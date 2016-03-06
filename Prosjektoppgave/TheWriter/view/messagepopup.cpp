#include "messagepopup.h"
#include "ui_messagepopup.h"

MessagePopUp::MessagePopUp(QWidget *parent, QString message_) :
    PopUp(parent, message_),
    ui(new Ui::MessagePopUp)
{
    ui->setupUi(this);
    insertToGridLayout(ui->ContinueBtn,2,1);
}

MessagePopUp::MessagePopUp(QWidget *parent, QString message_, QString btnText) :
    PopUp(parent, message_),
    ui(new Ui::MessagePopUp)
{
    ui->setupUi(this);
    ui->ContinueBtn->setText(btnText);

    insertToGridLayout(ui->ContinueBtn,2,1);

}

MessagePopUp::~MessagePopUp()
{
    delete ui;
}

void MessagePopUp::on_ContinueBtn_clicked()
{
    close();
}
