#include "optionlabel.hpp"
#include <QPainter>
#include <QWidget>

/* Hensikten for option labels er at de skal kunne gi spilleren
 * valg for hva som skal skje i det hun trykker på et objekt i
 * rommet. For eksempel på skribenten.
 *
 * OptionLabel arver ClickLabel som arver ScaleLabel,
 * som igjen arver QLabel
*/

OptionLabel::OptionLabel(const QString text_, QWidget *parent)
    :ClickLabel(parent), text{text_}
{}

OptionLabel::OptionLabel( QWidget *parent)
    :ClickLabel(parent)
{
    this->text = "click me!";

}

OptionLabel::~OptionLabel(){}

void OptionLabel::set_text(const QString text_)
{
    text = text_;
}

void OptionLabel::paintEvent(QPaintEvent *)
{
    QPixmap pix(":/other/images/pop_up_label.png");

    this->setGeometry(x_pos,y_pos, pix.width()*scale, pix.height()*scale);

    QPainter painter(this);

    painter.drawPixmap(0,0, pix.scaled( pix.width()*scale, pix.height()*scale));

    QFont font=painter.font() ;
    font.setPointSize ( 12 );
    font.setBold(false);
    font.setFamily("American Typewriter");

    painter.setPen(Qt::black);
    painter.setFont(font);
    painter.drawText(18,22,text);
}

