#include <iostream>
#include <QString>
#include "booster.h"
#include "utils/settings.hpp"

Booster::Booster(std::string boostername_)
    {
    attrib.reserve(Settings::NUMBER_OF_ATTRIBUTES);
    for(int i=0; i<Settings::NUMBER_OF_ATTRIBUTES;i++){
        attrib[i]=0;
    }

    boostername=boostername_;
}

Booster::Booster(std::string boostername_, int boostTime_,std::vector<float> &attrib_):boostername{boostername_},boostTime{boostTime_}{
    attrib=attrib_;
}

/* Copy-constructor */
Booster::Booster(const Booster &boo){
    boostername=boo.boostername;
    boostTime=boo.boostTime;
    attrib=boo.attrib;
}
/* Copy assignment operator */
Booster& Booster::operator =(const Booster &boo){
    if(&boo == this)return *this;

    boostername=boo.boostername;
    boostTime=boo.boostTime;
    attrib=boo.attrib;

    return *this;
}

std::string Booster::toStr(){
    std::string output=boostername;
    if(attrib[Settings::HUNGER]!=0)
        output+=" Hunger: "+ QString::number(attrib[Settings::HUNGER]).toStdString();
    if(attrib[Settings::SLEEP]!=0)
        output+=" Sleep: "+ QString::number(attrib[Settings::SLEEP]).toStdString();
    if(attrib[Settings::INSPIRATION]!=0)
        output+=" Inspiration: "+ QString::number(attrib[Settings::INSPIRATION]).toStdString();
    output+=" Timeleft: "+QString::number(boostTime).toStdString();
    return output;
}

int Booster::getBoostTime(){
    return boostTime;
}
std::string Booster::getTitle(){
    return boostername;
}
/** Oppdater tiden */
int Booster::decreaseBoostTime(int t_){
    boostTime-=t_;
    return boostTime;
}

void Booster::setAttrib(Settings::Attributes attr, float val){
        attrib[attr]=val;
}

std::vector<float> Booster::getAttribs(){
    return attrib;
}

/** getMetoder */
float Booster::getHungerVal(){
    return attrib[Settings::HUNGER];
}
float Booster::getSleepVal(){
    return attrib[Settings::SLEEP];
}
float Booster::getInspirationVal(){
    return attrib[Settings::INSPIRATION];
}
void Booster::setDuration(int boostTime_){
    boostTime=boostTime_;
}
void Booster::setHunger(float hunger_){
    attrib[Settings::HUNGER]=hunger_;
}
void Booster::setSleep(float sleep_){
    attrib[Settings::SLEEP]=sleep_;
}
void Booster::setInspiration(float inspiration_){
    attrib[Settings::INSPIRATION]=inspiration_;
}
void Booster::reset(){}

Booster::~Booster(){}
