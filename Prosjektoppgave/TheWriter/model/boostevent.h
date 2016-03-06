#ifndef BOOSTEVENT_H
#define BOOSTEVENT_H

#include "abstractevent.h"
#include "booster.h"
#include <list>

/** This contains a booster and a pointer to the queue
 *  wich it will get pushed into if it gets executed*/

class BoostEvent : public AbstractEvent
{

public:
    BoostEvent(Booster *b, std::list<Booster *> &queue_, std::string message_);
    ~BoostEvent() override;

    void execute() override;

    BoostEvent(Booster *b, std::list<Booster *> &queue_);
    bool hasMessage() override;
    std::string getMessage() override;
private:
    Booster *boost_;
    std::list<Booster*>& queue;
    std::string message;
    bool containsMessage;
};

#endif // BOOSTEVENT_H
