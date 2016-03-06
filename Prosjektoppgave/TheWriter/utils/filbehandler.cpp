
/*
 * filbehandler er implementert som en singleton.
 * Det skal altså være mulig å ha kunn en instanse av klassen
 * WriteText og ReadText leser filer som tekts
 */

//local
#include "filbehandler.hpp"

//not local
#include <QDataStream>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <string>
#include <iostream>
#include <QDebug>


Filbehandler* Filbehandler::_instance = 0;

Filbehandler* Filbehandler::Instance ()
{
    if(_instance == 0){
        _instance = new Filbehandler;
    }
    return _instance;
}

/*
 * metoden tar imot en QString som inneholder xml syntaks
 * som lagres til fil tilsvarende parameter verdien
 * Filename
*/

void Filbehandler::writeText(QString Filename, const QString str)
{
    QFile mFile(Filename);
    if(!mFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Kunne ikke åpne fil for å skrive!";
        return;
    }

    QTextStream out(&mFile);
    out << str;

    // flusher stream og sørger for at
    // alt blir skrevet til disken
    mFile.flush();
    mFile.close();
}

QString Filbehandler::readText(QString Filename)
{

    QFile mFile(Filename);
    if(!mFile.open(QIODevice::ReadOnly | QFile::Text))
    {
        qDebug() << "Kunne ikke åpne fil for å lese!";
        return "";
    }

    QTextStream in (&mFile);
    QString mText = in.readAll();


    mFile.close();

    return mText;

}

Filbehandler::Filbehandler() {}
Filbehandler::~Filbehandler() {
    delete _instance;
}
