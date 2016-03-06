/*
 * xmlfilbehandler er implementert som en singleton
*/

#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <QString>
//#include <QXmlStreamReader>
#include <QDomElement>
#include <QTime>

#include "model/timecontroller.hpp"
#include "model/writer.h"
#include "model/boostercontroller.hpp"
#include <model/loadgame.h>

class XmlParser
{

public:
    static XmlParser* Instance();

    bool skrivObjektTilXML( const Writer &ws, TimeController &time,BoosterController &boost,std::string fname_ );
    LoadGame loadFile(const QString fileName);
    void append_to_xml( QDomDocument &domTree );
protected:
    XmlParser();
private:
    static XmlParser* _instance;

    /*hjelpemetode for klassen*/
    QDomElement addElement( QDomDocument &doc, QDomNode &node,
                            const QString &tag,
                            const QString &value = QString::null );
    QDomDocument getDocumentRoot(const QString filename_);
    ~XmlParser();
};

#endif // XMLFILBEHANDLER_H
