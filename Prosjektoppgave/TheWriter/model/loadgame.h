#ifndef LOADGAME_H
#define LOADGAME_H

#include "writer.h"
#include "utils/namespaces.hpp"

struct TimeStruct{
    int days=0;
    int hours=0;
    int minutes=0;
    int seconds=0;
};

class LoadGame
{
    Writer* tempWriter;
    TimeStruct tempTimes;
public:
    LoadGame();
    explicit LoadGame(Writer* tempWriter_, int days_, int hours_,int minutes_,int seconds_);
    TimeStruct getTimes();
    Writer* getWriter();
    std::string toStr();
    ~LoadGame();
};



#endif // LOADGAME_H
