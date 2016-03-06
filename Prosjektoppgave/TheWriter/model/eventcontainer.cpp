#include "eventcontainer.h"

EventContainer::EventContainer(std::string text_, AbstractEvent *first_, std::string accept_btn,
                               AbstractEvent *second_, std::string decline_btn) :
    text{text_},
    accept{accept_btn},
    decline{decline_btn}
{
    first= new std::vector<AbstractEvent*>();
    second=new std::vector<AbstractEvent*>();
    first->push_back(first_);
    second->push_back(second_);

}

EventContainer::EventContainer(AbstractEvent *first_, AbstractEvent *second_):
    text{""}, accept{""}, decline{""}
{
    first= new std::vector<AbstractEvent*>();
    second=new std::vector<AbstractEvent*>();
    first->push_back(first_);
    second->push_back(second_);

}

void EventContainer::addAdditionalFirstEvent(AbstractEvent *additional){
    first->push_back(additional);
}

void EventContainer::addAdditionalSecondEvent(AbstractEvent *additional){
    second->push_back(additional);
}

EventContainer::~EventContainer()
{
    for(auto *a : *first)
        delete a;
    delete first;

    for(auto *a : *second)
        delete a;
    delete second;
}

void EventContainer::executeFirst()
{
    while(!first->empty()){
        AbstractEvent *f = first->back();
        f->execute();
        first->pop_back();
    }
}

void EventContainer::executeSecond()
{
    while(!second->empty()){
        AbstractEvent *s = second->back();
        s->execute();
        second->pop_back();
    }
}

std::string EventContainer::getString()
{
    return text;
}

std::string EventContainer::getAcceptText()
{
    return accept;
}

std::string EventContainer::getDeclineText()
{
    return decline;
}

std::vector<AbstractEvent *> *EventContainer::getEventOne()
{
    return first;
}

std::vector<AbstractEvent *> *EventContainer::getEventTwo()
{
    return second;
}

