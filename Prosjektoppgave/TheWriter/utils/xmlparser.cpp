/*
 *Klassen xml_parser er implementert som singleton
 */

#include <QString>
#include <iostream>
#include <QDebug>
#include <QFile>

//Local
#include "utils/xmlparser.hpp"
#include "utils/filbehandler.hpp"



XmlParser* XmlParser::_instance = 0;

XmlParser* XmlParser::Instance() {

    if(_instance==0){

        XmlParser::_instance = new XmlParser;
    }
    return _instance;
}


/*
 * Hjelpefunskjon som genererer et DOM-element for gitt DOM-dokument
 * og legger det til child-elementene til den gitte noden
 */
QDomElement XmlParser::addElement( QDomDocument &doc, QDomNode &node,
                                         const QString &tag,
                                         const QString &value )
{
    QDomElement el = doc.createElement( tag );
    node.appendChild( el );
    if ( !value.isNull() ) {
        QDomText txt = doc.createTextNode( value );
        el.appendChild( txt );
    }
    return el;
}



bool XmlParser::skrivObjektTilXML( const Writer &wtr,
                                   TimeController &time,
                                   BoosterController &boost,
                                   std::string fname_ )
{
    QDateTime currentT = QDateTime::currentDateTime();
    Filbehandler * fil_behandler = Filbehandler::Instance();
    QString format(".sav");
    QString fname(currentT.toString("ddMMyy")+"-"+QString::fromStdString(fname_)+" - " + QString::fromStdString(wtr.getName()));
    QString filename(fname+format);
    QDomDocument doc;
    QDomProcessingInstruction instr = doc.createProcessingInstruction(
                "xml", "version='1.0' encoding='UTF-8'");
    doc.appendChild(instr);
    QDomElement gameSetElement= addElement(doc,doc, "game");

    // generer 'writer' tag som root, legger til 'atributt' spiller
    QDomElement writerSetElement = addElement( doc, gameSetElement, "writer" );
    writerSetElement.setAttribute( "spiller", QString::fromStdString(wtr.getName()) );

    // Legg til <hunger>, <sleep>, <inspiration>, <money>, <writing>
    // <inspiration>, <hunger> og <sleep> er barn av <need>
    addElement( doc, writerSetElement, "money", QString::number( wtr.getMoney() ) );
    addElement( doc, writerSetElement, "writing", QString::number( wtr.ifWriting() ) );

    QDomElement need = addElement( doc, writerSetElement, "need");
    addElement( doc, need, "hunger", QString::number(wtr.getHunger()));
    addElement( doc, need, "sleep", QString::number(wtr.getSleep()));
    addElement( doc, need, "inspiration", QString::number(wtr.getInspiration()));
    // Legg til boosters
    if(!boost.getEventBoosters().empty()){
        QDomElement boosterSetElement = addElement(doc,gameSetElement, "boosters");
        for( auto b : (boost.getEventBoosters())){
            QDomElement boosterValueSetElement=addElement(doc,boosterSetElement,"booster");
            addElement( doc, boosterValueSetElement, "title", QString::fromStdString(b->getTitle()));
            addElement( doc, boosterValueSetElement, "hunger", QString::number(b->getHungerVal()));
            addElement( doc, boosterValueSetElement, "inspiration", QString::number(b->getInspirationVal()));
            addElement( doc, boosterValueSetElement, "sleep", QString::number(b->getSleepVal()));
            addElement( doc, boosterValueSetElement, "boosttime", QString::number(b->getBoostTime()));
        }
    }
    QDomElement timeelement = addElement( doc, gameSetElement, "time");
    addElement( doc, timeelement, "days", QString::number(time.getDays()));
    addElement( doc, timeelement, "hours", QString::number(time.getHours()));
    addElement( doc, timeelement, "minutes", QString::number(time.getMinutes()));
    addElement( doc, timeelement, "seconds", QString::number(time.getSeconds()));


    if(!wtr.getBook()){
        fil_behandler->writeText(filename, doc.toString());
        return true;
    }

    //Legger til boken som forfatteren skriver for øyeblikket
    QDomElement current_book = addElement(doc, writerSetElement, "current_book");
    current_book.setAttribute( "book_title", QString::fromStdString(wtr.getBook()->getName()));
    current_book.setAttribute( "book_length", QString::number(wtr.getBook()->getPageGoal()));
    QDomElement wordsThisHour_vector = addElement( doc, current_book, "wordsThisHour_vector" );

    for( auto i : *(wtr.getBook()->getWordsThisHour())){
        addElement( doc, wordsThisHour_vector, "quality", QString::number(i));
    }

    QDomElement totalWords_vector = addElement( doc, current_book, "totalWords_vector" );

    for( auto i : *(wtr.getBook()->getWordsWritten())){
        addElement( doc, totalWords_vector, "quality", QString::number(i));
    }

    fil_behandler->writeText(filename, doc.toString());

    return true;
}

