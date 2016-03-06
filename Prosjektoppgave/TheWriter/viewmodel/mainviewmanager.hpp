#ifndef MAINVIEWMANAGER_H
#define MAINVIEWMANAGER_H

#include <QObject>


#include "model/boostercontroller.hpp"
#include "statusviewmanager.h"
#include "studyview_manager.hpp"
#include "utils/xmlparser.hpp"
#include "view/mainview.h"
#include "popupmanager.h"
class MainViewManager : public QObject
{
    Q_OBJECT
public:
    explicit MainViewManager(QObject *parent,
                             StatusView& m_statusView_,
                             StatusViewManager& m_statusViewMgr_,
                             StudyView& m_studyview_,
                             StudyViewManager& m_studyView_manager_,
                             Writer& theWriter_,
                             TimeController& m_time_,
                             BoosterController& m_boosterC_,
                             MainView& m_mainView_,
                             PopUpManager& m_popUp_manager_);
    ~MainViewManager();
private:
    XmlParser* xmlp;
    TimeController& m_time;
    StatusView& m_statusView;
    StatusViewManager& m_statusViewMgr;
    StudyView& m_studyView;
    StudyViewManager& m_studyViewMgr;
    Writer& theWriter;
    BoosterController& m_boosterC;
    MainView& m_mainView;
    PopUpManager& m_popUpMgr;
    void startUp();
    void updateGUI();
    void updateData();
signals:

public slots:

private slots:
    void minuteUpdate();
    void hourUpdate();
    void dayUpdate();
    void weekUpdate();
    void sixhourintervalUpdate();
    void endBook();
    void endGame();
    void lagbok();
    void saveToFile();
};

#endif // MAINVIEWMANAGER_H
