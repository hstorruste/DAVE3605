#include <iostream>
#include "statusviewmanager.h"
#include "model/writer.h"
#include "model/timecontroller.hpp"

StatusViewManager::StatusViewManager(QObject *parent, Writer& m_thewriter_, StatusView& m_statusview_, TimeController& m_time_,BoosterController& m_boosterC_) :
    QObject(parent),
    m_time(m_time_),
    m_thewriter(m_thewriter_),
    m_statusview(m_statusview_),
    m_boosterC(m_boosterC_)

{
    updatestatus();
    wireButtons();
}

// Oppdater gamedatastatusen utfra hva som skjer ellers i spillet
void StatusViewManager::updatestatus(){
    if(!m_boosterC.getEventBoosters().empty()){ // ligger det en eventbooster i boostercontroller sin eventkø?
        gamestatus=m_boosterC.getEventBoosters().front()->toStr();
    } else if(m_thewriter.getBook()){ // Skrives det en bok?
        gamestatus="Writing "+m_thewriter.getBook()->toStr();
    }else{ // Om ikke bør du starte på en bok
        gamestatus="You are not writing a book. Click the book pile to start a new book";
    }

    // Be statusView om å hente ny data og oppdatere data som vises!
    m_statusview.updateGUI(m_thewriter,m_time,gamestatus);
}


StatusViewManager::~StatusViewManager()
{}

// Koble singaler/knappeklikk med
void StatusViewManager::wireButtons()
{
    connect(&m_statusview, &StatusView::NotifySpeedPause,&m_time,&TimeController::onSpeedPause);
    connect(&m_statusview, &StatusView::NotifySpeedNormal,&m_time,&TimeController::onSpeedNormal);
    connect(&m_statusview, &StatusView::NotifySpeedFaster,&m_time,&TimeController::onSpeedFaster);
    connect(&m_statusview, &StatusView::NotifySpeedFastest,&m_time,&TimeController::onSpeedFastest);
}

