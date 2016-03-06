#include <QCloseEvent>
#include "mainviewmanager.hpp"

/**
  Denne klassen har som funksjon å knytte sammen alt. Den mottar signaler fra timecontroller, signalene plukkes opp i slots som så sender beksjed til managere/controllere om at nå er et tick gått.
*/
MainViewManager::MainViewManager(QObject *parent,
                                StatusView& m_statusView_,
                                StatusViewManager& m_statusViewMgr_,
                                StudyView& m_studyview_,
                                StudyViewManager& m_studyView_manager_,
                                Writer& theWriter_,
                                TimeController& m_time_,
                                BoosterController& m_boosterC_,
                                MainView& m_mainView_,
                                PopUpManager& m_popUp_manager_)
                            :   QObject(parent),
                                m_time(m_time_),
                                m_statusView(m_statusView_),
                                m_statusViewMgr(m_statusViewMgr_),
                                m_studyView(m_studyview_),
                                m_studyViewMgr(m_studyView_manager_),
                                theWriter(theWriter_),
                                m_boosterC(m_boosterC_),
                                m_mainView(m_mainView_),
                                m_popUpMgr(m_popUp_manager_)
{
    xmlp = XmlParser::Instance();
    startUp();
}

MainViewManager::~MainViewManager()
{
}
// Koble sammen ticks, clicks og lukkinger med modeller og metoder
void MainViewManager::startUp(){
    connect(&m_time, &TimeController::timeTicked,this,&MainViewManager::minuteUpdate);
    connect(&m_time, &TimeController::hourTicked, this,&MainViewManager::hourUpdate);
    connect(&m_time, &TimeController::dayTicked, this,&MainViewManager::dayUpdate);
    connect(&m_time, &TimeController::weekTicked, this,&MainViewManager::weekUpdate);
    connect(&m_time, &TimeController::sixhourTicked, this,&MainViewManager::sixhourintervalUpdate);
    connect(&m_time, &TimeController::endGame, this,&MainViewManager::endGame);
    connect(&m_mainView,&MainView::windowClosed, this, &MainViewManager::saveToFile);
    connect(&m_studyView, &StudyView::NotifyBooksClicked, this,&MainViewManager::lagbok);
    connect(&m_boosterC, &BoosterController::bookFinished, this, &MainViewManager::endBook);
    sixhourintervalUpdate();
}

// Opprett ny bok
void MainViewManager::lagbok(){

    if(theWriter.hasBook())
        return;

    m_popUpMgr.newBook();
}

// Tidsoppdateringsklasser
void MainViewManager::minuteUpdate(){
    updateData();
    updateGUI();
    m_studyViewMgr.animateWriter();
}
void MainViewManager::hourUpdate(){
    xmlp->skrivObjektTilXML(theWriter, m_time,m_boosterC, "auto");
    if(theWriter.getBook())
        theWriter.getBook()->resetHour();
}
void MainViewManager::saveToFile(){
    xmlp->skrivObjektTilXML(theWriter, m_time,m_boosterC, "quit");
}

void MainViewManager::dayUpdate()
{

}
void MainViewManager::weekUpdate()
{
    m_popUpMgr.rentIsDue();
}
// Sekstimersoppdatering, knyttet til væroppdateringer
void MainViewManager::sixhourintervalUpdate()
{
    int day = m_time.getDays() - 1;
    int hour = m_time.getHours();
    m_studyViewMgr.changeWeather(day, hour);

}
// Tidsoppdateringsklasser slutt


// Ikke blitt implementert 
void MainViewManager::endGame()
{

}
// Avslutt boken
void MainViewManager::endBook()
{
    m_popUpMgr.endBook();
    m_mainView.closeEvent(nullptr);
    theWriter.resetBook();
}

// Gi beskjed om å oppdatere data
void MainViewManager::updateData(){
    m_boosterC.updateData();
}

// Gi beskjed om å oppdatere GUI
void MainViewManager::updateGUI(){
    m_statusViewMgr.updatestatus();
}
