#include <QFile>
#include <QDebug>
#include <iostream>
#include <QDir>
#include "initstart.h"
#include "view/dialogpopup.h"
#include "utils/xmlparser.hpp"

/**
    Initstart har som oppgave å vise et vindu hvor man gjør valget, nytt spill eller loade et savegame.
*/

InitStart::InitStart(QObject *parent) : QObject(parent), loadGameWin(nullptr), newGameWin(nullptr), w(nullptr)
{
}

InitStart::~InitStart()
{
    delete w;
}

void InitStart::start()
{
    DialogPopUp *startWin = new DialogPopUp(nullptr,"Do you want to start a new game?","New game", "Load game");
    startWin->setWindowTitle("The Writer");

    connect(startWin, SIGNAL(NotifyAcceptClicked()), this, SLOT(newGame()));
    connect(startWin, SIGNAL(NotifyDeclineClicked()), this, SLOT(loadFiles()));

    startWin->show();
}

void InitStart::newGame()
{

    newGameWin = new InputPopUp(nullptr, "Enter your name:", "Submit name");
    newGameWin->setWindowTitle("The Writer");

    connect(newGameWin, SIGNAL(NotifySubmitClicked()),this, SLOT(initNewGame()) );

    newGameWin->show();
}

void InitStart::initNewGame(){
    std::string playerName=newGameWin->getInput();

    w = new Startup(playerName);
    w->show();
}

void InitStart::loadFiles()
{

    QDir dir;
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Time);
    dir.setNameFilters(QStringList()<<"*.sav");

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
    }

    loadGameWin = new LoadGamePopUp(nullptr,list);
    loadGameWin->setWindowTitle("The Writer");
    connect(loadGameWin, SIGNAL(NotifyLoadClicked()),this,SLOT(loadGame()));
    connect(loadGameWin, SIGNAL(NotifyNewGameClicked()),this,SLOT(newGame()));
    loadGameWin->show();
}
void InitStart::loadGame(){

    XmlParser* parser=XmlParser::Instance();
    LoadGame myWriter;
    myWriter = parser->loadFile(loadGameWin->getLoadedGame());
    w=new Startup(myWriter);
    w->show();
}
