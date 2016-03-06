#include <QDesktopWidget> //få høyde og bredde på skjerm
#include <QPainter>
#include <QWidget>
#include <QLabel>
#include <iostream>
#include <QDebug>

#include "view/studyview.hpp"
#include "ui_studyview.h"
#include "view/optionlabel.hpp"

/*
 * Hensikten med klassen er å være et panel / canvas
 * for å kunne tegne opp 'the study', hvor
 * forfatteren befinner seg, med sine eiendeler
*/

StudyView::StudyView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudyView)
{
    ui->setupUi(this);

    //setter farge på bakgrunnen
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(Pal);

    /* setter bilde på labels */

    ui->clk_lb_coffee->setImage(QString(":/stud/images/study/coffe.png"));
    ui->clk_lb_books->setImage(QString(":/stud/images/study/books.png"));
    ui->clk_lb_wine->setImage(QString(":/stud/images/study/wine.png"));
    ui->clk_lb_writer->setImage(QString(":/stud/images/study/writer.png"));
    ui->clk_lb_desk->setImage(QString(":/stud/images/study/desk.png"));
    ui->clk_lb_sofa->setImage(QString(":/stud/images/study/couch.png"));
    ui->clk_lb_window->setImage(QString(":/stud/images/study/window.png"));
    ui->clk_lb_apple->setImage(QString(":/stud/images/study/apple.png"));
    ui->clk_lb_writer_lhand->setImage(QString(":/stud/images/study/left_hand.png"));
    ui->clk_lb_writer_rhand->setImage(QString(":/stud/images/study/right_hand.png"));
    ui->sc_lb_coffe_steam->setImage(QString(":/stud/images/study/coffe_steam.png"));

    ui->clk_lb_computer->setImage(QString(":/stud/images/study/computer.png"));
    ui->sc_lb_writer_head_left->setImage(QString(":/stud/images/study/writer_head_left.png"));
    ui->sc_lb_writer_head_right->setImage(QString(":/stud/images/study/writer_head_right.png"));

    // bool variable for animasjon
    this->left_hand_hidden = false;
    this->right_hand_hidden = false;
    this->coffe_steaming = true;
    this->show_alternate = true;

    super_secret_easter_egg = false;
    head_left = true;
    counter=0;

    if(super_secret_easter_egg)
        ui->sc_lb_writer_head_right->hide();

    else{
        ui->sc_lb_writer_head_right->hide();
        ui->sc_lb_writer_head_left->hide();
        ui->clk_lb_computer->hide();
    }

    QPixmap pixmap (":/stud/images/study/the_study.png");
    pixmap_size = pixmap.size();
}

/* hjelpemetode for å ende været */
void StudyView::changeWeather(int type)
{
    QString weather_image;
    QString weather_image_alt;
    QString window_light{""};
    raining = false;
    weather_alternate = false;

    switch(type) {
    case inGameWeather::night :
        weather_image=":/weather/images/weather/moon.png";
        window_light= ":/weather/images/study/night.png";

        break;
    case inGameWeather::sunny :
        weather_image=":/weather/images/weather/sun.png";
        window_light= ":/weather/images/study/light.png";

        break;
    case inGameWeather::cloudy :
        weather_image=":/weather/images/weather/clouded.png";

        break;
    case inGameWeather::raining :
        weather_image=":/weather/images/weather/rain1.png";
        weather_image_alt=":/weather/images/weather/rain2.png";

        raining = true;
        weather_alternate = true;

        break;
    default :
        weather_image=":/weather/images/weather/rain1.png";
        weather_image_alt=":/weather/images/weather/rain2.png";

        raining = true;
        weather_alternate = true;
    }

    ui->sc_lb_weather->setImage(QString(weather_image));

    if(weather_alternate){
        ui->sc_lb_weather_alternate->setImage(QString(weather_image_alt));
        ui->sc_lb_weather->hide();
    }else {
        ui->sc_lb_weather->show();
        ui->sc_lb_weather_alternate->hide();
    }

    if(!window_light.isEmpty()) {
        light_shining = true;
        ui->sc_lb_light->setImage(QString(window_light));
        ui->sc_lb_light->show();// vis lys label
    }else{
        ui->sc_lb_light->hide();// ikke vis lys label
        light_shining = false;
    }
}

