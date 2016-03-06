#ifndef ABSTRACTEVENT
#define ABSTRACTEVENT

#include <string>

class AbstractEvent
{

public:

    /** Executes the event */
    virtual void execute()=0;

    virtual ~AbstractEvent(){};

    virtual bool hasMessage(){return false;};

    virtual std::string getMessage(){return "";};


    //TODO Lage en BookEvent som setter inn ord i boka. Dvs mister ord: negative verdier, eller får en ord boost: positive verdier.
};

#endif // ABSTRACTEVENT

