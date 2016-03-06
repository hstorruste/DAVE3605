/********************************************************************************
** Form generated from reading UI file 'statusview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSVIEW_H
#define UI_STATUSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "view/clicklabel.hpp"

QT_BEGIN_NAMESPACE

class Ui_StatusView
{
public:
    QGroupBox *gpNeeds;
    QWidget *layoutWidget;
    QVBoxLayout *loNeedsLbl;
    QLabel *lblHunger;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *loNeedsSld;
    QProgressBar *prgrHunger;
    QProgressBar *prgrInspiration;
    QProgressBar *prgrSleep;
    QWidget *layoutWidget_3;
    QVBoxLayout *loNeedsMP;
    QLabel *lblHungerMul;
    QLabel *lblInspMul;
    QLabel *lblSleepMul;
    QLabel *lblStatus;
    QGroupBox *grpTime;
    QLabel *lblSpeed;
    QLabel *lblDays;
    QLabel *lblTime;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout;
    ClickLabel *clk_lb_pause;
    ClickLabel *clk_lb_play;
    ClickLabel *clk_lb_faster;
    ClickLabel *clk_lb_fastest;
    QLabel *lblPages;
    QLabel *lblBookQuality;
    QLabel *lblMoney;
    QProgressBar *prgrBook;
    QLabel *label;
    QLabel *label_4;
    QLabel *lblBookPrgrg;

    void setupUi(QWidget *StatusView)
    {
        if (StatusView->objectName().isEmpty())
            StatusView->setObjectName(QStringLiteral("StatusView"));
        StatusView->resize(867, 345);
        gpNeeds = new QGroupBox(StatusView);
        gpNeeds->setObjectName(QStringLiteral("gpNeeds"));
        gpNeeds->setGeometry(QRect(0, 30, 341, 121));
        layoutWidget = new QWidget(gpNeeds);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(145, 20, 100, 91));
        loNeedsLbl = new QVBoxLayout(layoutWidget);
        loNeedsLbl->setObjectName(QStringLiteral("loNeedsLbl"));
        loNeedsLbl->setContentsMargins(0, 0, 0, 0);
        lblHunger = new QLabel(layoutWidget);
        lblHunger->setObjectName(QStringLiteral("lblHunger"));

        loNeedsLbl->addWidget(lblHunger);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        loNeedsLbl->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        loNeedsLbl->addWidget(label_3);

        layoutWidget_2 = new QWidget(gpNeeds);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 131, 92));
        loNeedsSld = new QVBoxLayout(layoutWidget_2);
        loNeedsSld->setObjectName(QStringLiteral("loNeedsSld"));
        loNeedsSld->setContentsMargins(0, 0, 0, 0);
        prgrHunger = new QProgressBar(layoutWidget_2);
        prgrHunger->setObjectName(QStringLiteral("prgrHunger"));
        prgrHunger->setValue(24);

        loNeedsSld->addWidget(prgrHunger);

        prgrInspiration = new QProgressBar(layoutWidget_2);
        prgrInspiration->setObjectName(QStringLiteral("prgrInspiration"));
        prgrInspiration->setValue(24);

        loNeedsSld->addWidget(prgrInspiration);

        prgrSleep = new QProgressBar(layoutWidget_2);
        prgrSleep->setObjectName(QStringLiteral("prgrSleep"));
        prgrSleep->setValue(24);

        loNeedsSld->addWidget(prgrSleep);

        layoutWidget_3 = new QWidget(gpNeeds);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(250, 20, 81, 81));
        loNeedsMP = new QVBoxLayout(layoutWidget_3);
        loNeedsMP->setObjectName(QStringLiteral("loNeedsMP"));
        loNeedsMP->setContentsMargins(0, 0, 0, 0);
        lblHungerMul = new QLabel(layoutWidget_3);
        lblHungerMul->setObjectName(QStringLiteral("lblHungerMul"));

        loNeedsMP->addWidget(lblHungerMul);

        lblInspMul = new QLabel(layoutWidget_3);
        lblInspMul->setObjectName(QStringLiteral("lblInspMul"));

        loNeedsMP->addWidget(lblInspMul);

        lblSleepMul = new QLabel(layoutWidget_3);
        lblSleepMul->setObjectName(QStringLiteral("lblSleepMul"));

        loNeedsMP->addWidget(lblSleepMul);

        lblStatus = new QLabel(StatusView);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));
        lblStatus->setGeometry(QRect(10, 10, 751, 16));
        grpTime = new QGroupBox(StatusView);
        grpTime->setObjectName(QStringLiteral("grpTime"));
        grpTime->setGeometry(QRect(350, 30, 441, 121));
        lblSpeed = new QLabel(grpTime);
        lblSpeed->setObjectName(QStringLiteral("lblSpeed"));
        lblSpeed->setGeometry(QRect(120, 20, 131, 16));
        lblDays = new QLabel(grpTime);
        lblDays->setObjectName(QStringLiteral("lblDays"));
        lblDays->setGeometry(QRect(10, 20, 47, 13));
        lblTime = new QLabel(grpTime);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        lblTime->setGeometry(QRect(70, 20, 41, 16));
        layoutWidget_5 = new QWidget(grpTime);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 40, 533, 103));
        horizontalLayout = new QHBoxLayout(layoutWidget_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        clk_lb_pause = new ClickLabel(layoutWidget_5);
        clk_lb_pause->setObjectName(QStringLiteral("clk_lb_pause"));
        clk_lb_pause->setCursor(QCursor(Qt::PointingHandCursor));
        clk_lb_pause->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/pause.png")));

        horizontalLayout->addWidget(clk_lb_pause);

        clk_lb_play = new ClickLabel(layoutWidget_5);
        clk_lb_play->setObjectName(QStringLiteral("clk_lb_play"));
        clk_lb_play->setCursor(QCursor(Qt::PointingHandCursor));
        clk_lb_play->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/play.png")));

        horizontalLayout->addWidget(clk_lb_play);

        clk_lb_faster = new ClickLabel(layoutWidget_5);
        clk_lb_faster->setObjectName(QStringLiteral("clk_lb_faster"));
        clk_lb_faster->setCursor(QCursor(Qt::PointingHandCursor));
        clk_lb_faster->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/fast.png")));

        horizontalLayout->addWidget(clk_lb_faster);

        clk_lb_fastest = new ClickLabel(layoutWidget_5);
        clk_lb_fastest->setObjectName(QStringLiteral("clk_lb_fastest"));
        clk_lb_fastest->setCursor(QCursor(Qt::PointingHandCursor));
        clk_lb_fastest->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/fastest.png")));

        horizontalLayout->addWidget(clk_lb_fastest);

        lblPages = new QLabel(grpTime);
        lblPages->setObjectName(QStringLiteral("lblPages"));
        lblPages->setGeometry(QRect(240, 49, 60, 17));
        lblBookQuality = new QLabel(grpTime);
        lblBookQuality->setObjectName(QStringLiteral("lblBookQuality"));
        lblBookQuality->setGeometry(QRect(310, 49, 69, 16));
        lblMoney = new QLabel(grpTime);
        lblMoney->setObjectName(QStringLiteral("lblMoney"));
        lblMoney->setGeometry(QRect(240, 18, 69, 20));
        prgrBook = new QProgressBar(grpTime);
        prgrBook->setObjectName(QStringLiteral("prgrBook"));
        prgrBook->setGeometry(QRect(10, 90, 411, 23));
        prgrBook->setValue(0);
        label = new QLabel(grpTime);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 38, 47, 13));
        label_4 = new QLabel(grpTime);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(310, 37, 91, 16));
        lblBookPrgrg = new QLabel(StatusView);
        lblBookPrgrg->setObjectName(QStringLiteral("lblBookPrgrg"));
        lblBookPrgrg->setGeometry(QRect(360, 107, 111, 16));

        retranslateUi(StatusView);

        QMetaObject::connectSlotsByName(StatusView);
    } // setupUi

    void retranslateUi(QWidget *StatusView)
    {
        StatusView->setWindowTitle(QApplication::translate("StatusView", "Form", 0));
        gpNeeds->setTitle(QApplication::translate("StatusView", "Needs", 0));
        lblHunger->setText(QApplication::translate("StatusView", "Hunger", 0));
        label_2->setText(QApplication::translate("StatusView", "Inspiration", 0));
        label_3->setText(QApplication::translate("StatusView", "Sleep", 0));
        lblHungerMul->setText(QApplication::translate("StatusView", "hungermul", 0));
        lblInspMul->setText(QApplication::translate("StatusView", "inspimul", 0));
        lblSleepMul->setText(QApplication::translate("StatusView", "sleepmul", 0));
        lblStatus->setText(QApplication::translate("StatusView", "Status", 0));
        grpTime->setTitle(QApplication::translate("StatusView", "Time", 0));
        lblSpeed->setText(QApplication::translate("StatusView", "TextLabel", 0));
        lblDays->setText(QApplication::translate("StatusView", "Day 1", 0));
        lblTime->setText(QApplication::translate("StatusView", "Her er tiden", 0));
#ifndef QT_NO_TOOLTIP
        clk_lb_pause->setToolTip(QApplication::translate("StatusView", "Pause game", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_pause->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_play->setToolTip(QApplication::translate("StatusView", "Normal speed", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_play->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_faster->setToolTip(QApplication::translate("StatusView", "Faster speed", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_faster->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_fastest->setToolTip(QApplication::translate("StatusView", "Fastest speed", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_fastest->setText(QString());
        lblPages->setText(QApplication::translate("StatusView", "0", 0));
        lblBookQuality->setText(QApplication::translate("StatusView", "0", 0));
        lblMoney->setText(QApplication::translate("StatusView", "Money", 0));
        label->setText(QApplication::translate("StatusView", "Pages:", 0));
        label_4->setText(QApplication::translate("StatusView", "Quality (1-10)", 0));
        lblBookPrgrg->setText(QApplication::translate("StatusView", "Book progress", 0));
    } // retranslateUi

};

namespace Ui {
    class StatusView: public Ui_StatusView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSVIEW_H
