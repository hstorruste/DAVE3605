#include <QDomElement>
#include <QDebug>
#include <iostream>
#include <sstream>

#include <vector>

#include "weatherreport.hpp"
#include "utils/filbehandler.hpp"
#include "utils/namespaces.hpp"

using namespace weather;

WeatherReport* WeatherReport::_instance = 0;

WeatherReport* WeatherReport::Instance()
{
    if(_instance == 0){
        _instance = new WeatherReport;
    }
    return _instance;
}

WeatherReport::WeatherReport()
{
    // henter værmelding for  Pilestredet 46, 0167 Oslo
    url_ = "http://www.yr.no/sted/Norge/postnummer/0167/varsel.xml";
    // navnet på filen som skal lagres med værdata
    filename_ = "report.xml";
    //last ned været
    downloadXmlReport();
}

std::vector<int> WeatherReport::getWeatherReportPlease()
{
    /*fyller vektor dersom den er tom*/
    if(weatherDataList.empty()) readReport();
    return weatherDataList;
}


/*
 * henter værdata fra listen og returnerer
 * verdi som stemmer overenns med hva været kan
 * være 'in game'
 */
int WeatherReport::getWeatherAtTime(int interval)
{
    /*fyller vektor dersom den er tom*/
    if(weatherDataList.empty()) readReport();

    if((unsigned long)interval>weatherDataList.size())
        interval = interval % weatherDataList.size();

    /*sjekker om det er natt*/
    if( interval % 4 == 0 ) return inGameWeather::night;

    int dataNodeValue = weatherDataList[interval];

    int type{0};

    switch (dataNodeValue) {
    case weatherReport::sol :
    case weatherReport::lettskyet :
    case weatherReport::lettesluddbyger :
        type = inGameWeather::sunny;
        break;

    case weatherReport::delvisskyet :
    case weatherReport::skyet :
    case weatherReport::letteregnbyger :
    case weatherReport::regnbyger :
    case weatherReport::kraftigeregnbyger :
    case weatherReport::letteregnbygerogtorden :
    case weatherReport::regnbygerogtorden :
    case weatherReport::kraftigeregnbygerogtorden :
    case weatherReport::sluddbyger :
    case weatherReport::kraftigesluddbyger :
    case weatherReport::lettesluddbygerogtorden :
    case weatherReport::sluddbygerogtorden :
    case weatherReport::kraftigesluddbygerogtorden :
    case weatherReport::lettesnobyger :
    case weatherReport::snobyger :
    case weatherReport::kraftigesnobyger :
    case weatherReport::lettesnobygerogtorden :
    case weatherReport::snobygerogtorden :
    case weatherReport::kraftigesnobygerogtorden :
    case weatherReport::toke :
        type = inGameWeather::cloudy;
        break;
    case weatherReport::regn :
    case weatherReport::kraftigregn :
    case weatherReport::lettregnogtorden :
    case weatherReport::regnogtorden :
    case weatherReport::kraftigregnogtroden :
    case weatherReport::lettsludd :
    case weatherReport::kraftigsludd :
    case weatherReport::lettsluddogtorden :
    case weatherReport::kraftigsluddogtorde :
    case weatherReport::lettsno :
    case weatherReport::sno :
    case weatherReport::kraftigsno :
    case weatherReport::lettsnoogtoden :
    case weatherReport::snoogtoden :
    case weatherReport::kraftigsnoogtorden :
        type = inGameWeather::raining;
        break;
    default:
        type = raining;
    }
    return type;
}

std::string WeatherReport::getWeatherReportToString()
{

    std::stringstream result;
    std::copy(weatherDataList.begin(), weatherDataList.end(), std::ostream_iterator<int>(result, " "));
    return "[ " + result.str()  + " ]";
}

/*leser værdata fra dokumentet som er lastet den og lagrer i weatherDataList*/
void WeatherReport::readReport()
{
    try{

        QDomDocument doc = getDocumentRoot();

        if( doc.isNull() ) {
            throw QString("Kunne ikke henter værtdata " + filename_
                   + "\n genererer tilfeldig data");
        }

        QDomElement weatherData_ = doc.namedItem("weatherdata").toElement();

        if( weatherData_.isNull() ) {
            throw QString("Inget weatherdata element funnet øverst i " + filename_
                   + "\n genererer tilfeldig data");
        }

        QDomElement forecast_ = weatherData_.namedItem("forecast").toElement();
        QDomElement tabular_ = forecast_.namedItem("tabular").toElement();

        if(forecast_.isNull() || tabular_.isNull() ){
            throw QString( "Ingen værdata funnet i " + filename_
                   + "\n returnerer tilfeldig data");
        }

        /*
        *  værmeldingen har en <symbol> tag for hver 6.time, med en ny
        *  oppdatering av været, som en numerisk verdi.
        *  Disse verdiene legges inn i listen weatherReportList
        */


        QDomElement time_node_ = tabular_.firstChildElement();
        /*fjerner eventuel tidligere generert data*/
        while(!time_node_.isNull()){

            QDomElement symbol_ = time_node_.namedItem("symbol").toElement();
            std::string str = symbol_.attribute("name").toStdString();
            int numberEx_ = symbol_.attribute("number").toInt();
            weatherDataList.push_back(numberEx_);
            time_node_ = time_node_.nextSiblingElement();
        }

    }catch(QString expt){
        qDebug() << expt;
        randoizeWeather();
    }

}

/*privat hjelpemetode for å få document root*/
QDomDocument WeatherReport::getDocumentRoot()
{
    QFile file_(filename_);
    QDomDocument doc;
    QString errorMsg;
    int errorLine, errorColumn;
    doc.setContent( &file_, &errorMsg, &errorLine, &errorColumn );
    return doc;
}

/*privat hjelpemetode for å generere tilfeldig vær*/
void WeatherReport::randoizeWeather()
{
    for(int i = 0; i < 10; i++)
        weatherDataList.push_back(rand()%1+weatherReport::kraftigsno);
}

/*henter dokumentet fra den gitte adressen i url_*/
void WeatherReport::downloadXmlReport()
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

          manager->get(QNetworkRequest(QUrl(url_)));
}


void WeatherReport::replyFinished(QNetworkReply *reply)
{


    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        /*
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        */

        QFile mFile(filename_);

        if(!mFile.open(QFile::WriteOnly | QFile::Text))
        {
            qDebug() << "Kunne ikke åpne fil for å skrive!";
            return;
        }

        QTextStream out(&mFile);
        out << reply->readAll();

        /* flusher stream og sørger for at
         * alt blir skrevet til disken
         */
        mFile.flush();
        mFile.close();
    }
    /* sørger for at reply blir slettet når den
     * ikke lenger er i bruk
     */
    reply->deleteLater();

    /*leser data inn i weatherDataList*/
    readReport();

}

WeatherReport::~WeatherReport()
{
    delete _instance;
}
