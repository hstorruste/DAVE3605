/********************************************************************************
** Form generated from reading UI file 'inputpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTPOPUP_H
#define UI_INPUTPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputPopUp
{
public:
    QWidget *inputWidgets;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *submitBtn;

    void setupUi(QDialog *InputPopUp)
    {
        if (InputPopUp->objectName().isEmpty())
            InputPopUp->setObjectName(QStringLiteral("InputPopUp"));
        InputPopUp->resize(400, 300);
        inputWidgets = new QWidget(InputPopUp);
        inputWidgets->setObjectName(QStringLiteral("inputWidgets"));
        inputWidgets->setGeometry(QRect(70, 150, 221, 44));
        horizontalLayout = new QHBoxLayout(inputWidgets);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(inputWidgets);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        submitBtn = new QPushButton(inputWidgets);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));

        horizontalLayout->addWidget(submitBtn);


        retranslateUi(InputPopUp);

        QMetaObject::connectSlotsByName(InputPopUp);
    } // setupUi

    void retranslateUi(QDialog *InputPopUp)
    {
        InputPopUp->setWindowTitle(QApplication::translate("InputPopUp", "Dialog", 0));
        submitBtn->setText(QApplication::translate("InputPopUp", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class InputPopUp: public Ui_InputPopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTPOPUP_H