void StudyView::paintEvent(QPaintEvent *)
{
    /* Sett størrelse på study-panelet */

    QSize size = this->parentWidget()->size();
    float study_panel_width{ static_cast<float>( size.width())};

    /* study panel dekker 2/3 av høyden på skjermen */

    float study_panel_height{ static_cast<float>( size.height()*0.7)};
    setGeometry(0,0,study_panel_width,study_panel_height);

    /* regner ut posisjon og skaleringsfaktor for alle labels */

    float height{0.0};
    float width{0.0};
    float x{0.0};
    float y{0.0};
    float ratio{ static_cast<float>(pixmap_size.width())
                /  static_cast<float>(pixmap_size.height())};

    if(pixmap_size.width() <= study_panel_width){

        height = study_panel_height;
        width = height*ratio;
        x = (study_panel_width - width) / 2;

    }else{

        width = study_panel_width;
        height = width/ratio;
        y = (study_panel_height - height);

    }

    float scale{(height) / (pixmap_size.height())};

    /* parameterverdiene i reposition_image brukes i PaintEvent-metoden i QLabel-klassene */
    /* posisjonen blir satt i forhold til størrelsen på studyView*/


    ui->clk_lb_apple->repositionImage(x+ (width *0.22), y + ( height * 0.7), scale);
    ui->clk_lb_books->repositionImage(x + (width * 0.67), y + ( height  * 0.64) ,scale*1.3);
    ui->clk_lb_coffee->repositionImage(x + (width * 0.30),  y + ( height  * 0.63) , scale*1.2);
    ui->clk_lb_desk->repositionImage(x + (width * 0.1), y + ( height  * 0.7) , scale);
    ui->clk_lb_sofa->repositionImage(x + (width * 0.05), y + ( height  * 0.5) , scale);
    ui->sc_lb_study->repositionImage(x,y,scale);
    ui->clk_lb_writer->repositionImage(x + (width * 0.40), y + ( height  * 0.1) , scale*1.5);
    ui->clk_lb_wine->repositionImage(x + (width * 0.62), y + ( height * 0.4) , scale*1.3);
    ui->clk_lb_window->repositionImage(x+ (width *0.7), y + ( height * 0.05), scale);

    ui->sc_lb_weather->repositionImage(x+ (width *0.7), y + ( height * 0.05), scale);
    ui->sc_lb_weather_alternate->repositionImage(x+ (width *0.7), y + ( height * 0.05), scale);

    ui->clk_lb_writer_lhand->repositionImage(x + (width * 0.5), y + ( height  * 0.55) , scale*1.5);
    ui->clk_lb_writer_rhand->repositionImage(x + (width * 0.43), y + ( height  * 0.55) , scale*1.5);

    if(coffe_steaming)
        ui->sc_lb_coffe_steam->repositionImage(x + (width * 0.31),  y + ( height  * 0.62) , scale*1.2);

    /*if(!raining){
        ui->sc_lb_weather->repositionImage(x+ (width *0.71), y + ( height * 0.1), scale);
    }
    else if(raining){*/


    /*}*/

    if(light_shining){
        ui->sc_lb_light->repositionImage(x+ (width *0.52), y + ( height * -0.05), scale);
    }

    if(super_secret_easter_egg){

        ui->clk_lb_computer->repositionImage(x + (width * 0.40), y + ( height  * 0.61) , scale*1.5);
        ui->sc_lb_writer_head_left->repositionImage(x + (width * 0.47), y + ( height  * 0.1) , scale*1.5);
        ui->sc_lb_writer_head_right->repositionImage(x + (width * 0.46), y + ( height  * 0.1) , scale*1.5);
    }
}

/* animerer bildet */
void StudyView::AnimWrite()
{

    if(left_hand_hidden){
        ui->clk_lb_writer_lhand->show();
        left_hand_hidden = false;

    }else{
        ui->clk_lb_writer_lhand->hide();
        left_hand_hidden = true;
    }

    if(right_hand_hidden){
        ui->clk_lb_writer_rhand->hide();
        right_hand_hidden = false;
    }else{
        ui->clk_lb_writer_rhand->show();
        right_hand_hidden = true;
    }
}

/*animerer regn*/
void StudyView::AnimView()
{
    if(raining)
    {

        if(show_alternate)
        {
            ui->sc_lb_weather->show();
            ui->sc_lb_weather_alternate->hide();

            show_alternate = false;

        }
        else
        {
            ui->sc_lb_weather_alternate->show();
            ui->sc_lb_weather->hide();

            show_alternate = true;
        }
    }

    if(coffe_steaming)
    {
        coffe_steaming = false;
        ui->sc_lb_coffe_steam->hide();
    }
    else
    {
        coffe_steaming = true;
        ui->sc_lb_coffe_steam->show();
    }
}

/*animarer super hemmelig easter egg*/
void StudyView::AnimSuperSecretEasterEgg()
{

    if(super_secret_easter_egg) {
        ui->clk_lb_computer->show();
        if(head_left){
            head_left = false;
            ui->sc_lb_writer_head_right->show();
            ui->sc_lb_writer_head_left->hide();

        }else {
            head_left = true;
            ui->sc_lb_writer_head_left->show();
            ui->sc_lb_writer_head_right->hide();
        }
    }
}

StudyView::~StudyView()
{
    delete ui;
}

/*--------------------------------------------------*/
/*                  click events                    */

void StudyView::on_clk_lb_writer_clicked()
{
    counter++;
    if(counter>=10){
        super_secret_easter_egg = true;
    }

    emit NotifyWriterClicked();
}

void StudyView::on_clk_lb_apple_clicked()
{
    emit NotifyAppleClicked();
}

void StudyView::on_clk_lb_coffee_clicked()
{
    emit NotifyCoffeeClicked();
}

void StudyView::on_clk_lb_wine_clicked()
{
    emit NotifyWineClicked();
}

void StudyView::on_clk_lb_sofa_clicked()
{
    emit NotifySofaClicked();
}

void StudyView::on_clk_lb_books_clicked()
{
    emit NotifyBooksClicked();
}



