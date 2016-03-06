#include "statusview.hpp"
#include "ui_statusview.h"
#include "model/writer.h"
#include "model/timecontroller.hpp"
/**
* Nedre del av det som vises. Henter data fra modellen og viser det som grafiske/tekstlige elementer på skjermen
*/
StatusView::StatusView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusView)
{
    ui->setupUi(this);

    //setter farge på bakgrunnen
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(Pal);


    // setter bilde og str på play icons
    ui->clk_lb_pause->setImage(QString(":/icons/images/icons/pause.png"));
    ui->clk_lb_pause->repositionImage(10,0.0,0.3);
    ui->clk_lb_play->setImage(QString(":/icons/images/icons/play.png"));
    ui->clk_lb_play->repositionImage(60,0,0.3);
    ui->clk_lb_faster->setImage(QString(":/icons/images/icons/fast.png"));
    ui->clk_lb_faster->repositionImage(100,0,0.3);
    ui->clk_lb_fastest->setImage(QString(":/icons/images/icons/fastest.png"));
    ui->clk_lb_fastest->repositionImage(150,0,0.3);

}
// Oppdater GUI-elementer
void StatusView::updateGUI(Writer& theWriter, TimeController& m_time,std::string gamestatus){
    QString speedText="";
    if(m_time.getSpeed()==0){
        speedText=" Game paused.";
    } else{
        speedText=" x"+QString::number(m_time.getSpeed()/60);
    }

    // Gjør tiden om til en QString
    QString text=m_time.getTimer().toString("hh:mm");


// Hent needs og vis i respektive plasser
    // Som tekst
    ui->lblHungerMul->setText(QString::number(theWriter.getHunger(), 'f',2));
    ui->lblInspMul->setText(QString::number(theWriter.getInspiration(), 'f',2));
    ui->lblSleepMul->setText(QString::number(theWriter.getSleep(), 'f',2));
    // Grafisk visning
    ui->prgrHunger->setValue(theWriter.getHunger());
    ui->prgrInspiration->setValue(theWriter.getInspiration());
    ui->prgrSleep->setValue(theWriter.getSleep());

// Vis tid
    ui->lblTime->setText(text);
    ui->lblSpeed->setText(speedText);
    ui->lblDays->setText("Day: "+QString::number(m_time.getDays()));


    ui->lblMoney->setText("$"+QString::number(theWriter.getMoney()));
    ui->lblStatus->setText(QString::fromStdString(gamestatus)); // Oppdaterer status på spillet

    if(theWriter.getBook()){

        ui->lblPages->setText(QString::number((((float)theWriter.getBook()->getNumberOfWords())/
                                               (float)theWriter.getBook()->getWordsPrPage()), 'f',2)+
                                                "/"+QString::number(theWriter.getBook()->getPageGoal())); // Antall sider visning og sidemål

        ui->lblBookQuality->setText(QString::number(theWriter.getBook()->getQuality(), 'f',2)); // Henter kvaliteten og formatererer den til 2 desimaler
        ui->prgrBook->setValue((((float)theWriter.getBook()->getNumberOfPages()/
                                 (float)theWriter.getBook()->getPageGoal()) *100)); // Henter progresjonen på boka og deler på sidermål for ferdig bok. Så multipliserer med 100 for å få i %.

    }
}

void StatusView::paintEvent(QPaintEvent *)
{

    /* Sett størrelse på status-panelet */
    /* study panel dekker 1/3 av nedre del på skjermen */

    QSize size = this->parentWidget()->size();

    float status_panel_width =  { static_cast<float>( size.width())};
    float status_panel_height = { static_cast<float>( size.height()*0.3 ) };
    float room_panel_height =   { static_cast<float>( size.height()*0.7 ) };

    setGeometry(0,room_panel_height, status_panel_width,status_panel_height);

}

StatusView::~StatusView()
{
    delete ui;
}

// Send signal om at speedknappene er klikket på
void StatusView::on_clk_lb_pause_clicked()
{
    emit NotifySpeedPause();
}

void StatusView::on_clk_lb_play_clicked()
{
    emit NotifySpeedNormal();
}

void StatusView::on_clk_lb_faster_clicked()
{
    emit NotifySpeedFaster();
}


void StatusView::on_clk_lb_fastest_clicked()
{
    emit NotifySpeedFastest();
}
