#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include <viewmodel/mainviewmanager.hpp>
#include "view/mainview.h"
#include "view/statusview.hpp"
#include "view/studyview.hpp"
#include "model/timecontroller.hpp"
#include "viewmodel/statusviewmanager.h"
#include "viewmodel/popupmanager.h"
#include "viewmodel/studyview_manager.hpp"
#include "model/booster.h"
#include "model/boostercontroller.hpp"
#include "view/inputpopup.h"
#include "utils/weatherreport.hpp"

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(std::string playerName);
    explicit Startup(LoadGame& loadGame_);
    void show() const;
    ~Startup();
private:
    int speed;
    Writer& theWriter;
    TimeController& m_time;
    StatusView& m_statusView;
    BoosterController& m_boosterC;
    StatusViewManager& m_statusViewMgr;
    PopUpManager& m_popUpMgr;
    StudyView& m_studyView;
    StudyViewManager& m_studyViewMgr;
    MainView& m_mainView;
    MainViewManager& m_mainViewMgr;

    explicit Startup(const Startup& rhs)=delete;
    Startup& operator=(const Startup&rhs) = delete;


signals:

public slots:

};

#endif // STARTUP_H
