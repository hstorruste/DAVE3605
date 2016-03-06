#include "eventfactory.h"
#include "model/boostevent.h"
#include "model/moneyevent.h"

#include <string>


EventFactory::EventFactory(Writer &theWriter_, BoosterController &bContr_) :
    theWriter(theWriter_), bContr(bContr_)

{

}

EventFactory::~EventFactory()
{

}

EventContainer *EventFactory::create()
{
    /* Genererer en int fra 1 til NR_OF_EVENTS */
    int event_nr = rand() % NR_OF_EVENTS + 1;

    EventContainer *event;

    switch(event_nr){

    case 1:
        event = birdHitsWindow();
        break;

    case 2:
        event = pizzaDelivery();
        break;
    case 3:
        event=mumCalled();
        break;
    }
    return event;
}

EventContainer *EventFactory::birdHitsWindow(){

    std::string text = "A bird flies into your window and dies. Do you want to take time to bury it?";
    /** choice one */
    Booster *boost1 = new Booster("Burying bird");//Slows down the sleep and gain inspiration
    boost1->setAttrib(Settings::Attributes::SLEEP, 0.2);
    boost1->setAttrib(Settings::Attributes::INSPIRATION, 0.5);
    boost1->setDuration(30);
    BoostEvent *choice1 = new BoostEvent(boost1,bContr.getEventBoosters(),
                                                    "You bury the bird and gain some inspiration while getting some fresh air.");
    /** choice two */
    Booster *boost2 = new Booster("Bad conscience!"); // Short, but gives less inspiration.
    boost2->setAttrib(Settings::Attributes::INSPIRATION, -4);
    boost2->setDuration(5);
    BoostEvent *choice2 = new BoostEvent(boost2, bContr.getEventBoosters(), "You worry about bad carma and lose inspiration.");

    return new EventContainer(text,choice1,"Bury",choice2,"Don't care");
}

EventContainer *EventFactory::mumCalled(){

    std::string text = "Mum calls. \nDo you have time to talk to her?.";
    /** choice one */
    Booster *boost1 = new Booster("Mum called");
    boost1->setAttrib(Settings::Attributes::INSPIRATION, 0.1);
    boost1->setDuration(90);
    BoostEvent *choice1 = new BoostEvent(boost1,bContr.getEventBoosters(),
                                                    "You talk to mum for way too long, but got a break and inspiration.");

    /** choice two */
    Booster *boost2 = new Booster("Mum called");

    BoostEvent *choice2 = new BoostEvent(boost2, bContr.getSingleBoosters(),
                                         "Alright toughguy.\nShe might call you back. Maybe.");

    EventContainer *cont = new EventContainer(text,choice1,"Yes",choice2,"No time for love, Dr. Jones");
    return cont;
}



EventContainer *EventFactory::pizzaDelivery(){

    std::string text = "A pizza delivery guy, shows up on your door with a pizza.He has obvious the wrong address. \nDo you pay for the pizza or tell him it's the wrong address?.";
    /** choice one */
    Booster *boost1 = new Booster("Eating pizza");
    boost1->setAttrib(Settings::Attributes::HUNGER, 1);
    boost1->setDuration(40);
    BoostEvent *choice1 = new BoostEvent(boost1,bContr.getEventBoosters(),
                                                    "You enjoy the tasty pizza.");
    MoneyEvent *additionalChoice1 = new MoneyEvent(theWriter, -15);

    /** choice two */
    Booster *boost2 = new Booster("The neighbor's pizza");
    boost2->setAttrib(Settings::Attributes::INSPIRATION, 10);
    BoostEvent *choice2 = new BoostEvent(boost2, bContr.getSingleBoosters(),
                                         "The neighbor comes running, and are happy to receive her pizza.\nYou have a clean conscience and gain inspiration.");

    EventContainer *cont = new EventContainer(text,choice1,"Pay",choice2,"Be honest");
    cont->addAdditionalFirstEvent(additionalChoice1);
    return cont;
}

