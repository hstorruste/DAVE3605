
/*
 * filbehandler er implementert som en singleton.
 * Det skal altså være mulig å ha kunn en instanse av klassen
 * WriteText og ReadText leser filer som tekts
 */

#ifndef FILBEHANDLER_HPP
#define FILBEHANDLER_HPP

#include <QString>

class Filbehandler{

public:
    static Filbehandler* Instance();
     void writeText(QString Filename, const QString str);
     QString readText(QString Filename);


protected:
    Filbehandler();

private:
    static Filbehandler* _instance;
    ~Filbehandler();

};

#endif
