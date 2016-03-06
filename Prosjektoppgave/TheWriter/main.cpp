#include <QApplication>
#include "initstart.h"

#include "utils/weatherreport.hpp"
/**
 * Oppstartsklasse. Her starter all moroa og den starter initstart
*/
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InitStart init;
    init.start();

    return a.exec();
}

