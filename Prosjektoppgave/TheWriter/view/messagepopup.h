#ifndef MESSAGEPOPUP_H
#define MESSAGEPOPUP_H

#include "popup.h"

namespace Ui {
class MessagePopUp;
}

class MessagePopUp : public PopUp
{
    Q_OBJECT

public:
    explicit MessagePopUp(QWidget *parent, QString message_);
    MessagePopUp(QWidget *parent, QString message_, QString btnText);
    ~MessagePopUp();

private slots:
    void on_ContinueBtn_clicked();

private:
    Ui::MessagePopUp *ui;
};

#endif // MESSAGEPOPUP_H
