#-------------------------------------------------
#
# Project created by QtCreator 2015-04-17T13:18:34
#
#-------------------------------------------------

QT       += core gui xml network


QMAKE_CXXFLAGS += -std=c++11 -Wall


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheWriter
TEMPLATE = app

CONFIG   -= app_bundle #Legger filer på utsiden av den eksekverbare filen

RESOURCES += \
    resource.qrc

    

HEADERS += \
    model/abstractevent.h \
    model/abstracteventfactory.h \
    model/book.h \
    model/booster.h \
    model/boostevent.h \
    model/eventcontainer.h \
    model/timecontroller.hpp \
    model/writer.h \
    utils/filbehandler.hpp \
    view/clicklabel.hpp \
    view/mainview.h \
    view/messagepopup.h \
    view/optionlabel.hpp \
    view/popup.h \
    view/scalelabel.hpp \
    view/statusview.hpp \
    view/dialogpopup.h \
    viewmodel/popupmanager.h \
    viewmodel/statusviewmanager.h \
    viewmodel/studyview_manager.hpp \
    utils/settings.hpp \
    startup.h \
    model/boostercontroller.hpp \
    model/moneyevent.h \
    model/eventfactory.h \
    utils/weatherreport.hpp \
    view/inputpopup.h \
    viewmodel/mainviewmanager.hpp \
    initstart.h \
    utils/namespaces.hpp \
    model/loadgame.h \
    view/loadgamepopup.h \
    view/studyview.hpp \
    utils/namespaces.hpp \
    utils/xmlparser.hpp

SOURCES += \
    model/book.cpp \
    model/booster.cpp \
    model/boostevent.cpp \
    model/eventcontainer.cpp \
    model/timecontroller.cpp \
    model/writer.cpp \
    utils/filbehandler.cpp \
    view/clicklabel.cpp \
    view/mainview.cpp \
    view/messagepopup.cpp \
    view/optionlabel.cpp \
    view/popup.cpp \
    view/scalelabel.cpp \
    view/statusview.cpp \
    view/dialogpopup.cpp \
    viewmodel/popupmanager.cpp \
    viewmodel/statusviewmanager.cpp \
    main.cpp \
    startup.cpp \
    model/boostercontroller.cpp \
    model/moneyevent.cpp \
    model/eventfactory.cpp \
    utils/weatherreport.cpp \
    view/inputpopup.cpp \
    viewmodel/mainviewmanager.cpp \
    initstart.cpp \
    model/loadgame.cpp \
    view/loadgamepopup.cpp \
    view/studyview.cpp \
    viewmodel/studyviewmanager.cpp \
    utils/xmlparser.cpp

FORMS += \
    view/mainview.ui \
    view/popup.ui \
    view/studyview.ui \
    view/messagepopup.ui \
    view/statusview.ui \
    view/dialogpopup.ui \
    view/inputpopup.ui \
    view/loadgamepopup.ui
