/********************************************************************************
** Form generated from reading UI file 'popup.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_PopUp
{
public:
    QGridLayout *popUpGrid;
    QSpacerItem *verticalSpacer;
    QTextBrowser *TextBox;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *PopUp)
    {
        if (PopUp->objectName().isEmpty())
            PopUp->setObjectName(QStringLiteral("PopUp"));
        PopUp->resize(467, 247);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PopUp->sizePolicy().hasHeightForWidth());
        PopUp->setSizePolicy(sizePolicy);
        popUpGrid = new QGridLayout(PopUp);
        popUpGrid->setObjectName(QStringLiteral("popUpGrid"));
        popUpGrid->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        popUpGrid->addItem(verticalSpacer, 0, 1, 1, 1);

        TextBox = new QTextBrowser(PopUp);
        TextBox->setObjectName(QStringLiteral("TextBox"));
        sizePolicy.setHeightForWidth(TextBox->sizePolicy().hasHeightForWidth());
        TextBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        TextBox->setFont(font);
        TextBox->setAutoFillBackground(false);
        TextBox->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        TextBox->setFrameShape(QFrame::NoFrame);
        TextBox->setLineWidth(0);
        TextBox->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        TextBox->setAutoFormatting(QTextEdit::AutoNone);

        popUpGrid->addWidget(TextBox, 1, 1, 2, 1);

        horizontalSpacer = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        popUpGrid->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        popUpGrid->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        popUpGrid->addItem(verticalSpacer_2, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        popUpGrid->addItem(verticalSpacer_3, 1, 2, 1, 1);


        retranslateUi(PopUp);

        QMetaObject::connectSlotsByName(PopUp);
    } // setupUi

    void retranslateUi(QDialog *PopUp)
    {
        PopUp->setWindowTitle(QApplication::translate("PopUp", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PopUp: public Ui_PopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
