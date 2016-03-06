#ifndef SCALELABEL_H
#define SCALELABEL_H
#include <QWidget>
#include <qlabel.h>

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

class ScaleLabel : public QLabel
{
public:
    ScaleLabel(QWidget * parent);
    void setPosition(int x, int y, int height, int width, int scale);
    ~ScaleLabel();
    void repositionImage(float pos_x, float pos_y, float scale_);
    void setImage(QString imageName_);
    QPoint getPosition();
public slots:
    void paintEvent(QPaintEvent *);

protected:
    //QString image_path;
    float x_pos, y_pos, scale;

private:
    QPixmap pixmap;

};

#endif // SCALELABEL_H
