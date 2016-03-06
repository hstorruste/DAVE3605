#include "clicklabel.hpp"

#include <QDebug>
#include <QWidget>

/*Clicklabel er en egendefinert QLabel. Den arver ScaleLabel som er subklasse
 * av QLabel. Hensikten med ClickLabel er at man skal kunne opprette
 * klikkbare labels
 */

ClickLabel::ClickLabel(QWidget * parent )
    : ScaleLabel(parent)
{

    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}

void ClickLabel::mousePressEvent ( QMouseEvent *)
{
    emit clicked();
}

void ClickLabel::slotClicked(){}
