#include "popup.h"
#include "ui_popup.h"

#include <QGridLayout>
#include <QPainter>

PopUp::PopUp(QWidget *parent, QString message_):
    QDialog(parent),
    ui(new Ui::PopUp),
    message{message_}
{
    ui->setupUi(this);
    ui->TextBox->setText(message);
    ui->popUpGrid->addWidget(ui->TextBox,1,1);
    setAttribute(Qt::WA_DeleteOnClose);
}

PopUp::~PopUp()
{
    delete ui;
}

void PopUp::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/other/images/icons/pop_up_window.png").scaled(size()));
}

void PopUp::insertToGridLayout(QWidget* qw, int row, int column)
{
    ui->popUpGrid->addWidget(qw,row,column);

}

void PopUp::insertToGridLayout(QLayout* item, int row, int column)
{
    ui->popUpGrid->addLayout(item, row, column);
}

void PopUp::reject()
{
    QDialog::reject();
    if(!sender())
        done(1);
}
