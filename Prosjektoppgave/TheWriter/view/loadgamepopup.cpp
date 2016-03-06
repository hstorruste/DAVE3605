#include <QStringListModel>
#include <iostream>
#include "loadgamepopup.h"
#include "ui_loadgamepopup.h"

LoadGamePopUp::LoadGamePopUp(QWidget *parent, QFileInfoList list_) :
    PopUp(parent,"Loadgame"),
    loadGames(list_),
    ui(new Ui::LoadGamePopUp)
{
    ui->setupUi(this);
    if(!loadGames.empty()){
        for(auto fl : loadGames)
        ui->listLoadGames->addItem(fl.fileName());
    } else {
        ui->listLoadGames->addItem("No game saved.");
        ui->btnLoadGame->setDisabled(true);
    }


}
QString LoadGamePopUp::getLoadedGame(){
    return ui->listLoadGames->currentItem()->text();
}

LoadGamePopUp::~LoadGamePopUp()
{
    delete ui;
}

void LoadGamePopUp::on_btnLoadGame_clicked()
{
    // Test om noen av listeobjektene er valgte
    if(ui->listLoadGames->currentItem()!=NULL){
        close();
        emit NotifyLoadClicked();
    }

}

void LoadGamePopUp::on_btnNewGame_clicked()
{
    close();
    emit NotifyNewGameClicked();
}

void LoadGamePopUp::on_listLoadGames_itemDoubleClicked(QListWidgetItem *item)
{
    if(!loadGames.empty()){
        if(ui->listLoadGames->currentItem()!=NULL){
            close();
            emit NotifyLoadClicked();
        }
    }

}
