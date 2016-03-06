#include "writer.h"
#include "booster.h"

#include <vector>
#include <stdio.h> //NULL
#include <iostream>
/**
    Writer-klassen.
    Holder orden på forfatterens behov og progresjonen på hans bok
*/
Writer::Writer() :
    name{"Player#1"},
    hunger{100},
    inspiration{100},
    sleep{100},
    money{2000},
    current_book{nullptr},
    writing{false}
{}

Writer::Writer(std::string name_) :
    name{name_},
    hunger{100},
    inspiration{100},
    sleep{100},
    money{2000},
    current_book{nullptr},
    writing{false}
{}

Writer::Writer(std::string name_,
               float hunger_,
               float inspiration_,
               float sleep_,
               int money_,
               Book* c_book_):
    name{name_},
    hunger{hunger_},
    inspiration{inspiration_},
    sleep{sleep_},
    money{money_},
    current_book{c_book_}
{
    if(getBook()){
        writing =true;
    }
}

/*copy-constructor*/
Writer::Writer( const Writer &wrt )
{
    name=wrt.name;
    hunger=wrt.hunger;
    money=wrt.money;
    inspiration=wrt.inspiration;
    sleep=wrt.sleep;
    writing=wrt.writing;

    current_book = new Book(*wrt.current_book);
}

/*copy assignment operator*/

Writer& Writer::operator =(const Writer &wrt)
{
    if(&wrt == this) return *this;

    name=wrt.name;
    hunger=wrt.hunger;
    inspiration=wrt.inspiration;
    money=wrt.money;
    sleep=wrt.sleep;
    writing=wrt.writing;

    current_book = new Book(*wrt.current_book);

    return *this;
}

/*move constructor*/
Writer::Writer(Writer &&wrt) :
    name{""},
    hunger{0.0},
    inspiration{0.0},
    sleep{0.0},
    money{0},
    current_book{nullptr},
    writing{false}
{
    name = wrt.name;
    hunger = wrt.hunger;
    inspiration = wrt.hunger;
    money = wrt.money;
    sleep = wrt.sleep;
    writing = wrt.writing;

    current_book = new Book(*wrt.current_book);

    wrt.name = "";
    wrt.hunger = 0.0;
    wrt.inspiration = 0.0;
    wrt.money = 0;
    wrt.sleep = 0.0;
    wrt.writing = false;

    wrt.current_book = nullptr;
}

/*move assignment operator*/
Writer& Writer::operator =(Writer &&wrt) {

    if(this==&wrt) return *this;

    name="";
    hunger=0.0;
    inspiration=0.0;
    money=0;
    sleep=0.0;
    writing=false;

    current_book=nullptr;

    name = wrt.name;
    hunger = wrt.hunger;
    inspiration = wrt.hunger;
    money = wrt.money;
    sleep = wrt.sleep;
    writing = wrt.writing;

    current_book=wrt.current_book;

    wrt.name = "";
    wrt.hunger = 0.0;
    wrt.inspiration = 0.0;
    wrt.money = 0;
    wrt.sleep = 0.0;
    wrt.writing = false;

    wrt.current_book = nullptr;

    return *this;
}

Writer::~Writer(){
    delete current_book;
}



bool Writer::ifWriting() const
{
    return writing;
}

void Writer::isNotWriting()
{
    //if(getBook())
    writing = false;
}

void Writer::isWriting()
{
    if(getBook())
    writing = true;
}

/** Opprett bok */
void Writer::addBook(){
    if(!hasBook()){
        writing=true;
        current_book = new Book;
    }
}

void Writer::addBook(std::string bookName)
{
    if(!hasBook()){
        writing=true;
        current_book = new Book(bookName);
    }
}

bool Writer::hasBook()
{
    return nullptr != current_book;
}

void Writer::resetBook()
{
    writing=false;
    delete current_book;
    current_book=nullptr;
}

/** Update, set og get-metoder */
void Writer::updateHunger(float hunger_){
    if((hunger+hunger_)<=MINVAL){
        hunger=MINVAL;
//        emit Writer::HungerNone();
    } else if((hunger+hunger_)<=0){
        hunger+=hunger_;
//        emit Writer::HungerLow();
    } else if(hunger+hunger_>=MAXVAL){
        hunger=MAXVAL;
    } else{
        hunger+=hunger_;
    }
}

void Writer::updateInspiration(float inspiration_){
    if((inspiration+inspiration_)<=MINVAL){
        inspiration=MINVAL;
//        emit Writer::InspirationNone();
    } else if((inspiration+inspiration_)<=0){
        inspiration+=inspiration_;
//        emit Writer::InspirationLow();
    } else if(inspiration+inspiration_>=MAXVAL){
        inspiration=MAXVAL;
    } else{
        inspiration+=inspiration_;
    }
}
void Writer::updateSleep(float sleep_){
    if((sleep+sleep_)<=MINVAL){
        sleep=MINVAL;
//        emit Writer::SleepNone();
    } else if((sleep+sleep_)<=0){
        sleep+=sleep_;
//        emit Writer::SleepLow();
    } else if(sleep+sleep_>=MAXVAL){
        sleep=MAXVAL;
    } else{
        sleep+=sleep_;
    }
}
void Writer::setHunger(float hunger_){
    hunger=hunger_;
}
void Writer::setInspiration(float inspiration_){
    inspiration=inspiration_;
}
void Writer::setSleep(float sleep_){
    sleep=sleep_;
}
void Writer::setMoney(int money_){
    money=money_;
}
float Writer::getHunger() const{
    return hunger;
}
int Writer::getMoney() const{
    return money;
}
const std::string& Writer::getName() const
{
    return name;
}

std::string Writer::toStr()
{
    return name;
}
float Writer::getInspiration() const{
    return inspiration;
}
float Writer::getSleep() const{
    return sleep;
}
Book *Writer::getBook() const{
    return current_book;
}
