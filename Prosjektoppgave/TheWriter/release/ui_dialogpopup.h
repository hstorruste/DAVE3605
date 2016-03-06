/********************************************************************************
** Form generated from reading UI file 'dialogpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPOPUP_H
#define UI_DIALOGPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogPopUp
{
public:
    QWidget *buttonsWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *acceptbtn;
    QPushButton *declinebtn;

    void setupUi(QDialog *DialogPopUp)
    {
        if (DialogPopUp->objectName().isEmpty())
            DialogPopUp->setObjectName(QStringLiteral("DialogPopUp"));
        DialogPopUp->resize(400, 300);
        buttonsWidget = new QWidget(DialogPopUp);
        buttonsWidget->setObjectName(QStringLiteral("buttonsWidget"));
        buttonsWidget->setGeometry(QRect(11, 11, 351, 141));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonsWidget->sizePolicy().hasHeightForWidth());
        buttonsWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(buttonsWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        acceptbtn = new QPushButton(buttonsWidget);
        acceptbtn->setObjectName(QStringLiteral("acceptbtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(acceptbtn->sizePolicy().hasHeightForWidth());
        acceptbtn->setSizePolicy(sizePolicy1);
        acceptbtn->setCursor(QCursor(Qt::PointingHandCursor));
        acceptbtn->setAutoFillBackground(false);
        acceptbtn->setStyleSheet(QLatin1String("border-image: url(:/other/images/pop_up_label.png);\n"
"padding: 5px;\n"
""));

        horizontalLayout->addWidget(acceptbtn);

        declinebtn = new QPushButton(buttonsWidget);
        declinebtn->setObjectName(QStringLiteral("declinebtn"));
        sizePolicy1.setHeightForWidth(declinebtn->sizePolicy().hasHeightForWidth());
        declinebtn->setSizePolicy(sizePolicy1);
        declinebtn->setCursor(QCursor(Qt::PointingHandCursor));
        declinebtn->setAutoFillBackground(false);
        declinebtn->setStyleSheet(QLatin1String("border-image: url(:/other/images/pop_up_label.png);\n"
"padding: 5px;\n"
""));

        horizontalLayout->addWidget(declinebtn);


        retranslateUi(DialogPopUp);

        QMetaObject::connectSlotsByName(DialogPopUp);
    } // setupUi

    void retranslateUi(QDialog *DialogPopUp)
    {
        DialogPopUp->setWindowTitle(QApplication::translate("DialogPopUp", "Dialog", 0));
        acceptbtn->setText(QApplication::translate("DialogPopUp", "PushButton", 0));
        declinebtn->setText(QApplication::translate("DialogPopUp", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogPopUp: public Ui_DialogPopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPOPUP_H
