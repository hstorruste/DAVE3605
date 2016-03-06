#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTime>
#include <vector>
#include <QListWidget>
#include <QList>


#include "model/timecontroller.hpp"
#include "statusview.hpp"
#include "studyview.hpp"
#include "model/boostercontroller.hpp"
#include "viewmodel/statusviewmanager.h"
#include "viewmodel/studyview_manager.hpp"
#include "utils/xmlparser.hpp"

namespace Ui {
class MainView;
}

class MainView : public QMainWindow, public QCloseEvent
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent,
                      StatusView& m_statusview_,
                      StudyView& m_studyview_);
    ~MainView();




private:
    StatusView& m_statusView;
    StudyView& m_studyView;
    Ui::MainView *ui;
    void startUp();
public slots:
    /*overskriver close event for mainview*/
    void closeEvent(QCloseEvent*);
signals:
    void windowClosed();
};

#endif // MAINVIEW_H
