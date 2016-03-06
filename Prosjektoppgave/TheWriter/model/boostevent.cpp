#include "boostevent.h"

BoostEvent::BoostEvent(Booster *b, std::list<Booster*> &queue_, std::string message_) :
    boost_{b}, queue(queue_), message{message_}, containsMessage{true}
{

}

BoostEvent::BoostEvent(Booster *b, std::list<Booster*> &queue_) :
    boost_{b}, queue(queue_), containsMessage{false}
{

}

BoostEvent::~BoostEvent()
{
    delete boost_;
}

void BoostEvent::execute()
{
    queue.push_front(boost_);
    boost_=nullptr;
}

bool BoostEvent::hasMessage()
{
    return containsMessage;
}

std::string BoostEvent::getMessage()
{
    return message;
}
