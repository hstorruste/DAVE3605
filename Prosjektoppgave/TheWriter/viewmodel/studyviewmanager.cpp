#include "studyview_manager.hpp"


StudyViewManager::StudyViewManager(QObject *parent,
                                     Writer& m_thewriter_,
                                     StudyView& m_studyview_,
                                     BoosterController& m_boostC_) :
  QObject(parent),
  m_thewriter(m_thewriter_),
  m_studyview(m_studyview_),
  m_boostC(m_boostC_)
{
    WireButtons();
    u_weatherReport = WeatherReport::Instance();
}


StudyViewManager::~StudyViewManager()
{

}
void StudyViewManager::animateWriter(){

    if(m_thewriter.ifWriting()){
        m_studyview.AnimWrite();
    }

    m_studyview.AnimView();
    m_studyview.AnimSuperSecretEasterEgg();
}

void StudyViewManager::changeWeather(int day, int hour)
{
    /*et interval tilsvarer 6 timer*/
    int interval = (day * 4) + (hour/6);
    int type = u_weatherReport->getWeatherAtTime(interval);
    m_studyview.changeWeather(type);
}


void StudyViewManager::WireButtons()
{
    connect(&m_studyview, &StudyView::NotifyAppleClicked,&m_boostC,&BoosterController::onAppleClicked);
    connect(&m_studyview, &StudyView::NotifyCoffeeClicked,&m_boostC,&BoosterController::onCoffeeClicked);
    connect(&m_studyview, &StudyView::NotifyWineClicked,&m_boostC,&BoosterController::onWineClicked);
    connect(&m_studyview, &StudyView::NotifySofaClicked,&m_boostC,&BoosterController::onSofaClicked);
    //connect(&m_studyview, &StudyView::NotifyBooksClicked,&m_boostC,&BoosterController::onBooksClicked);
}
