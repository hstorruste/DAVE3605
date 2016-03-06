#ifndef BOOSTEVENTFACTORY_H
#define BOOSTEVENTFACTORY_H

#include <list>
#include "abstracteventfactory.h"
#include "booster.h"
#include "eventcontainer.h"
#include "boostercontroller.hpp"
#include "writer.h"

/** This class is a factory for events that will push (to the front) a booster into the writers booster-queue.
 * Each type of event has its own private function that will be called by the create-function randomly.
 * The number of different events is stored in the NR_OF_EVENTS variable.(This is used in the randomization.)*/

class EventFactory : public AbstractEventFactory
{

    Writer &theWriter;
    BoosterController &bContr;
    const int NR_OF_EVENTS=3;
public:
    EventFactory(Writer &theWriter_, BoosterController &bContr_);

    ~EventFactory();

    EventContainer *create() override;
private:
    /** Events */
    EventContainer *birdHitsWindow();
    EventContainer *pizzaDelivery();
    EventContainer *mumCalled();
};

#endif // BOOSTEVENTFACTORY_H
