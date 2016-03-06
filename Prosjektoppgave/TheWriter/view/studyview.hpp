#ifndef STUDYVIEW_HPP
#define STUDYVIEW_HPP
#include "optionlabel.hpp"
#include <QWidget>
#include "utils/namespaces.hpp"
/*
 * Hensikten med klassen er å være et panel / canvas
 * for å kunne tegne opp 'the study', hvor
 * forfatteren befinner seg, med sine eiendeler
*/

namespace Ui {
class StudyView;
}
using namespace weather;

class StudyView : public QWidget
{
    Q_OBJECT

public:
    explicit StudyView(QWidget *parent = 0);
    ~StudyView();
    void paintEvent(QPaintEvent *);

public slots:
    void AnimWrite();
    void AnimView();
    void AnimSuperSecretEasterEgg();
    void changeWeather(int type);

private slots:
    void on_clk_lb_writer_clicked();
    void on_clk_lb_apple_clicked();
    void on_clk_lb_coffee_clicked();
    void on_clk_lb_wine_clicked();
    void on_clk_lb_sofa_clicked();
    void on_clk_lb_books_clicked();

signals:
    void NotifyAppleClicked();
    void NotifyCoffeeClicked();
    void NotifyWineClicked();
    void NotifySofaClicked();
    void NotifyBooksClicked();
    void NotifyWriterClicked();

private:
    Ui::StudyView *ui;
    QSize pixmap_size;

    /*for animasjoner*/
    bool right_hand_hidden;
    bool left_hand_hidden;
    bool raining;
    bool weather_alternate;
    bool show_alternate;
    bool light_shining;
    bool coffe_steaming;
    /*superhemmelig*/
    bool head_left;
    bool super_secret_easter_egg;
    int counter;

};

#endif // STUDYVIEW_HPP
