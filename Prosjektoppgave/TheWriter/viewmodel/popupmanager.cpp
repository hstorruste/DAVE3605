#include "popupmanager.h"
#include "model/abstracteventfactory.h"
#include "model/eventfactory.h"
#include "model/boostercontroller.hpp"
#include "model/moneyevent.h"
#include "view/dialogpopup.h"
#include "view/messagepopup.h"
#include "view/popup.h"
#include <sstream>

PopUpManager::PopUpManager(QObject *parent, Writer &theWriter_, TimeController &m_time_, BoosterController& m_boosterC_) :
    QObject(parent),
    theWriter(theWriter_),
    m_time(m_time_),
    time_since_last_popup{0},
    time_to_next_event{0},
    m_boosterC(m_boosterC_),
    cont(nullptr)
{
    wireTime();
}

PopUpManager::~PopUpManager()
{

}

void PopUpManager::wireTime()
{
    connect(&m_time, &TimeController::timeTicked, this, &PopUpManager::popUpChance);
}

/** Calls createPopUp if time_to_next_event <= time_since_last_event */
void PopUpManager::popUpChance()
{
    /*Sjekker om det er første gang denne kjøres*/
    if(time_to_next_event == 0)
           setTimeToNextEvent();

    time_since_last_popup+=m_time.getSpeed();

    if(time_to_next_event <= time_since_last_popup)
    {
        setTimeToNextEvent();
        time_since_last_popup=0;
        createRandomPopUp();
    }
}

void PopUpManager::setTimeToNextEvent()
{
    /* Setter time_to_next_event til et tall mellom MIN_TIME_TO_NEXT_EVENT
     *  og TIME_BETWEEN_EVENTS_SPAN_WIDTH + MIN_TIME_TO_NEXT_EVENT */
    time_to_next_event = rand() % TIME_BETWEEN_EVENTS_SPAN_WIDTH + MIN_TIME_TO_NEXT_EVENT;
}

void PopUpManager::createRandomPopUp()
{
    AbstractEventFactory *factory;

    /* Genererer en int mellom 1 og NR_OF_FACTORIES */
    int result= rand() % NR_OF_FACTORIES + 1;

    switch(result){

        case 1:
        factory=new EventFactory(theWriter,m_boosterC);
        break;
    }

    cont=factory->create();

    DialogPopUp *eventWin=new DialogPopUp(nullptr,cont->getString().c_str(),
                         cont->getAcceptText().c_str(),
                         cont->getDeclineText().c_str());

    connect(eventWin, SIGNAL(NotifyAcceptClicked()), this, SLOT(acceptRecieved()));
    connect(eventWin, SIGNAL(NotifyDeclineClicked()), this, SLOT(rejectRecieved()));

    Qt::WindowFlags flags = eventWin->windowFlags();
    flags = flags | Qt::FramelessWindowHint;
    eventWin->setWindowFlags(flags);

    int res = eventWin->exec();
    if(res == 1)
        rejectRecieved();

    delete factory;
}

void PopUpManager::acceptRecieved()
{
    std::vector<AbstractEvent*> *events=cont->getEventOne();
    /* Sjekker om eventen trigger nye popUps*/
    for( auto e : *events)
        if(e->hasMessage()){
            PopUp *eventWin = new MessagePopUp(nullptr, QString::fromUtf8(e->getMessage().c_str()));
            Qt::WindowFlags flags = eventWin->windowFlags();
            flags = flags | Qt::FramelessWindowHint;
            eventWin->setWindowFlags(flags);

            eventWin->exec();
        }

    cont->executeFirst();
    delete cont;
}

void PopUpManager::rejectRecieved()
{
    std::vector<AbstractEvent*> *events=cont->getEventTwo();
    /* Sjekker om eventen trigger nye popUps*/
    for( auto e : *events)
        if(e->hasMessage()){
            PopUp *eventWin = new MessagePopUp(nullptr, QString::fromUtf8(e->getMessage().c_str()));
            Qt::WindowFlags flags = eventWin->windowFlags();
            flags = flags | Qt::FramelessWindowHint;
            eventWin->setWindowFlags(flags);

            eventWin->exec();
        }

    cont->executeSecond();
    delete cont;
}

void PopUpManager::rentIsDue()
{
    PopUp *rentWin = new DialogPopUp(nullptr,"Rent is due! \n100$ \nDo you want to pay?", "Pay", "Don't pay");
    Qt::WindowFlags flags = rentWin->windowFlags();
    flags = flags | Qt::FramelessWindowHint;
    rentWin->setWindowFlags(flags);
    cont = new EventContainer(new MoneyEvent(theWriter, -100),new MoneyEvent(theWriter,0));

    connect(rentWin, SIGNAL(NotifyAcceptClicked()), this, SLOT(acceptRecieved()));
    connect(rentWin, SIGNAL(NotifyDeclineClicked()), this, SLOT(rejectRecieved()));


    int res = rentWin->exec();
    if(res == 1)
        rejectRecieved();

}

void PopUpManager::newBook()
{
    bokWin = new InputPopUp(nullptr, "What do you want to call your book?","Start writing");
    Qt::WindowFlags flags = bokWin->windowFlags();
    flags = flags | Qt::FramelessWindowHint;
    bokWin->setWindowFlags(flags);

    connect(bokWin,SIGNAL(NotifySubmitClicked()),this,SLOT(startedBook()));

    bokWin->exec();
}

void PopUpManager::endBook()
{
    std::ostringstream bookstat;
    bookstat << "Congratulation!\n";
    bookstat << theWriter.getBook()->getName() << " is completed.\n";
    bookstat << "You wrote " << theWriter.getBook()->getNumberOfPages() << " pages.\n";
    bookstat << "With a quality of " << theWriter.getBook()->getQuality() << " out of 10.";
    MessagePopUp *endbookWin = new MessagePopUp(nullptr, QString::fromUtf8(bookstat.str().c_str()), "Good bye!");

    endbookWin->exec();

}

void PopUpManager::startedBook()
{
    std::string bookTitle = bokWin->getInput();

    theWriter.addBook(bookTitle);
}

