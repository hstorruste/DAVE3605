#ifndef MONEYEVENT_H
#define MONEYEVENT_H

#include "abstractevent.h"
#include "writer.h"

class MoneyEvent : public AbstractEvent
{

public:
    MoneyEvent(Writer &theWriter_, int amount_);
    ~MoneyEvent();
    void execute() override;

private:
    Writer &theWriter;
    int amount;
};

#endif // MONEYEVENT_H
