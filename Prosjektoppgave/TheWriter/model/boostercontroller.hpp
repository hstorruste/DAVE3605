#ifndef BOOSTERCONTROLLER_H
#define BOOSTERCONTROLLER_H

#include <QObject>
#include "booster.h"
#include "writer.h"
#include "timecontroller.hpp"

class BoosterController : public QObject
{
    Q_OBJECT

private:
    Writer& theWriter;
    TimeController& m_time;
    std::list<Booster*>&eventboosters;
    std::list<Booster*>&environmentboosters;
    std::list<Booster*>&singleboosters;
    void WireEvents();
public:
    void addEventBooster(Booster* eb);
    std::list<Booster*> &getEventBoosters();
    void updateData();
    std::list<Booster*> &getEnvironmentalBoosters();
    explicit BoosterController(QObject *parent, Writer& theWriter_,TimeController& m_time_);
    ~BoosterController();

    std::list<Booster *> &getSingleBoosters();
signals:
    void emptyEvents();
    void nonEmptyEvents();
    void bookFinished();
public slots:
    void onAppleClicked();
    void onCoffeeClicked();
    void onWindowClicked();
    void onWineClicked();
    void onSofaClicked();
    void onBooksClicked();
private slots:
    void continueWriting();
    void stopWriting();
};

#endif // BOOSTERCONTROLLER_H
