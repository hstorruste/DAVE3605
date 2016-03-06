#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QWidget>
#include "scalelabel.hpp"

/*Clicklabel er en egendefinert QLabel. Den arver ScaleLabel som er subklasse
 * av QLabel. Hensikten med ClickLabel er at man skal kunne opprette
 * klikkbare labels
 */

class ClickLabel : public ScaleLabel
{
    Q_OBJECT
public:
    ClickLabel( QWidget * parent = 0 );
    ~ClickLabel(){}

signals:
    void clicked();

public slots:
    void slotClicked();

protected:
    void mousePressEvent (QMouseEvent *);

private:

};

#endif // CLICKLABEL_H
