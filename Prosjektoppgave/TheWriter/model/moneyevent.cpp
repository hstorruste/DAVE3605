#include "moneyevent.h"

MoneyEvent::MoneyEvent(Writer &theWriter_, int amount_) :
    theWriter(theWriter_)
{
amount=amount_;
}

MoneyEvent::~MoneyEvent()
{

}

void MoneyEvent::execute()
{
    theWriter.setMoney(theWriter.getMoney()+amount);
}
