#include "dialogpopup.h"
#include "ui_dialogpopup.h"

DialogPopUp::DialogPopUp(QWidget *parent, QString message_, QString accept_btn, QString decline_btn) :
    PopUp(parent, message_),
    ui(new Ui::DialogPopUp),
    acceptText{accept_btn},
    declineText{decline_btn}
{
    ui->setupUi(this);
    ui->acceptbtn->setText(acceptText);
    ui->declinebtn->setText(declineText);

    insertToGridLayout(ui->buttonsWidget,2,1);
}

DialogPopUp::~DialogPopUp()
{
    delete ui;
}

void DialogPopUp::on_acceptbtn_clicked()
{
    close();
    emit NotifyAcceptClicked();
}

void DialogPopUp::on_declinebtn_clicked()
{
    close();
    emit NotifyDeclineClicked();
}
