#ifndef EVENTCONTAINER
#define EVENTCONTAINER

#include <string>
#include "abstractevent.h"
#include <vector>

class EventContainer
{
    std::string text;
    std::vector<AbstractEvent*> *first;
    std::string accept;
    std::vector<AbstractEvent*> *second;
    std::string decline;

public:
    EventContainer(std::string text, AbstractEvent *first_, std::string accept_btn,
                   AbstractEvent *second_, std::string decline_btn);
    EventContainer(AbstractEvent *first_, AbstractEvent *second_);
    virtual ~EventContainer();
    virtual void executeFirst();
    virtual void executeSecond();
    std::string getString();
    std::string getAcceptText();
    std::string getDeclineText();
    std::vector<AbstractEvent*>* getEventOne();
    std::vector<AbstractEvent*>* getEventTwo();

    void addAdditionalFirstEvent(AbstractEvent *additional);
    void addAdditionalSecondEvent(AbstractEvent *additional);
};


#endif // EVENTCONTAINER

