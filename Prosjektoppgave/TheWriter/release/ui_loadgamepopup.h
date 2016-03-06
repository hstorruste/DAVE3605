/********************************************************************************
** Form generated from reading UI file 'loadgamepopup.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADGAMEPOPUP_H
#define UI_LOADGAMEPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadGamePopUp
{
public:
    QPushButton *btnLoadGame;
    QListWidget *listLoadGames;
    QPushButton *btnNewGame;

    void setupUi(QWidget *LoadGamePopUp)
    {
        if (LoadGamePopUp->objectName().isEmpty())
            LoadGamePopUp->setObjectName(QStringLiteral("LoadGamePopUp"));
        LoadGamePopUp->resize(400, 300);
        btnLoadGame = new QPushButton(LoadGamePopUp);
        btnLoadGame->setObjectName(QStringLiteral("btnLoadGame"));
        btnLoadGame->setGeometry(QRect(50, 240, 115, 32));
        listLoadGames = new QListWidget(LoadGamePopUp);
        listLoadGames->setObjectName(QStringLiteral("listLoadGames"));
        listLoadGames->setGeometry(QRect(50, 30, 256, 192));
        listLoadGames->setSelectionBehavior(QAbstractItemView::SelectItems);
        btnNewGame = new QPushButton(LoadGamePopUp);
        btnNewGame->setObjectName(QStringLiteral("btnNewGame"));
        btnNewGame->setGeometry(QRect(180, 240, 115, 32));

        retranslateUi(LoadGamePopUp);

        QMetaObject::connectSlotsByName(LoadGamePopUp);
    } // setupUi

    void retranslateUi(QWidget *LoadGamePopUp)
    {
        LoadGamePopUp->setWindowTitle(QApplication::translate("LoadGamePopUp", "Form", 0));
        btnLoadGame->setText(QApplication::translate("LoadGamePopUp", "Load game", 0));
        btnNewGame->setText(QApplication::translate("LoadGamePopUp", "New Game", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadGamePopUp: public Ui_LoadGamePopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADGAMEPOPUP_H
