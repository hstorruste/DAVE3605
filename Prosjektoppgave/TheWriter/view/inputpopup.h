#ifndef INPUTPOPUP_H
#define INPUTPOPUP_H

#include "popup.h"

#include <QValidator>

namespace Ui {
class InputPopUp;
}

class InputPopUp : public PopUp
{
    Q_OBJECT
    QRegExp regex;
    QValidator *validator;
public:
    explicit InputPopUp(QWidget *parent, QString message_, QString btnText);
    ~InputPopUp();

    std::string getInput();
signals:
    void NotifySubmitClicked();

private slots:
    void on_submitBtn_clicked();

private:
    Ui::InputPopUp *ui;
};

#endif // INPUTPOPUP_H
