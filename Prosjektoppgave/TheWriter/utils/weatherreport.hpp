/*
 * Dennne klassen henter værdata fra yr.no i form av xml
 * og bruker denne informasjonen til å påvirke spillet
 * værmeldingen deles inn i bolker på 6 timer av gangen
 * enum weather_report definerer navn på du ulike typene
 * vær som kan forekomme i xml dokumentet.
 *
 * klassen er implementert som singleton
 *
 */

#ifndef WEATHERREPORT_H
#define WEATHERREPORT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <vector>
#include <QDomDocument>

class WeatherReport : public QObject
{
    Q_OBJECT

private:
    static WeatherReport* _instance;
    QNetworkAccessManager *manager;
    QString url_;
    QString filename_;
    std::vector<int> weatherDataList;

    /*henter xml fra nettet dersom det er mulig*/
    void downloadXmlReport();

    /*leser xml fil og lagrer data om været til watherData List*/
    void readReport();

    /*hjelpemetode som returnerer dokument root*/
    QDomDocument getDocumentRoot();

    /* dersom det kastes en exception ved lesing av værdata
     * returnerers tilfeldig data*/
    void randoizeWeather();

    ~WeatherReport();

protected:
    WeatherReport();

public:
    static WeatherReport* Instance();
    std::vector<int> getWeatherReportPlease();
    int getWeatherAtTime(int interval);
    std::string getWeatherReportToString();

public slots:
    void replyFinished (QNetworkReply *reply);
};

#endif // WEATHERREPORT_H
