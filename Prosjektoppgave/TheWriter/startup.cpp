#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "startup.h"

/**
    Henter inn data fra loadgame eller navnet på forfatter som skal brukes i spillet og initierer klassenene som trengs for å spille spillet.
    Denne klassen er populært kalt "ballongmannen". Han som fyller alle nødvendige klasser med luft, holder de så de ikke flyr avgårde, og gir slipp når tiden er ute
    Trigger mainview som holder studyview og statusview.
    MainViewManager er neste steg.
*/

// Konstruktør for new game
Startup::Startup(std::string playerName) :
    QObject(nullptr),
    theWriter(*new Writer(playerName)),
    m_time(*new TimeController(nullptr)),
    m_statusView(*new StatusView(nullptr)),
    m_boosterC(*new BoosterController(nullptr,theWriter,m_time)),
    m_statusViewMgr(*new StatusViewManager(nullptr, theWriter,
                                           m_statusView,
                                           m_time,m_boosterC)),
    m_popUpMgr(*new PopUpManager(nullptr,
                                 theWriter,
                                 m_time,m_boosterC)),
    m_studyView(*new StudyView(nullptr)),
    m_studyViewMgr(*new StudyViewManager( nullptr,
                                           theWriter,
                                           m_studyView,
                                           m_boosterC)),
    m_mainView(*new MainView(nullptr,
                             m_statusView,
                             m_studyView)),
    m_mainViewMgr(*new MainViewManager(nullptr,
                                       m_statusView,
                                       m_statusViewMgr,
                                       m_studyView,
                                       m_studyViewMgr,
                                       theWriter,
                                       m_time,
                                       m_boosterC,
                                       m_mainView,
                                       m_popUpMgr))
{
    srand(time(NULL));
}


// Konstruktør for å load game
Startup::Startup(LoadGame& loadGame_) :
    QObject(nullptr),
    theWriter(*loadGame_.getWriter()),
    m_time(* new TimeController(nullptr,loadGame_.getTimes().days,loadGame_.getTimes().hours, loadGame_.getTimes().minutes,loadGame_.getTimes().seconds)),
    m_statusView(*new StatusView(nullptr)),
    m_boosterC(*new BoosterController(nullptr,theWriter,m_time)),
    m_statusViewMgr(*new StatusViewManager(nullptr, theWriter,
                                           m_statusView,
                                           m_time,m_boosterC)),
    m_popUpMgr(*new PopUpManager(nullptr,
                                 theWriter,
                                 m_time,m_boosterC)),
    m_studyView(*new StudyView(nullptr)),
    m_studyViewMgr(*new StudyViewManager( nullptr,
                                           theWriter,
                                           m_studyView,
                                           m_boosterC)),
    m_mainView(*new MainView(nullptr,
                             m_statusView,
                             m_studyView)),
    m_mainViewMgr(*new MainViewManager(nullptr,
                                       m_statusView,
                                       m_statusViewMgr,
                                       m_studyView,
                                       m_studyViewMgr,
                                       theWriter,
                                       m_time,
                                       m_boosterC,
                                       m_mainView,
                                       m_popUpMgr))
{
    srand(time(NULL));
}

void Startup::show() const
{
    m_mainView.show();
}

Startup::~Startup()
{
    delete &theWriter;
    delete &m_time;
    delete &m_statusView;
    delete &m_boosterC;
    delete &m_statusViewMgr;
    delete &m_popUpMgr;
    delete &m_studyView;
    delete &m_studyViewMgr;
    delete &m_mainView;
    delete &m_mainViewMgr;

}
