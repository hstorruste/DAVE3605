#include <iostream>
#include "boostercontroller.hpp"
#include "writer.h"
#include "book.h"
/**
    Denne klassen skal oppdatere needs utfra boostere og antall ord utfra needs.
    Dette er en klasse som burde vært delt opp i to (minst) klasser som f.eks. het NeedsUpdate og BookUpdate.
    Men nå er den slik den er, litt uoversiktlig og gjør litt vel mye.
*/

BoosterController::BoosterController(QObject *parent, Writer& theWriter_,TimeController& m_time_) :
                    QObject(parent),
                    theWriter(theWriter_),
                    m_time(m_time_),
                    eventboosters(*new std::list<Booster*>()),
                    environmentboosters(*new std::list<Booster*>()),
                    singleboosters(*new std::list<Booster*>())
{
    WireEvents();
}
void BoosterController::addEventBooster(Booster* eb){
    eventboosters.push_back(eb);
}

// Oppdater data (får tick fra MainViewController
void BoosterController::updateData(){
// Sett utgangsverdier

    int speedmulti=m_time.getSpeed()/60;
    float hungerval=-0.1666*speedmulti;
    float inspirationval=0;
    if(theWriter.ifWriting()){
        inspirationval=-0.07*speedmulti;
    }
    float sleepval=-0.1*speedmulti;
    int timeleft;
    int wordspermin = 10;
    int quality = 10;

// Oppdaterer needsval med eventbooster hvis det finnes. Det er kun den første som er gyldig
    if(!eventboosters.empty()){
        emit nonEmptyEvents(); //Gir beskjed om at Writer ikke skal skrive
        Booster *b= eventboosters.front();
        timeleft=b->getBoostTime();
        if(timeleft<=speedmulti){ // om tiden igjen av boosteren er mindre hastigheten
            hungerval+=b->getHungerVal()*timeleft;
            inspirationval+=b->getInspirationVal()*timeleft;
            sleepval+=b->getSleepVal()*timeleft;
            eventboosters.pop_front();
            delete b;
            if(eventboosters.empty()){ // om det ikke er flere boostere i køen
                emit emptyEvents(); //Gir beskjed om at Writer kan skrive igjen
            }
        } else{ // Vanlig flyt
            b->decreaseBoostTime(speedmulti); // Sett ned hastigheten på boosteren med et tick
            hungerval+=b->getHungerVal()*speedmulti;
            inspirationval+=b->getInspirationVal()*speedmulti;
            sleepval+=b->getSleepVal()*speedmulti;
        }
    }

// Oppdaterer needs med environmental boosters hvis de finnes.
    if(!environmentboosters.empty()){
        for(Booster* e : environmentboosters){
                hungerval+=e->getHungerVal()*speedmulti;
                inspirationval+=e->getInspirationVal()*speedmulti;
                sleepval+=e->getSleepVal()*speedmulti;
        }
    }
// Oppdaterer needs med alle singelboosters hvis de finnes
    while(!singleboosters.empty()){
        Booster *b=singleboosters.front();
        hungerval+=b->getHungerVal();
        inspirationval+=b->getInspirationVal();
        sleepval+=b->getSleepVal();
        singleboosters.pop_front();
        delete b;
    }
// Oppdater data i writer
    theWriter.updateHunger(hungerval);
    theWriter.updateSleep(sleepval);
    theWriter.updateInspiration(inspirationval);

// Oppdater antall ord i boka
    if(theWriter.ifWriting()){
        wordspermin=wordspermin*((theWriter.getHunger()+theWriter.getSleep())/200);
        quality=quality*(theWriter.getInspiration()/100);
        theWriter.getBook()->insertwords(wordspermin*speedmulti, quality);
        if(theWriter.getBook()->getPageGoal()<=theWriter.getBook()->getNumberOfPages())
            emit bookFinished();
    }

}
// Settere og gettere
std::list<Booster *> &BoosterController::getEnvironmentalBoosters()
{
    return environmentboosters;
}

std::list<Booster*>& BoosterController::getEventBoosters(){
    return eventboosters;
}

std::list<Booster*>& BoosterController::getSingleBoosters(){
    return singleboosters;
}

// Slutt på settere og gettere

BoosterController::~BoosterController()
{
    for(Booster *b : eventboosters)
        delete b;
    delete &eventboosters;
    for(Booster *b : environmentboosters)
        delete b;
    delete &environmentboosters;
    for(Booster *b : singleboosters)
        delete b;
    delete &singleboosters;
}

// Klikkevents
void BoosterController::onAppleClicked()
{
    Booster* apple=new Booster{"Eating an apple"};
    apple->setDuration(20);
    apple->setHunger(0.4);
    addEventBooster(apple);
}

void BoosterController::onCoffeeClicked()
{
    Booster* coffee=new Booster{"Makin coffee"};
    coffee->setDuration(20);
    coffee->setHunger(0.2);
    coffee->setSleep(0.4);
    addEventBooster(coffee);
}

void BoosterController::onWineClicked()
{
    Booster* wine=new Booster{"Drinking wine"};
    wine->setDuration(20);
    wine->setHunger(0.1);
    wine->setSleep(-0.2);
    wine->setInspiration(0.5);
    addEventBooster(wine);
}

// Her skulle sleep vært trigget
void BoosterController::onSofaClicked()
{

}

void BoosterController::onBooksClicked()
{
    theWriter.addBook();
}


// Slots
void BoosterController::continueWriting(){
    theWriter.isWriting();
}
void BoosterController::stopWriting(){
    theWriter.isNotWriting();
}
// Koble sammen signaler og evneter
void BoosterController::WireEvents(){
    connect(this,&BoosterController::emptyEvents,this, &BoosterController::continueWriting);
    connect(this,&BoosterController::nonEmptyEvents,this, &BoosterController::stopWriting);
}
// Vinduet i rommet, ikke grafiske vinduet
void BoosterController::onWindowClicked()
{
}



