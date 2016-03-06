#include "inputpopup.h"
#include "ui_inputpopup.h"
#include <iostream>

InputPopUp::InputPopUp(QWidget *parent, QString message_, QString btnText) :
    PopUp(parent,message_),
    ui(new Ui::InputPopUp)
{
//    QRegExpValidator validator();

    ui->setupUi(this);
    ui->submitBtn->setText(btnText);
    QRegExp regex("^[A-Za-z0-9]{1,}[A-Za-z0-9 ]{0,16}"); // sjekker at det starter med et (godkjent) tegn, og er mellom 0 og 16 karakterer
    validator = new QRegExpValidator(regex, this);
    ui->lineEdit->setValidator(validator); // kobler input med regex

    insertToGridLayout(ui->inputWidgets,2,1);
}

InputPopUp::~InputPopUp()
{

    delete validator;
    delete ui;
}
//([A-Za-z ]{16})
void InputPopUp::on_submitBtn_clicked()
{
    if(ui->lineEdit->text().length()>0){
        emit NotifySubmitClicked();
        close();
    }
}

std::string InputPopUp::getInput(){

    return ui->lineEdit->text().toStdString();
}
