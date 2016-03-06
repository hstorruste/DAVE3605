/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QWidget *centralWidget;
    QTextBrowser *txtBoosters;
    QPushButton *btnMakeCoffee;
    QPushButton *btnEatSandwich;
    QPushButton *lblLagBok;
    QListView *listBooster;
    QLabel *lblTime;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(870, 613);
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        txtBoosters = new QTextBrowser(centralWidget);
        txtBoosters->setObjectName(QStringLiteral("txtBoosters"));
        txtBoosters->setGeometry(QRect(710, 70, 141, 291));
        btnMakeCoffee = new QPushButton(centralWidget);
        btnMakeCoffee->setObjectName(QStringLiteral("btnMakeCoffee"));
        btnMakeCoffee->setGeometry(QRect(420, 320, 75, 23));
        btnEatSandwich = new QPushButton(centralWidget);
        btnEatSandwich->setObjectName(QStringLiteral("btnEatSandwich"));
        btnEatSandwich->setGeometry(QRect(420, 280, 75, 23));
        lblLagBok = new QPushButton(centralWidget);
        lblLagBok->setObjectName(QStringLiteral("lblLagBok"));
        lblLagBok->setGeometry(QRect(280, 170, 75, 23));
        listBooster = new QListView(centralWidget);
        listBooster->setObjectName(QStringLiteral("listBooster"));
        listBooster->setGeometry(QRect(420, 40, 256, 192));
        lblTime = new QLabel(centralWidget);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        lblTime->setGeometry(QRect(370, 210, 47, 13));
        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 22));
        MainView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainView);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainView->setStatusBar(statusBar);

        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "MainView", 0));
        btnMakeCoffee->setText(QApplication::translate("MainView", "Make coffee", 0));
        btnEatSandwich->setText(QApplication::translate("MainView", "Eat sandwich", 0));
        lblLagBok->setText(QApplication::translate("MainView", "Lag bok", 0));
        lblTime->setText(QApplication::translate("MainView", "Her er tiden", 0));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
