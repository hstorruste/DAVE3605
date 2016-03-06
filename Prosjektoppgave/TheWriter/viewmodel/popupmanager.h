#ifndef POPUPMANAGER_H
#define POPUPMANAGER_H

#include <QObject>

#include "model/writer.h"
#include "model/timecontroller.hpp"
#include "model/eventcontainer.h"
#include "model/booster.h"
#include "model/boostercontroller.hpp"
#include "view/inputpopup.h"
class PopUpManager : public QObject
{
    Q_OBJECT
public:
    explicit PopUpManager(QObject *parent, Writer& theWriter_, TimeController& m_time_,BoosterController& m_boosterC_);
    ~PopUpManager();

    /** Trigges når det skal lages en ny bok */
    void newBook();
    /** Trigges når boken er ferdig */
    void endBook();
    /** Trigges etter hver 7. dag */
    void rentIsDue();

private:
    Writer& theWriter;
    TimeController& m_time;
    int time_since_last_popup;
    int time_to_next_event;
    BoosterController& m_boosterC;
    const int MIN_TIME_TO_NEXT_EVENT=1800; //Halv time
    const int TIME_BETWEEN_EVENTS_SPAN_WIDTH=12600; // 3,5 timer
    const int NR_OF_FACTORIES=1;
    EventContainer *cont;
    InputPopUp *bokWin;


    void createRandomPopUp();
    void wireTime();
    void setTimeToNextEvent();

signals:

public slots:
private slots:
    void popUpChance();
    void acceptRecieved();
    void rejectRecieved();


    void startedBook();
};

#endif // POPUPMANAGER_H
