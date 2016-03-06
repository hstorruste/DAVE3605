#include "timecontroller.hpp"
#include <iostream>
#include <QTime>

/**
    Holder orden på tiden. Oppdateres hvert sekund/tidsenhet, også kalt tick.
    Om spillet ikke er på pause så oppdateres tiden i spillet også i henhold til speed.
    Og sender ut signal til MainViewManager at det er gått en tidsenhet/tick.
*/

// Konstruktør ved new game, myTimer er klokken som vises i spillet og starter på 06:00.
TimeController::TimeController(QObject *parent) : QObject(parent),myTimer(6,0,0)
{

    // Oppstartsverdier
    days=1;
    weeks=1;
    speed=60; // Hvor mange spillsekunder hvert tick

    // Tidskontroller
    timer = new QTimer(this);
    // Koble signalet timeout mot sloten timeupdate
    connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));

    // Start timer
    timer->start(1000);
}

// Konstruktør for å hente inn savegame
TimeController::TimeController(QObject *parent,int days_, int hours_,int minutes_,int seconds_) : QObject(parent),days(days_),myTimer(hours_,minutes_,seconds_)
{
    // Oppstartsverdier
    weeks=days/7;
    speed=60; // Hvor mange spillsekunder hvert tick

    // Tidskontroller
    timer = new QTimer(this);

    // Koble signal mot slot. Tikk mot funksjoner
    connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));

    // Start timer
    timer->start(1000);
}

// Speedendringer, hvor mange spillminutter per tick
void TimeController::onSpeedPause(){
    speed=0;
}
void TimeController::onSpeedNormal(){
    speed=60;
}
void TimeController::onSpeedFaster(){
    speed=180;
}
void TimeController::onSpeedFastest(){
    speed=300;
}

// Get metoder for speed
int TimeController::getSpeed(){
    return speed;
}
int TimeController::getDays(){
    return days;
}
int TimeController::getHours(){
    return myTimer.hour();
}
int TimeController::getMinutes(){
    return myTimer.minute();
}
int TimeController::getSeconds(){
    return myTimer.second();
}
QTime TimeController::getTimer(){
    return myTimer;
}
void TimeController::addTime(int t){
    myTimer.addSecs(t);
}

//Time update
void TimeController::timeUpdate(){
    // Har det klokken tippet over en time siden forrige tick?
    if(myTimer.hour()<myTimer.addSecs(speed).hour()){
        emit hourTicked();
    }

    // Væroppdatering hver 6. time
    if(myTimer.hour()%6==0){
        emit sixhourTicked();
    }

    // Dagsoppdatering
    if(myTimer.addSecs(speed) < myTimer){
        emit dayTicked();
        emit hourTicked();
        days++;
        if(days%7==0){ // Har det gått en uke?
            weeks++;
            emit weekTicked();
        }
    }
    myTimer=myTimer.addSecs(speed); // legg speed til myTimer
    emit timeTicked(); // fortell at en tidsenhet/et tick har gått
    if(days>100){ // EndGame ved 100 dager, men det er ikke implementert
        emit endGame();
    }
}
TimeController::~TimeController()
{
    delete timer;
}

