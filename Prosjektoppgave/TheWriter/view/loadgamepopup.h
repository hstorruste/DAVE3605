#ifndef LOADGAMEPOPUP_H
#define LOADGAMEPOPUP_H

#include <view/popup.h>

#include <QFileInfoList>
#include <QListWidget>

namespace Ui {
class LoadGamePopUp;
}

class LoadGamePopUp : public PopUp
{
    Q_OBJECT
    QFileInfoList loadGames;
public:
    explicit LoadGamePopUp(QWidget *parent, QFileInfoList list_);
    QString getLoadedGame();
    ~LoadGamePopUp();
private slots:
    void on_btnLoadGame_clicked();
    void on_btnNewGame_clicked();
    void on_listLoadGames_itemDoubleClicked(QListWidgetItem *item);

signals:
    void NotifyLoadClicked();
    void NotifyNewGameClicked();
private:
    Ui::LoadGamePopUp *ui;
};

#endif // LOADGAMEPOPUP_H