QDomDocument XmlParser::getDocumentRoot(const QString fileName_){

    Filbehandler* loadFile = Filbehandler::Instance();
    QString gameData = loadFile->readText(fileName_);
    QDomDocument domTree;
    QFile file(fileName_);
    QString errorMsg;
    int errorLine, errorColumn;
    domTree.setContent (&file, &errorMsg,&errorLine,&errorColumn);
    return domTree;
}

LoadGame XmlParser::loadFile(const QString fileName)
{ 
    LoadGame loadGame_;
    QDomDocument domTree = getDocumentRoot(fileName);
    if(domTree.isNull()){
        return loadGame_;
    }

// Default values for player and book
    std::string player_name{"Player#1"};
    float sleep{0.0};
    float hunger{0.0};
    float inspiration{0.0};
    int money{0};
    bool writing{false};
    std::string book_title{"ghost town"};
    int book_length{0};
    std::vector<int> wordsThisHour;
    std::vector<int> totalWordsWritten;

    int days=0;
    int hours=0;
    int minutes=0;
    int seconds=0;
    QDomElement game=domTree.namedItem("game").toElement();
    QDomElement writer_ = game.namedItem("writer").toElement();

    if ( game.isNull() ) {
        qWarning() << "No <writer> element found at the top-level "
                   << "of the XML file!";

//        return wrt; // returnerer writer med initialverdier
    }

    if ( writer_.hasAttribute("spiller") ) {
        player_name = writer_.attribute("spiller").toStdString();
    }

    QDomElement writing_ = writer_.namedItem("writing").toElement();
    if( !writing_.isNull()) writing = writing_.text().toInt();

    QDomElement money_ = writer_.namedItem("money").toElement();
    if( !money_.isNull()) money = money_.text().toInt();

    QDomElement need_ = writer_.namedItem("need").toElement();

    if(!need_.isNull()){
        QDomElement sleep_ = need_.namedItem("sleep").toElement();
        if( !sleep_.isNull()) sleep = sleep_.text().toFloat();

        QDomElement hunger_ = need_.namedItem("hunger").toElement();
        if( !hunger_.isNull()) hunger = hunger_.text().toFloat();

        QDomElement inspiration_ = need_.namedItem("inspiration").toElement();
        if( !inspiration_.isNull()) inspiration = inspiration_.text().toFloat();
    }

    QDomElement book_ = writer_.namedItem("current_book").toElement();

    if (!book_.isNull()){
        if( book_.hasAttribute("book_title") ) {
            book_title = book_.attribute("book_title").toStdString();
        }

        if( book_.hasAttribute("book_length") ) {
            book_length = book_.attribute("book_length").toInt();
        }
    } else {
        qWarning() << "No <book> element found in the xml" ;
    }
    QDomElement wordsThisHour_vector_ = book_.namedItem("wordsThisHour_vector").toElement();
    QDomNodeList nodes = wordsThisHour_vector_.elementsByTagName("quality");

    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            wordsThisHour.push_back(e.text().toInt());
        }
    }

    QDomElement totalWords_vector_ = book_.namedItem("totalWords_vector").toElement();
    QDomNodeList nodes_total = totalWords_vector_.elementsByTagName("quality");

    for(int i = 0; i < nodes_total.count(); i++)
    {
        QDomNode elm = nodes_total.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            totalWordsWritten.push_back(e.text().toInt());
        }
    }
    QDomElement time_= game.namedItem("time").toElement();

    QDomElement days_= time_.namedItem("days").toElement();
    if( !days_.isNull()) days = days_.text().toInt();
    QDomElement hours_= time_.namedItem("hours").toElement();
    if( !hours_.isNull()) hours = hours_.text().toInt();

    QDomElement minutes_= time_.namedItem("minutes").toElement();
    if( !minutes_.isNull()) minutes = minutes_.text().toInt();

    QDomElement seconds_= time_.namedItem("seconds").toElement();
    if( !seconds_.isNull()) seconds = seconds_.text().toInt();

    if(book_.isNull()){
        return LoadGame(new Writer(player_name,
                  hunger,
                  inspiration,
                  sleep,
                  money,
                  nullptr),days,hours,minutes,seconds);
    }else {
        return LoadGame(new Writer(player_name,
                  hunger,
                  inspiration,
                  sleep,
                  money,
                  new Book(book_title,
                           book_length,
                           wordsThisHour,
                           totalWordsWritten)),days,hours,minutes,seconds);
    }
}

XmlParser::XmlParser(){}
XmlParser::~XmlParser(){
    delete _instance;
}
