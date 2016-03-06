#ifndef OPTIONLABEL_H
#define OPTIONLABEL_H

#include "clicklabel.hpp"

/* Hensikten for option labels er at de skal kunne gi spilleren
 * valg for hva som skal skje i det hun trykker på et objekt i
 * rommet. For eksempel på skribenten.
 *
 * OptionLabel arver ClickLabel som arver ScaleLabel,
 * som igjen arver QLabel
*/


class OptionLabel : public ClickLabel
{
    Q_OBJECT
public:
    OptionLabel(const QString text_, QWidget * parent = 0 );
    OptionLabel(QWidget * parent = 0 );
    ~OptionLabel();
    void set_text(const QString text_);
public slots:
    void  paintEvent(QPaintEvent *);

private:
    QString text;
};

#endif // OPTIONLABEL_H
