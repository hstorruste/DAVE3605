#ifndef WRITER_H
#define WRITER_H
#include <vector>
#include <list>
#include <string>

#include "book.h"

class Writer
{
    std::string name;
    float hunger;
    float inspiration;
    float sleep;
    int money;
    Book* current_book;
    bool writing;
    const float MAXVAL=110;
    const float MINVAL=-10;
public:
    Writer();
    Writer(std::string name_);
    Writer(std::string name_,
           float hunger_,
           float inspiration_,
           float sleep_,
           int money_,
           Book *c_book);
    Writer( const Writer &wrt ); // copy constructor
    Writer& operator = ( const Writer &wrt ); // copy assignment operator
    Writer( Writer &&wrt ); // move constructor
    Writer& operator =(Writer &&wrt); // move assignment operator*/
    void setHunger(float hunger_);
    void setInspiration(float inspiration_);
    void setSleep(float sleep_);
    void updateHunger(float hunger_);
    void updateInspiration(float inspiration_);
    void updateSleep(float sleep_);
    void setMoney(int money_);
    bool ifWriting() const;
    void isWriting();
    void isNotWriting();
    float getHunger() const;
    float getInspiration() const;
    float getSleep() const;
    int getMoney() const;
    const std::string& getName() const;
    std::string toStr();
    Book * getBook() const;
    void addBook();
    void addBook(std::string bookName);
    bool hasBook();
    void resetBook();
    ~Writer();
};

#endif // WRITER_H
