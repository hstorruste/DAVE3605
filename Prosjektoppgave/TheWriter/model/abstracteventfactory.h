#ifndef ABSTRACTEVENTFACTORY
#define ABSTRACTEVENTFACTORY

#include "eventcontainer.h"
class AbstractEventFactory
{
public:
    virtual EventContainer *create()=0;
    virtual ~AbstractEventFactory(){};
};

#endif // ABSTRACTEVENTFACTORY

