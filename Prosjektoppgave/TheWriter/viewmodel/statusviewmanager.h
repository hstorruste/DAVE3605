#ifndef STATUSVIEWMANAGER_H
#define STATUSVIEWMANAGER_H

#include <QObject>
#include "model/writer.h"
#include "view/statusview.hpp"
#include "model/timecontroller.hpp"
#include "model/boostercontroller.hpp"
class StatusViewManager : public QObject
{
    Q_OBJECT
public:
    explicit StatusViewManager(QObject *parent,
                               Writer& m_thewriter_,
                               StatusView& m_statusview_,
                               TimeController& m_time_,
                               BoosterController& m_boosterC_);
    ~StatusViewManager();
private:
    TimeController& m_time;
    Writer& m_thewriter;
    StatusView& m_statusview;
    BoosterController& m_boosterC;
    std::string gamestatus;
    void wireButtons();
public slots:
    void updatestatus();
};

#endif // STATUSVIEWMANAGER_H
