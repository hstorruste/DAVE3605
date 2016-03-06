#include <QTimer>
#include <iostream>
#include <list>
#include <stdio.h>
#include <QDebug>

#include "mainview.h"
#include "ui_mainview.h"



MainView::MainView(QWidget *parent,
                   StatusView& m_statusView_,
                   StudyView& m_studyview_):

                   QMainWindow(parent),
                   m_statusView(m_statusView_),
                   m_studyView(m_studyview_),
                   ui(new Ui::MainView)
{
    ui->setupUi(this);
// Add statusview og studyview to mainview
    m_statusView.setParent(this);
    m_studyView.setParent(this);
    setWindowTitle("The Writer");
}

MainView::~MainView(){
    delete ui;
}
void MainView::closeEvent(QCloseEvent*)
{
    emit windowClosed();
}

