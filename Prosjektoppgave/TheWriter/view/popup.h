#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QLayoutItem>

namespace Ui {
class PopUp;
}

class PopUp : public QDialog
{
    Q_OBJECT

public:
    explicit PopUp(QWidget *parent, QString message_);
    virtual ~PopUp();

    void insertToGridLayout(QWidget *qw, int row, int column);
    void insertToGridLayout(QLayout *item, int row, int column);

public slots:
    void paintEvent(QPaintEvent *);

private slots:
    void reject() override;
private:
    Ui::PopUp *ui;
    QString message;

};

#endif // POPUP_H
