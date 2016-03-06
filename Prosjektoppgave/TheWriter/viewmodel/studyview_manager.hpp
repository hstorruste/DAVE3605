#ifndef STUDYVIEW_MANAGER_H
#define STUDYVIEW_MANAGER_H

#include <QObject>
#include "model/writer.h"
#include "view/studyview.hpp"
#include "model/boostercontroller.hpp"
#include "utils/weatherreport.hpp"
class StudyViewManager : public QObject
{
    Q_OBJECT
private:
    Writer& m_thewriter;
    StudyView& m_studyview;
    BoosterController& m_boostC;
    WeatherReport* u_weatherReport;
    void WireButtons();
public:
    explicit StudyViewManager(QObject *parent,
                               Writer& m_thewriter_,
                               StudyView& m_studyview,
                               BoosterController& m_boostC_);
    ~StudyViewManager();

signals:

public slots:
    void animateWriter();
    void changeWeather(int day, int hour);
};

#endif // STUDYVIEW_MANAGER_H
