#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H

#include <QObject>
#include <QTime>
#include <QTimer>
class TimeController : public QObject
{
    Q_OBJECT
private:
    int speed;
    int days;
    int weeks;
    QTimer *timer;
    QTime myTimer;
public:
    explicit TimeController(QObject *parent = 0);
    explicit TimeController(QObject *parent,int days_, int hours_,int minutes_,int seconds_);
    void onSpeedPause();
    void onSpeedNormal();
    void onSpeedFaster();
    void onSpeedFastest();
    int getDays();
    int getHours();
    int getMinutes();
    int getSeconds();
    int getSpeed();
    QTime getTimer();
    ~TimeController();

signals:
    void timeTicked();
    void hourTicked();
    void dayTicked();
    void weekTicked();
    void sixhourTicked();
    void endGame();
private slots:
    void timeUpdate();
public slots:
    void addTime(int t);
};

#endif // TIMECONTROLLER_H
