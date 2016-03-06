#ifndef DIALOGPOPUP_H
#define DIALOGPOPUP_H

#include "popup.h"

namespace Ui {
class DialogPopUp;
}

class DialogPopUp : public PopUp
{
    Q_OBJECT

public:
    explicit DialogPopUp(QWidget *parent, QString message_, QString accept_btn, QString decline_btn);
    ~DialogPopUp();

signals:
    void NotifyAcceptClicked();
    void NotifyDeclineClicked();

private slots:
    void on_acceptbtn_clicked();

    void on_declinebtn_clicked();


private:
    Ui::DialogPopUp *ui;
    QString acceptText;
    QString declineText;
};

#endif // DIALOGPOPUP_H
