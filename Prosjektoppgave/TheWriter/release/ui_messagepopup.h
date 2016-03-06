/********************************************************************************
** Form generated from reading UI file 'messagepopup.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEPOPUP_H
#define UI_MESSAGEPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MessagePopUp
{
public:
    QPushButton *ContinueBtn;

    void setupUi(QDialog *MessagePopUp)
    {
        if (MessagePopUp->objectName().isEmpty())
            MessagePopUp->setObjectName(QStringLiteral("MessagePopUp"));
        MessagePopUp->resize(390, 310);
        ContinueBtn = new QPushButton(MessagePopUp);
        ContinueBtn->setObjectName(QStringLiteral("ContinueBtn"));
        ContinueBtn->setGeometry(QRect(140, 120, 151, 31));
        ContinueBtn->setCursor(QCursor(Qt::PointingHandCursor));
        ContinueBtn->setAutoFillBackground(false);
        ContinueBtn->setStyleSheet(QLatin1String("border-image: url(:/other/images/pop_up_label.png);\n"
"padding: 5px;\n"
""));

        retranslateUi(MessagePopUp);

        QMetaObject::connectSlotsByName(MessagePopUp);
    } // setupUi

    void retranslateUi(QDialog *MessagePopUp)
    {
        MessagePopUp->setWindowTitle(QApplication::translate("MessagePopUp", "Dialog", 0));
        ContinueBtn->setText(QApplication::translate("MessagePopUp", "Continue", 0));
    } // retranslateUi

};

namespace Ui {
    class MessagePopUp: public Ui_MessagePopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEPOPUP_H
