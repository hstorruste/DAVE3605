#ifndef STATUSVIEW_HPP
#define STATUSVIEW_HPP

#include <QWidget>
#include "model/writer.h"
#include "model/timecontroller.hpp"
namespace Ui {
class StatusView;
}

class StatusView : public QWidget
{
    Q_OBJECT
    std::string gamestatus;
public:
    void updateGUI(Writer& theWriter, TimeController& m_time,std::string gamestatus);
    explicit StatusView(QWidget *parent = 0);
    ~StatusView();
public slots:
    void paintEvent(QPaintEvent *);
private slots:

    void on_clk_lb_play_clicked();
    void on_clk_lb_pause_clicked();
    void on_clk_lb_faster_clicked();
    void on_clk_lb_fastest_clicked();

signals:

    void NotifySpeedPause();
    void NotifySpeedNormal();
    void NotifySpeedFaster();
    void NotifySpeedFastest();

private:
    Ui::StatusView *ui;

};

#endif // STATUSVIEW_HPP
