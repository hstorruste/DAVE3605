/********************************************************************************
** Form generated from reading UI file 'studyview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYVIEW_H
#define UI_STUDYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "view/clicklabel.hpp"
#include "view/scalelabel.hpp"

QT_BEGIN_NAMESPACE

class Ui_StudyView
{
public:
    ClickLabel *clk_lb_coffee;
    ScaleLabel *clk_lb_desk;
    ClickLabel *clk_lb_writer;
    ClickLabel *clk_lb_wine;
    ClickLabel *clk_lb_books;
    ScaleLabel *sc_lb_study;
    ClickLabel *clk_lb_sofa;
    ClickLabel *clk_lb_window;
    ClickLabel *clk_lb_apple;
    ClickLabel *clk_lb_writer_rhand;
    ClickLabel *clk_lb_writer_lhand;
    ClickLabel *sc_lb_writer_head_left;
    ClickLabel *sc_lb_writer_head_right;
    ClickLabel *clk_lb_computer;
    ScaleLabel *sc_lb_light;
    ScaleLabel *sc_lb_night;
    ScaleLabel *sc_lb_weather;
    ScaleLabel *sc_lb_weather_alternate;

    void setupUi(QWidget *StudyView)
    {
        if (StudyView->objectName().isEmpty())
            StudyView->setObjectName(QStringLiteral("StudyView"));
        StudyView->resize(400, 300);
        StudyView->setAutoFillBackground(false);
        clk_lb_coffee = new ClickLabel(StudyView);
        clk_lb_coffee->setObjectName(QStringLiteral("clk_lb_coffee"));
        clk_lb_coffee->setGeometry(QRect(0, 0, 59, 16));
        clk_lb_coffee->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_coffee->setFocusPolicy(Qt::NoFocus);
        clk_lb_desk = new ScaleLabel(StudyView);
        clk_lb_desk->setObjectName(QStringLiteral("clk_lb_desk"));
        clk_lb_desk->setGeometry(QRect(10, 10, 59, 16));
        clk_lb_writer = new ClickLabel(StudyView);
        clk_lb_writer->setObjectName(QStringLiteral("clk_lb_writer"));
        clk_lb_writer->setGeometry(QRect(20, 20, 59, 16));
        clk_lb_writer->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_wine = new ClickLabel(StudyView);
        clk_lb_wine->setObjectName(QStringLiteral("clk_lb_wine"));
        clk_lb_wine->setGeometry(QRect(30, 30, 59, 16));
        clk_lb_wine->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_books = new ClickLabel(StudyView);
        clk_lb_books->setObjectName(QStringLiteral("clk_lb_books"));
        clk_lb_books->setGeometry(QRect(40, 40, 59, 16));
        clk_lb_books->setCursor(QCursor(Qt::OpenHandCursor));
        sc_lb_study = new ScaleLabel(StudyView);
        sc_lb_study->setObjectName(QStringLiteral("sc_lb_study"));
        sc_lb_study->setGeometry(QRect(50, 50, 59, 16));
        sc_lb_study->setCursor(QCursor(Qt::ArrowCursor));
        clk_lb_sofa = new ClickLabel(StudyView);
        clk_lb_sofa->setObjectName(QStringLiteral("clk_lb_sofa"));
        clk_lb_sofa->setGeometry(QRect(60, 60, 59, 16));
        clk_lb_sofa->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_window = new ClickLabel(StudyView);
        clk_lb_window->setObjectName(QStringLiteral("clk_lb_window"));
        clk_lb_window->setGeometry(QRect(100, 100, 59, 16));
        clk_lb_window->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_window->setFocusPolicy(Qt::NoFocus);
        clk_lb_apple = new ClickLabel(StudyView);
        clk_lb_apple->setObjectName(QStringLiteral("clk_lb_apple"));
        clk_lb_apple->setGeometry(QRect(110, 110, 59, 16));
        clk_lb_apple->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_writer_rhand = new ClickLabel(StudyView);
        clk_lb_writer_rhand->setObjectName(QStringLiteral("clk_lb_writer_rhand"));
        clk_lb_writer_rhand->setGeometry(QRect(120, 120, 59, 16));
        clk_lb_writer_rhand->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_writer_lhand = new ClickLabel(StudyView);
        clk_lb_writer_lhand->setObjectName(QStringLiteral("clk_lb_writer_lhand"));
        clk_lb_writer_lhand->setGeometry(QRect(130, 130, 59, 16));
        clk_lb_writer_lhand->setCursor(QCursor(Qt::OpenHandCursor));
        sc_lb_writer_head_left = new ClickLabel(StudyView);
        sc_lb_writer_head_left->setObjectName(QStringLiteral("sc_lb_writer_head_left"));
        sc_lb_writer_head_left->setGeometry(QRect(70, 70, 59, 16));
        sc_lb_writer_head_left->setCursor(QCursor(Qt::OpenHandCursor));
        sc_lb_writer_head_right = new ClickLabel(StudyView);
        sc_lb_writer_head_right->setObjectName(QStringLiteral("sc_lb_writer_head_right"));
        sc_lb_writer_head_right->setGeometry(QRect(140, 140, 59, 16));
        sc_lb_writer_head_right->setCursor(QCursor(Qt::OpenHandCursor));
        clk_lb_computer = new ClickLabel(StudyView);
        clk_lb_computer->setObjectName(QStringLiteral("clk_lb_computer"));
        clk_lb_computer->setGeometry(QRect(150, 150, 59, 16));
        clk_lb_computer->setCursor(QCursor(Qt::OpenHandCursor));
        sc_lb_light = new ScaleLabel(StudyView);
        sc_lb_light->setObjectName(QStringLiteral("sc_lb_light"));
        sc_lb_light->setGeometry(QRect(170, 170, 59, 16));
        sc_lb_night = new ScaleLabel(StudyView);
        sc_lb_night->setObjectName(QStringLiteral("sc_lb_night"));
        sc_lb_night->setGeometry(QRect(180, 180, 59, 16));
        sc_lb_weather = new ScaleLabel(StudyView);
        sc_lb_weather->setObjectName(QStringLiteral("sc_lb_weather"));
        sc_lb_weather->setGeometry(QRect(80, 80, 59, 16));
        sc_lb_weather->setCursor(QCursor(Qt::ArrowCursor));
        sc_lb_weather_alternate = new ScaleLabel(StudyView);
        sc_lb_weather_alternate->setObjectName(QStringLiteral("sc_lb_weather_alternate"));
        sc_lb_weather_alternate->setGeometry(QRect(190, 190, 59, 16));
        sc_lb_weather_alternate->setCursor(QCursor(Qt::ArrowCursor));
        sc_lb_weather->raise();
        sc_lb_study->raise();
        clk_lb_sofa->raise();
        clk_lb_desk->raise();
        clk_lb_writer->raise();
        clk_lb_wine->raise();
        clk_lb_books->raise();
        clk_lb_coffee->raise();
        clk_lb_window->raise();
        clk_lb_apple->raise();
        clk_lb_writer_rhand->raise();
        clk_lb_writer_lhand->raise();
        clk_lb_computer->raise();
        sc_lb_writer_head_left->raise();
        sc_lb_writer_head_right->raise();
        sc_lb_light->raise();
        sc_lb_night->raise();
        sc_lb_weather_alternate->raise();

        retranslateUi(StudyView);

        QMetaObject::connectSlotsByName(StudyView);
    } // setupUi

    void retranslateUi(QWidget *StudyView)
    {
        StudyView->setWindowTitle(QApplication::translate("StudyView", "Form", 0));
#ifndef QT_NO_TOOLTIP
        clk_lb_coffee->setToolTip(QApplication::translate("StudyView", "Drink coffee", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_coffee->setText(QString());
        clk_lb_desk->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_writer->setToolTip(QApplication::translate("StudyView", "Writer does...", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_writer->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_wine->setToolTip(QApplication::translate("StudyView", "Drink wine", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_wine->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_books->setToolTip(QApplication::translate("StudyView", "Write book", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_books->setText(QString());
        sc_lb_study->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_sofa->setToolTip(QApplication::translate("StudyView", "Sleep", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_sofa->setText(QString());
        clk_lb_window->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_apple->setToolTip(QApplication::translate("StudyView", "Eat", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_apple->setText(QString());
        clk_lb_writer_rhand->setText(QString());
        clk_lb_writer_lhand->setText(QString());
        sc_lb_writer_head_left->setText(QString());
        sc_lb_writer_head_right->setText(QString());
#ifndef QT_NO_TOOLTIP
        clk_lb_computer->setToolTip(QApplication::translate("StudyView", "Writer does...", 0));
#endif // QT_NO_TOOLTIP
        clk_lb_computer->setText(QString());
        sc_lb_light->setText(QString());
        sc_lb_night->setText(QString());
        sc_lb_weather->setText(QString());
        sc_lb_weather_alternate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StudyView: public Ui_StudyView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYVIEW_H
