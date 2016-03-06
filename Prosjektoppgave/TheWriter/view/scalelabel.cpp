#include "scalelabel.hpp"
#include <QWidget>
#include <QPainter>
#include <QDebug>

/* ScaleLabel er en egendefinert versjon av QLabel. Hensikten er at man
 * skal kunne ha tilgang til klassens PaintEvent for å definere posisjonen
 * og størrelsen til objekene som arver klassen.
 *
 * Utregningene gjøres i PaintEvent metoden til klassen hvor objektene blir definert,
 * nemlig the_studypanel.
 *
 * Posisjonen og størrelsen settes med metoden reposition_image
 *
 * metoden set_image tar imot et QPixmap objekt som brukes for å sette
 * bilde på label
*/

ScaleLabel::ScaleLabel(QWidget *parent) : QLabel(parent ){}


void ScaleLabel::setImage( QString imageName_)
{
    pixmap.load(imageName_);
}

QPoint ScaleLabel::getPosition()
{
    return QPoint(x_pos, y_pos);
}

/* tar imot utregninger av posisjon og skaleringsfaktor*/
void ScaleLabel::repositionImage(float pos_x, float pos_y, float scale_)
{
    x_pos = pos_x; y_pos = pos_y; scale = scale_;
}

void ScaleLabel::paintEvent(QPaintEvent *)
{
   if (pixmap.isNull()) return;

   this->setGeometry(x_pos,y_pos, pixmap.width()*scale, pixmap.height()*scale);

   /*tegner en skallert versjon av objektet på skjermen*/
   QPainter painter(this);

   painter.drawPixmap(0,0, pixmap.scaled( pixmap.width()*scale, pixmap.height()*scale));
}


ScaleLabel::~ScaleLabel(){
}

