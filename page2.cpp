#include "page2.h"
#include "ui_page2.h"
#include <QTime>
#include <QTimer>
#include "time.h"
#include "QTimer"
#include "QTime"
#include "QLineEdit"
#include "shop.h"
#include "chicken.h"
#include "sheep.h"
#include "cow.h"
#include "land.h"
#include "mland.h"
#include "hous.h"
#include "worker.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "sheep.h"
#include "finish.h"
#include "QMap"
#include "butcher.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QString"
#include "QSqlQuery"
#include "QMovie"
#include "QLabel"
#include "QApplication"
//#include <QVector>




page2::page2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page2)
{    
    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/lansvoic.mp3"));
    player->setVolume(100);
    player->play();

    ui->label->hide();
    refresh();

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&page2::updateTime);
    timer->start(1000);

    connct_timers();

}


void page2::refresh()
{
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_17->setEnabled(false);
    ui->pushButton_18->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_21->setEnabled(false);
    ui->pushButton_22->setEnabled(false);
    ui->pushButton_23->setEnabled(false);
    ui->pushButton_24->setEnabled(false);

    ui->pushButton_7->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_9->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_13->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_14->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_15->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_16->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_17->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_18->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_19->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_20->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_21->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_22->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_23->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));
    ui->pushButton_24->setStyleSheet(("border-image: url(:/new/prefix1/imagfil/lanppc.png)"));

    ui->pushButton_basket->hide();
    ui->pushButton_basket_2->hide();
    ui->pushButton_basket_3->hide();
    ui->pushButton_basket_4->hide();
    ui->pushButton_basket_5->hide();
    ui->pushButton_basket_6->hide();
    ui->pushButton_basket_7->hide();
    ui->pushButton_basket_8->hide();
    ui->pushButton_basket_9->hide();
    ui->pushButton_basket_10->hide();
    ui->pushButton_basket_11->hide();
    ui->pushButton_basket_12->hide();
    ui->pushButton_basket_13->hide();
    ui->pushButton_basket_14->hide();

    ui->label_cow->hide();
    ui->label_cow_2->hide();
    ui->label_cow_3->hide();
    ui->label_cow_4->hide();
    ui->label_cow_5->hide();
    ui->label_cow_6->hide();
    ui->label_cow_7->hide();
    ui->label_cow_8->hide();
    ui->label_cow_9->hide();
    ui->label_cow_10->hide();
    ui->label_cow_11->hide();
    ui->label_cow_12->hide();
    ui->label_cow_13->hide();
    ui->label_cow_14->hide();

    ui->label_worker_1->hide();
    ui->label_worker_2->hide();
    ui->label_worker_3->hide();
    ui->label_worker_4->hide();
    ui->label_worker_5->hide();
    ui->label_worker_6->hide();
    ui->label_worker_7->hide();
    ui->label_worker_8->hide();
    ui->label_worker_9->hide();
    ui->label_worker_10->hide();
    ui->label_worker_11->hide();
    ui->label_worker_12->hide();
    ui->label_worker_13->hide();
    ui->label_worker_14->hide();

    ui->label_milk->hide();
    ui->label_milk_2->hide();
    ui->label_milk_3->hide();
    ui->label_milk_4->hide();
    ui->label_milk_5->hide();
    ui->label_milk_6->hide();
    ui->label_milk_7->hide();
    ui->label_milk_8->hide();
    ui->label_milk_9->hide();
    ui->label_milk_10->hide();
    ui->label_milk_11->hide();
    ui->label_milk_12->hide();
    ui->label_milk_13->hide();
    ui->label_milk_14->hide();

    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();

    ui->pushButton_look_2->show();
    ui->pushButton_look_3->show();
    ui->pushButton_look_4->show();
    ui->pushButton_look_5->show();
    ui->pushButton_look_6->show();
    ui->pushButton_look_7->show();
    ui->pushButton_look_8->show();
    ui->pushButton_look_9->show();
    ui->pushButton_look_10->show();
    ui->pushButton_look_11->show();
    ui->pushButton_look_12->show();
    ui->pushButton_look_13->show();
    ui->pushButton_look_14->show();

    ui->label_timer_1->setText("0");
    ui->label_timer_2->setText("0");
    ui->label_timer_3->setText("0");
    ui->label_timer_4->setText("0");
    ui->label_timer_5->setText("0");
    ui->label_timer_6->setText("0");
    ui->label_timer_7->setText("0");
    ui->label_timer_8->setText("0");
    ui->label_timer_9->setText("0");
    ui->label_timer_10->setText("0");
    ui->label_timer_11->setText("0");
    ui->label_timer_12->setText("0");
    ui->label_timer_13->setText("0");
    ui->label_timer_14->setText("0");

    for(int i=1;i<=14;i++){
        connct_Sheep[i]=0;
        connct_chicken[i]=0;
        connct_corn[i]=0;
        connct_wheat[i]=0;
        connct_cow[i]=0;
    }


       QFile file("D:/faz2/faz2/fils/coin.txt");
       QFile chicken("D:/faz2/faz2/fils/number_of_chicken.txt");
       QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");
       QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");
       QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
       QFile land("D:/faz2/faz2/fils/number_of_land.txt");
       QFile wheat("D:/faz2/faz2/fils/number_of_wheat.txt");
       QFile cron("D:/faz2/faz2/fils/number_of_cron.txt");
       QFile chicken_egg("D:/faz2/faz2/fils/number_of_chicken_egg.txt");
       QFile chicken_mat("D:/faz2/faz2/fils/number_of_chicken_mat.txt");
       QFile cow_mat("D:/faz2/faz2/fils/number_of_cow_mat.txt");
       QFile cow_milk("D:/faz2/faz2/fils/number_of_cow_milk.txt");
       QFile sheep_milk("D:/faz2/faz2/fils/number_of_sheep_milk.txt");
       QFile sheep_mat("D:/faz2/faz2/fils/number_of_sheep_milk.txt");
       QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
       QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
       QFile baskets("D:/faz2/faz2/fils/basket.txt");


       QTextStream stream(&chicken);
       QTextStream out(&file);
       QTextStream out2(&cow);
       QTextStream out3(&sheep);
       QTextStream out4(&worker);
       QTextStream out5(&land);
       QTextStream out6(&wheat);
       QTextStream out7(&cron);
       QTextStream out8(&chicken_egg);
       QTextStream out9(&chicken_mat);
       QTextStream out10(&cow_mat);
       QTextStream out11(&cow_milk);
       QTextStream out12(&sheep_milk);
       QTextStream out13(&sheep_mat);
       QTextStream out14(&workerlan);
       QTextStream out15(&cultivation);
       QTextStream out16(&baskets);

       int coin = 100;
       if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
           out<<coin;
           file.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
           ui->pushButton->setEnabled(false);
       }
       int number_of_chicken = 0;
       if(chicken.open(QIODevice::WriteOnly | QIODevice::Text)){
           stream << number_of_chicken;
           chicken.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_cow = 0;
       if(cow.open(QIODevice::WriteOnly | QIODevice::Text)){
           out2 << number_of_cow;
           cow.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_sheep = 0;
       if(sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
           out3 << number_of_sheep;
           sheep.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_worker = 1;
       if(worker.open(QIODevice::WriteOnly | QIODevice::Text)){
           out4 << number_of_worker;
           worker.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_land = 1;
       if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
           out5 << number_of_land;
           land.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_wheat = 0;
       if(wheat.open(QIODevice::WriteOnly | QIODevice::Text)){
           out6 << number_of_wheat;
           wheat.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_cron = 0;
       if(cron.open(QIODevice::WriteOnly | QIODevice::Text)){
           out7 << number_of_cron;
           cron.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_chicken_egg = 0;
       if(chicken_egg.open(QIODevice::WriteOnly | QIODevice::Text)){
           out8 << number_of_chicken_egg;
           chicken_egg.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_chicken_mat = 0;
       if(chicken_mat.open(QIODevice::WriteOnly | QIODevice::Text)){
           out9 << number_of_chicken_mat;
           chicken_mat.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_cow_mat = 0;
       if(cow_mat.open(QIODevice::WriteOnly | QIODevice::Text)){
           out10 << number_of_cow_mat;
           cow_mat.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_cow_milk = 0;
       if(cow_milk.open(QIODevice::WriteOnly | QIODevice::Text)){
           out11 << number_of_cow_milk;
           cow_milk.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_sheep_milk = 0;
       if(sheep_milk.open(QIODevice::WriteOnly | QIODevice::Text)){
           out12 << number_of_sheep_milk;
           sheep_milk.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int number_of_sheep_mat = 0;
       if(sheep_mat.open(QIODevice::WriteOnly | QIODevice::Text)){
           out13 << number_of_sheep_mat;
           sheep_mat.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int workerlans = 0;
       if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
           out14 << workerlans;
           workerlan.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       QString cultivations = "0";
       if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
           out15 << cultivations;
           cultivation.close();
       }else{
           QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
       }
       int basketss = 0;
       QString bask = "D:/faz2/faz2/fils/basket.txt";
       outfil(bask,basketss);

       int sheeplan=0;
       QString seeplan="D:/faz2/faz2/fils/sheeplan.txt";
       outfil(seeplan,sheeplan);

       int chickenlan=0;
       QString chickenland="D:/faz2/faz2/fils/chickenland.txt";
       outfil(chickenland,chickenlan);

       int cowlan=0;
       QString cowland="D:/faz2/faz2/fils/cowland.txt";
       outfil(cowland,cowlan);

}


void page2::connct_timers(){
    QTimer *cow;
    cow= new QTimer(this);
    connect(cow,&QTimer::timeout,this,&page2::Cow_push1);
    connect(cow,&QTimer::timeout,this,&page2::Cow_push2);
    connect(cow,&QTimer::timeout,this,&page2::Cow_push3);
    QTimer *cow2;
    cow2= new QTimer(this);
    connect(cow2,&QTimer::timeout,this,&page2::Cow_push4);
    connect(cow2,&QTimer::timeout,this,&page2::Cow_push5);
    connect(cow2,&QTimer::timeout,this,&page2::Cow_push6);
    QTimer *cow3;
    cow3= new QTimer(this);
    connect(cow3,&QTimer::timeout,this,&page2::Cow_push7);
    connect(cow3,&QTimer::timeout,this,&page2::Cow_push8);
    connect(cow3,&QTimer::timeout,this,&page2::Cow_push9);
    QTimer *cow4;
    cow4= new QTimer(this);
    connect(cow4,&QTimer::timeout,this,&page2::Cow_push10);
    connect(cow4,&QTimer::timeout,this,&page2::Cow_push11);
    connect(cow4,&QTimer::timeout,this,&page2::Cow_push12);
    QTimer *cow5;
    cow5= new QTimer(this);
    connect(cow5,&QTimer::timeout,this,&page2::Cow_push13);
    connect(cow5,&QTimer::timeout,this,&page2::Cow_push14);
    cow->start(1000);
    cow2->start(1000);
    cow3->start(1000);
    cow4->start(1000);
    cow5->start(1000);



    QTimer *corn;
    corn = new QTimer(this);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push1);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push2);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push3);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push4);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push5);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push6);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push7);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push8);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push9);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push10);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push11);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push12);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push13);
    connect(corn,&QTimer::timeout,this,&page2::Corn_push14);

    corn->start(1000);

    QTimer *wheat;
    wheat = new QTimer(this);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push1);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push2);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push3);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push4);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push5);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push6);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push7);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push8);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push9);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push10);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push11);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push12);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push13);
    connect(wheat,&QTimer::timeout,this,&page2::Wheat_push14);


    wheat->start(1000);

    QTimer *chicken;
    chicken = new QTimer(this);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push1);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push2);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push3);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push4);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push5);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push6);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push7);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push8);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push9);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push10);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push11);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push12);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push13);
    connect(chicken,&QTimer::timeout,this,&page2::Chickeen_push14);


    chicken->start(1000);

    QTimer *sheep;
    sheep = new QTimer(this);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push1);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push2);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push3);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push4);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push5);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push6);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push7);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push8);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push9);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push10);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push11);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push12);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push13);
    connect(sheep,&QTimer::timeout,this,&page2::Sheep_push14);


    sheep->start(1000);
}


void page2::basketss(int pric)
{
    QFile file("D:/faz2/faz2/fils/coin.txt");
    QTextStream in(&file);
    QTextStream out(&file);
    QTextStream out2(&file);

    int coin = incoin();
    coin = coin + pric;
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
       out << coin;
       file.close();
   }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
   }

}


void page2::outcoin(int coin)
{

        QFile file("D:/faz2/faz2/fils/coin.txt");
        QTextStream out(&file);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            out<<coin;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
}


void page2::outfil(QString fils , int coin)
{
        QFile file(fils);
        QTextStream out(&file);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            out<<coin;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
}



int page2::incoin()
{
        int coin=0;
        QFile file("D:/faz2/faz2/fils/coin.txt");
        QTextStream in(&file);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            in >>coin;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        return coin;
}


int page2::infile(QString fils)
{
        int num=0;
        QFile file(fils);
        QTextStream in(&file);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            in >> num;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        return num;
}


void page2::updateTime()
{

    static int seconds = 0;
    seconds++;
    static int players=0;
    QFile player("D:/faz2/faz2/fils/number_of_players.txt");
    QTextStream stream1(&player);
    if(player.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> players;
        player.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    if (seconds == 180 && play<=players)                                                    // check if 3 minutes have passed
    {
        seconds = 0;
        elapsedTimer.restart();
        QString message = QString("Your turn is over").arg(play);
        QMessageBox::information(this,"Finsh",message);
        QString Username;
        QSqlDatabase database;
        database=QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("d:///database.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
        if(database.open()){
            QSqlQuery qury;
            QString pric =  QString::number(play);
            if(qury.exec("SELECT Username FROM Loginpaigah WHERE number='"+pric+"' ")){
                if(qury.next()){
                    Username = qury.value(0).toString();
                }
            }
            database.close();
        }else {
          qDebug() << "failed db.";
        }
        QSqlDatabase score;
        int coin = incoin();
        QString coins=QString::number(coin);
        QString numbr=QString::number(play);
        score =QSqlDatabase::addDatabase("QSQLITE");
        score.setDatabaseName("d:///score.db");                                           //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
        score.open();
        score.exec("INSERT INTO username(UserName,Score,number)VALUES('"+Username+"','"+coins+"','"+numbr+"')");
        score.close();

        play++;
        refresh();

    }else if (play>players && pos==0){
        QString Username[10];
        QString scor;
        int scr[10];

        QSqlDatabase scores;
        scores=QSqlDatabase::addDatabase("QSQLITE");
        scores.setDatabaseName("d:///score.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
        for(int i = 0; i < play ; i++){
        if(scores.open()){
            QSqlQuery qury;
            QString pric =  QString::number(i);
            if(qury.exec("SELECT Username FROM username WHERE number='"+pric+"' ")){
                if(qury.next()){
                    Username[i] = qury.value(0).toString();
                }
            }
            scores.close();
        }else {
          qDebug() << "failed db.";
        }

        if(scores.open()){
            QSqlQuery qury;
            QString pric =  QString::number(i);
            if(qury.exec("SELECT Score FROM username WHERE number='"+pric+"' ")){
                if(qury.next()){
                    scor = qury.value(0).toString();
                    scr[i]=scor.toInt();
                }
            }
            scores.close();
        }else {
          qDebug() << "failed db.";
        }
        }
        for(int i = 0; i < play-1 ; ++i){
            for(int j = 0; j< play-i-1; ++j){
                if (scr[j]<scr[j+1]){
                    int tmp = scr[j];
                    QString tp = Username[j];
                    scr[j]=scr[j+1];
                    Username[j]=Username[j+1];
                    scr[j+1]=tmp;
                    Username[j+1]=tp;
                }
            }
            QSqlDatabase score;
            pos=1;
            QString coins=QString::number(scr[i]);
            QString numbr=QString::number(i);
            score =QSqlDatabase::addDatabase("QSQLITE");
            score.setDatabaseName("d:///scoretartib.db");                                           //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
            score.open();
            score.exec("INSERT INTO username(UserName,Score)VALUES('"+Username[i]+"','"+coins+"')");
            score.close();

        }
        finish* FINISH = new finish();
        FINISH->show();
    }
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    ui->lcdNumber->display(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(remainingSeconds, 2, 10, QChar('0')));

    int kill=0;
    QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
    QTextStream stream15(&kill_sheeps);
    if(kill_sheeps.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream15 >> kill;
        kill_sheeps.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    static int j;
    if(kill==1){
        j=1;
        while(j==1){
            int rand=qrand()%14+1;
            for (int i=1;i<=14;i++){
                if(connct_Sheep[i]==1){
                    kill_Sheep[i]=2;

                }
            }
            if (kill_Sheep[rand]==2){
               kill_Sheep[rand]=1;
               j=0;
            }
        }
    }



    int kill_chick=0;
    QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
    QTextStream stream14(&kill_chickens);
    if(kill_chickens.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream14 >> kill_chick;
        kill_chickens.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    static int i;
    if(kill_chick==1){
        i=1;
        while(i==1){
            int rand=qrand()%14+1;
            for (int i=1;i<=14;i++){
                if(connct_chicken[i]==1){
                    kill_chicken[i]=2;
                }
            }
            if (kill_chicken[rand]==2){
               kill_chicken[rand]=1;
               i=0;
            }
        }
    }


    int kill_coww=0;
    QFile kill_cows("D:/faz2/faz2/fils/kill_cow.txt");
    QTextStream stream13(&kill_cows);
    if(kill_cows.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream13 >> kill_coww;
        kill_cows.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    static int k;
    if(kill_coww==1){
        k=1;
        while(k==1){
            int rand=qrand()%14+1;
            for (int i=1;i<=14;i++){
                if(connct_cow[i]==1){
                    kill_cow[i]=2;
                }
            }
            if (kill_cow[rand]==2){
               kill_cow[rand]=1;
               k=0;
            }
        }
    }


    QFile file("D:/faz2/faz2/fils/coin.txt");
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QFile worklan("D:/faz2/faz2/fils/workerlan.txt");
    QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");
    QFile wheat("D:/faz2/faz2/fils/number_of_wheat.txt");
    QFile corn("D:/faz2/faz2/fils/number_of_cron.txt");
    QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");
    QFile chicken("D:/faz2/faz2/fils/number_of_chicken.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    worker.open(QIODevice::ReadOnly | QIODevice::Text);
    land.open(QIODevice::ReadOnly | QIODevice::Text);
    cow.open(QIODevice::ReadOnly | QIODevice::Text);
    sheep.open(QIODevice::ReadOnly | QIODevice::Text);
    chicken.open(QIODevice::ReadOnly | QIODevice::Text);
    corn.open(QIODevice::ReadOnly | QIODevice::Text);
    wheat.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QTextStream stream(&worker);
    QTextStream in2(&land);
    QTextStream stream4(&cow);
    QTextStream stream5(&sheep);
    QTextStream stream6(&chicken);
    QTextStream stream7(&corn);
    QTextStream stream9(&wheat);

    int number_of_land;
    int number_of_cow;
    int coin;
    int number_of_wheat;
    int number_of_chicken;
    int number_of_corn;
    int number_of_sheep;

    int number_of_worker;
    in >> coin;
    stream >> number_of_worker;
    stream4 >> number_of_cow;
    in2 >> number_of_land;
    stream6 >> number_of_chicken;
    stream5 >> number_of_sheep;
    stream7 >> number_of_corn;
    stream9 >> number_of_wheat;


    file.close();
    worker.close();
    land.close();
    cow.close();
    sheep.close();
    chicken.close();
    corn.close();
    wheat.close();


    ui->lineEdit_coin->setText(" = " + QString::number(coin));
    ui->lineEdit_worker->setText(" = " + QString::number(number_of_worker));
    ui->lineEdit_land->setText(" = " + QString::number(number_of_land));
    ui->lineEdit_cow->setText(" = " + QString::number(number_of_cow));
    ui->label_chicken->setText(" = " + QString::number(number_of_chicken));
    ui->label_sheep->setText(" = " + QString::number(number_of_sheep));
    ui->label_corn->setText(" = " + QString::number(number_of_corn));
    ui->label_wheat->setText(" = " + QString::number(number_of_wheat));


}








page2::~page2()
{
    delete ui;
}

//void time_land::tab(){

//}


void page2::on_pushButton_Butcher_clicked()
{
    Butcher* BUTCHER = new Butcher();
    BUTCHER->show();
}



void page2::on_pushButton_3_clicked()
{
    shop* SHOP = new shop();
    SHOP->show();

}


void page2::on_pushButton__clicked()
{
    land* LAND = new land();
    LAND->show();

}


void page2::on_pushButton_2_clicked()
{
    land* LAND = new land();
    LAND->show();
}


void page2::on_pushButton_clicked()
{
    land* LAND = new land();
    LAND->show();

}


void page2::on_pushButton_6_clicked()
{
    sheep* SHEEP = new sheep();
    SHEEP ->show();
}


void page2::on_pushButton_1_clicked()
{
    cow* COW = new cow();
    COW ->show();
}


void page2::on_pushButton_4_clicked()
{
    hous* HOUS = new hous();
    HOUS ->show();
}


void page2::on_pushButton_8_clicked()
{
    chicken* CHICKEN = new chicken();
    CHICKEN ->show();
}


void page2::on_pushButton_10_clicked()
{
    worker* WORKER = new worker();
    WORKER ->show();
}


void page2::on_pushButton_5_clicked()
{
    land* LAND = new land();
    LAND->show();
}


void page2::on_pushButton_basket_clicked()
{
    ui->pushButton_basket->hide();
    ui->label_milk->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    if(Cultivations[1] == "corn" ){
          ui->pushButton_7->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_1->hide();
        ui->pushButton_7->setStyleSheet("");
        ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[1] == "wheat" ){
        ui->pushButton_7->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_1->hide();
        ui->pushButton_7->setStyleSheet("");
        ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[1] == "cow" ){
        basketss(5);
        connct_cow[1]=1;
    }
    if(Cultivations[1] == "sheep" ){
        basketss(3);
        connct_Sheep[1]=1;
    }
    if(Cultivations[1] == "chicken" ){
        basketss(3);
        connct_chicken[1]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push1(){
    if(connct_wheat[1]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_1->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[1]="wheat";
                ui->pushButton_7->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_1->setMovie(movie);
                movie->start();
                ui->label_worker_1->show();
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket->show();
                seconds1 = 0;
                connct_wheat[1]=0;
                cultivations = "0";
                ui->label_timer_1->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push1(){
    if(connct_corn[1]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_1->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[1]="corn";
                ui->pushButton_7->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_1->setMovie(movie);
                movie->start();
                ui->label_worker_1->show();
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket->show();
                seconds1 = 0;
                connct_corn[1]=0;
                cultivations = "0";
                ui->label_timer_1->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push1(){
    if(connct_cow[1]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_1->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[1]="cow";
                ui->pushButton_7->setEnabled(false);
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow->show();
                ui->label_cow->setStyleSheet("");
                ui->label_cow->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_1->setMovie(movie);
                movie->start();
                ui->label_worker_1->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket->show();
                 ui->label_milk->show();
                 ui->label_milk->setStyleSheet("");
                 ui->label_milk->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[1]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[1]==1){
                ui->pushButton_7->setEnabled(true);
                kill_cow[1]=0;
                connct_cow[1]=0;
                workerlans--;
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk->hide();
                ui->label_worker_1->hide();
                ui->label_cow->hide();
                ui->pushButton_basket->hide();
                ui->label_timer_1->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Chickeen_push1(){
    if(connct_chicken[1]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_1->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[1]="chicken";
                ui->pushButton_7->setEnabled(false);
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow->show();
                ui->label_cow->setStyleSheet("");
                ui->label_cow->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_1->setMovie(movie);
                movie->start();
                ui->label_worker_1->show();

            }
            if (seconds5 == 20 ){

                 ui->pushButton_basket->show();
                 ui->label_milk->show();
                 ui->label_milk->setStyleSheet("");
                 ui->label_milk->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[1]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[1]==1){
                ui->pushButton_7->setEnabled(true);
                kill_chicken[1]=0;
                connct_chicken[1]=0;
                workerlans--;
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk->hide();
                ui->label_worker_1->hide();
                ui->label_cow->hide();
                ui->pushButton_basket->hide();
                ui->label_timer_1->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }

            }
    }
}


void page2::Sheep_push1(){
    if(connct_Sheep[1]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_1->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[1]="sheep";
                ui->pushButton_7->setEnabled(false);
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow->show();
                ui->label_cow->setStyleSheet("");
                ui->label_cow->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_1->setMovie(movie);
                movie->start();
                ui->label_worker_1->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket->show();
                 ui->label_milk->show();
                 ui->label_milk->setStyleSheet("");
                 ui->label_milk->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[1]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[1]==1){
                ui->pushButton_7->setEnabled(true);
                kill_Sheep[1]=0;
                connct_Sheep[1]=0;
                workerlans--;
                ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk->hide();
                ui->label_worker_1->hide();
                ui->label_cow->hide();
                ui->pushButton_basket->hide();
                ui->label_timer_1->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::on_pushButton_7_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[1]=1;
    }
    else if(cultivation=="corn"){
        connct_corn[1]=1;
    }
    else if(cultivation=="cow"){
        connct_cow[1]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[1]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[1]=1;
    }

    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream2 << cultivation;
        cultivations.close();
     }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
     }

}
void page2::on_pushButton_basket_2_clicked()
{
    ui->pushButton_basket_2->hide();
    ui->label_milk_2->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    if(Cultivations[2]== "corn" ){
          ui->pushButton_9->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_2->hide();
        ui->pushButton_9->setStyleSheet("");
        ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[2] == "wheat" ){
        ui->pushButton_9->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_2->hide();
        ui->pushButton_9->setStyleSheet("");
        ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[2] == "cow" ){
        basketss(5);
        connct_cow[2]=1;

    }
    if(Cultivations[2] == "sheep" ){
        basketss(3);
        connct_Sheep[2]=1;

    }
    if(Cultivations[2] == "chicken" ){
        basketss(3);
        connct_chicken[2]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}

void page2::Wheat_push2(){
    if(connct_wheat[2]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_2->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[2]="wheat";
                ui->pushButton_9->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_2->setMovie(movie);
                movie->start();
                ui->label_worker_2->show();
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_2->show();
                seconds1 = 0;
                connct_wheat[2]=0;
                cultivations = "0";
                ui->label_timer_2->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}

void page2::Corn_push2(){
    if(connct_corn[2]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_2->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[2]="corn";
                ui->pushButton_9->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_2->setMovie(movie);
                movie->start();
                ui->label_worker_2->show();
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_2->show();
                seconds1 = 0;
                connct_corn[2]=0;
                cultivations = "0";
                ui->label_timer_2->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push2(){
    if(connct_cow[2]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_2->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[2]="cow";
                ui->pushButton_9->setEnabled(false);
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_2->show();
                ui->label_cow_2->setStyleSheet("");
                ui->label_cow_2->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_2->setMovie(movie);
                movie->start();
                ui->label_worker_2->show();
            }
            if (seconds5 == 20 ){

                 ui->pushButton_basket_2->show();
                 ui->label_milk_2->show();
                 ui->label_milk_2->setStyleSheet("");
                 ui->label_milk_2->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[2]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[2]==1){
                ui->pushButton_9->setEnabled(true);
                kill_cow[2]=0;
                connct_cow[2]=0;
                workerlans--;
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_2->hide();
                ui->label_worker_2->hide();
                ui->label_cow_2->hide();
                ui->pushButton_basket_2->hide();
                ui->label_timer_2->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push2(){
    if(connct_chicken[2]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_2->setText(QString::number(seconds5));

            if(seconds5 == 1){
                Cultivations[2]="chicken";
                ui->pushButton_9->setEnabled(false);
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_2->show();
                ui->label_cow_2->setStyleSheet("");
                ui->label_cow_2->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_2->setMovie(movie);
                movie->start();
                ui->label_worker_2->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_2->show();
                 ui->label_milk_2->show();
                 ui->label_milk_2->setStyleSheet("");
                 ui->label_milk_2->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_chicken[1]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[2]==1){
                ui->pushButton_9->setEnabled(true);
                kill_chicken[2]=0;
                connct_chicken[2]=0;
                workerlans--;
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_2->hide();
                ui->label_worker_2->hide();
                ui->label_cow_2->hide();
                ui->pushButton_basket_2->hide();
                ui->label_timer_2->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push2(){
    if(connct_Sheep[2]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_2->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[2]="sheep";
                ui->pushButton_9->setEnabled(false);
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_2->show();
                ui->label_cow_2->setStyleSheet("");
                ui->label_cow_2->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_2->setMovie(movie);
                movie->start();
                ui->label_worker_2->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_2->show();
                 ui->label_milk_2->show();
                 ui->label_milk_2->setStyleSheet("");
                 ui->label_milk_2->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[2]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[2]==1){
                ui->pushButton_9->setEnabled(true);
                kill_Sheep[2]=0;
                connct_Sheep[2]=0;
                workerlans--;
                ui->pushButton_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_2->hide();
                ui->label_worker_2->hide();
                ui->label_cow_2->hide();
                ui->pushButton_basket_2->hide();
                ui->label_timer_2->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::on_pushButton_9_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[2]=1;
    }else if(cultivation=="corn"){
        connct_corn[2]=1;

    }else if(cultivation=="cow"){
        connct_cow[2]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[2]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[2]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::on_pushButton_basket_3_clicked()
{
    ui->pushButton_basket_3->hide();
    ui->label_milk_3->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[3] == "corn" ){
          ui->pushButton_13->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_3->hide();
        ui->pushButton_13->setStyleSheet("");
        ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[3] == "wheat" ){
        ui->pushButton_13->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_3->hide();
        ui->pushButton_13->setStyleSheet("");
        ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[3] == "cow" ){
        basketss(5);
        connct_cow[3]=1;
    }
    if(Cultivations[3] == "sheep" ){
        basketss(3);
        connct_Sheep[3]=1;
    }
    if(Cultivations[3] == "chicken" ){
        basketss(3);
        connct_chicken[3]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push3(){
    if(connct_wheat[3]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_3->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[3]="wheat";
                ui->pushButton_13->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_3->setMovie(movie);
                movie->start();
                ui->label_worker_3->show();
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_3->show();
                seconds1 = 0;
                connct_wheat[3]=0;
                cultivations = "0";
                ui->label_timer_3->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push3(){
    if(connct_corn[3]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_3->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[3]="corn";
                ui->pushButton_13->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_3->setMovie(movie);
                movie->start();
                ui->label_worker_3->show();
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_3->show();
                seconds1 = 0;
                connct_corn[3]=0;
                cultivations = "0";
                ui->label_timer_3->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push3(){
    if(connct_cow[3]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_3->setText(QString::number(seconds5));

            if(seconds5 == 1){
                Cultivations[3]="cow";
                ui->pushButton_13->setEnabled(false);
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_3->show();
                ui->label_cow_3->setStyleSheet("");
                ui->label_cow_3->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_3->setMovie(movie);
                movie->start();
                ui->label_worker_3->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_3->show();
                 ui->label_milk_3->show();
                 ui->label_milk_3->setStyleSheet("");
                 ui->label_milk_3->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[3]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[3]==1){
                ui->pushButton_13->setEnabled(true);
                kill_cow[3]=0;
                connct_cow[3]=0;
                workerlans--;
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_3->hide();
                ui->label_worker_3->hide();
                ui->label_cow_3->hide();
                ui->pushButton_basket_3->hide();
                ui->label_timer_3->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Chickeen_push3(){
    if(connct_chicken[3]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_3->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[3]="chicken";
                ui->pushButton_13->setEnabled(false);
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_3->show();
                ui->label_cow_3->setStyleSheet("");
                ui->label_cow_3->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_3->setMovie(movie);
                movie->start();
                ui->label_worker_3->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_3->show();
                 ui->label_milk_3->show();
                 ui->label_milk_3->setStyleSheet("");
                 ui->label_milk_3->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[3]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[3]==1){
                ui->pushButton_13->setEnabled(true);
                kill_chicken[3]=0;
                connct_chicken[3]=0;
                workerlans--;
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_3->hide();
                ui->label_worker_3->hide();
                ui->label_cow_3->hide();
                ui->pushButton_basket_3->hide();
                ui->label_timer_3->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push3(){
    if(connct_Sheep[3]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_3->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[3]="sheep";
                ui->pushButton_13->setEnabled(false);
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_3->show();
                ui->label_cow_3->setStyleSheet("");
                ui->label_cow_3->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_3->setMovie(movie);
                movie->start();
                ui->label_worker_3->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_3->show();
                 ui->label_milk_3->show();
                 ui->label_milk_3->setStyleSheet("");
                 ui->label_milk_3->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[3]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[3]==1){
                ui->pushButton_13->setEnabled(true);
                kill_Sheep[3]=0;
                connct_Sheep[3]=0;
                workerlans--;
                ui->pushButton_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_3->hide();
                ui->label_worker_3->hide();
                ui->label_cow_3->hide();
                ui->pushButton_basket_3->hide();
                ui->label_timer_3->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::on_pushButton_13_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[3]=1;
    }else if(cultivation=="corn"){
        connct_corn[3]=1;

    }else if(cultivation=="cow"){
        connct_cow[3]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[3]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[3]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::on_pushButton_basket_4_clicked()
{
    ui->pushButton_basket_4->hide();
    ui->label_milk_4->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[4] == "corn" ){
          ui->pushButton_14->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_4->hide();
        ui->pushButton_14->setStyleSheet("");
        ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[4] == "wheat" ){
        ui->pushButton_14->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_4->hide();
        ui->pushButton_14->setStyleSheet("");
        ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[4] == "cow" ){
        basketss(5);
        connct_cow[4]=1;
    }
    if(Cultivations[4] == "sheep" ){
        basketss(3);
        connct_Sheep[4]=1;
    }
    if(Cultivations[4] == "chicken" ){
        basketss(3);
        connct_chicken[4]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push4(){
    if(connct_wheat[4]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_4->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[4]="wheat";
                ui->pushButton_14->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_4->setMovie(movie);
                movie->start();
                ui->label_worker_4->show();
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_4->show();
                seconds1 = 0;
                connct_wheat[4]=0;
                cultivations = "0";
                ui->label_timer_4->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push4(){
    if(connct_corn[4]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_4->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[4]="corn";
                ui->pushButton_14->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_4->setMovie(movie);
                movie->start();
                ui->label_worker_4->show();
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_4->show();
                seconds1 = 0;
                connct_corn[4]=0;
                cultivations = "0";
                ui->label_timer_4->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push4(){
    if(connct_cow[4]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_4->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[4]="cow";
                ui->pushButton_14->setEnabled(false);
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_4->show();
                ui->label_cow_4->setStyleSheet("");
                ui->label_cow_4->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_4->setMovie(movie);
                movie->start();
                ui->label_worker_4->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_4->show();
                 ui->label_milk_4->show();
                 ui->label_milk_4->setStyleSheet("");
                 ui->label_milk_4->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[4]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[4]==1){
                ui->pushButton_14->setEnabled(true);
                kill_cow[4]=0;
                connct_cow[4]=0;
                workerlans--;
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_4->hide();
                ui->label_worker_4->hide();
                ui->label_cow_4->hide();
                ui->pushButton_basket_4->hide();
                ui->label_timer_4->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }


    }
}


void page2::Chickeen_push4(){
    if(connct_chicken[4]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_4->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[4]="chicken";
                ui->pushButton_14->setEnabled(false);
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_4->show();
                ui->label_cow_4->setStyleSheet("");
                ui->label_cow_4->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_4->setMovie(movie);
                movie->start();
                ui->label_worker_4->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_4->show();
                 ui->label_milk_4->show();
                 ui->label_milk_4->setStyleSheet("");
                 ui->label_milk_4->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[4]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[4]==1){
                ui->pushButton_14->setEnabled(true);
                kill_chicken[4]=0;
                connct_chicken[4]=0;
                workerlans--;
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_4->hide();
                ui->label_worker_4->hide();
                ui->label_cow_4->hide();
                ui->pushButton_basket_4->hide();
                ui->label_timer_4->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push4(){
    if(connct_Sheep[4]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_4->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[4]="sheep";
                ui->pushButton_14->setEnabled(false);
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_4->show();
                ui->label_cow_4->setStyleSheet("");
                ui->label_cow_4->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_4->setMovie(movie);
                movie->start();
                ui->label_worker_4->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_4->show();
                 ui->label_milk_4->show();
                 ui->label_milk_4->setStyleSheet("");
                 ui->label_milk_4->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[4]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[4]==1){
                ui->pushButton_14->setEnabled(true);
                kill_Sheep[4]=0;
                connct_Sheep[4]=0;
                workerlans--;
                ui->pushButton_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_4->hide();
                ui->label_worker_4->hide();
                ui->label_cow_4->hide();
                ui->pushButton_basket_4->hide();
                ui->label_timer_4->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::on_pushButton_14_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[4]=1;
    }
    else if(cultivation=="corn"){
        connct_corn[4]=1;

    }else if(cultivation=="cow"){
        connct_cow[4]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[4]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[4]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}



void page2::on_pushButton_basket_5_clicked()
{
    ui->pushButton_basket_5->hide();
    ui->label_milk_5->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[5] == "corn" ){
          ui->pushButton_15->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_5->hide();
        ui->pushButton_15->setStyleSheet("");
        ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[5] == "wheat" ){
        ui->pushButton_15->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_5->hide();
        ui->pushButton_15->setStyleSheet("");
        ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[5] == "cow" ){
        basketss(5);
        connct_cow[5]=1;
    }
    if(Cultivations[5] == "sheep" ){
        basketss(3);
        connct_Sheep[5]=1;
    }
    if(Cultivations[5] == "chicken" ){
        basketss(3);
        connct_chicken[5]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push5(){
    if(connct_wheat[5]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_5->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[5]="wheat";
                ui->pushButton_15->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_5->setMovie(movie);
                movie->start();
                ui->label_worker_5->show();
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_5->show();
                seconds1 = 0;
                connct_wheat[5]=0;
                cultivations = "0";
                ui->label_timer_5->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push5(){
    if(connct_corn[5]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_5->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[5]="corn";
                ui->pushButton_15->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_5->setMovie(movie);
                movie->start();
                ui->label_worker_5->show();
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_5->show();
                seconds1 = 0;
                connct_corn[5]=0;
                cultivations = "0";
                ui->label_timer_5->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push5(){
    if(connct_cow[5]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_5->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[5]="cow";
                ui->pushButton_15->setEnabled(false);
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_5->show();
                ui->label_cow_5->setStyleSheet("");
                ui->label_cow_5->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_5->setMovie(movie);
                movie->start();
                ui->label_worker_5->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_5->show();
                 ui->label_milk_5->show();
                 ui->label_milk_5->setStyleSheet("");
                 ui->label_milk_5->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[5]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[5]==1){
                ui->pushButton_15->setEnabled(true);
                kill_cow[5]=0;
                connct_cow[5]=0;
                workerlans--;
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_5->hide();
                ui->label_worker_5->hide();
                ui->label_cow_5->hide();
                ui->pushButton_basket_5->hide();
                ui->label_timer_5->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push5(){
    if(connct_chicken[5]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_5->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[5]="chicken";
                ui->pushButton_15->setEnabled(false);
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_5->show();
                ui->label_cow_5->setStyleSheet("");
                ui->label_cow_5->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_5->setMovie(movie);
                movie->start();
                ui->label_worker_5->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_5->show();
                 ui->label_milk_5->show();
                 ui->label_milk_5->setStyleSheet("");
                 ui->label_milk_5->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[5]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[5]==1){
                ui->pushButton_15->setEnabled(true);
                kill_chicken[5]=0;
                connct_chicken[5]=0;
                workerlans--;
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_5->hide();
                ui->label_worker_5->hide();
                ui->label_cow_5->hide();
                ui->pushButton_basket_5->hide();
                ui->label_timer_5->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }

            }
    }
}


void page2::Sheep_push5(){
    if(connct_Sheep[5]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_5->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[5]="sheep";
                ui->pushButton_15->setEnabled(false);
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_5->show();
                ui->label_cow_5->setStyleSheet("");
                ui->label_cow_5->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_5->setMovie(movie);
                movie->start();
                ui->label_worker_5->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_5->show();
                 ui->label_milk_5->show();
                 ui->label_milk_5->setStyleSheet("");
                 ui->label_milk_5->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[5]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[5]==1){
                ui->pushButton_15->setEnabled(true);
                kill_Sheep[5]=0;
                connct_Sheep[5]=0;
                workerlans--;
                ui->pushButton_15->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_5->hide();
                ui->label_worker_5->hide();
                ui->label_cow_5->hide();
                ui->pushButton_basket_5->hide();
                ui->label_timer_5->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }

            }
    }
}



void page2::on_pushButton_15_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[5]=1;
    }else if(cultivation=="corn"){
        connct_corn[5]=1;

    }else if(cultivation=="cow"){
        connct_cow[5]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[5]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[5]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}




void page2::on_pushButton_basket_6_clicked()
{
    ui->pushButton_basket_6->hide();
    ui->label_milk_6->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[6] == "corn" ){
          ui->pushButton_16->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_6->hide();
        ui->pushButton_16->setStyleSheet("");
        ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[6] == "wheat" ){
        ui->pushButton_16->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_6->hide();
        ui->pushButton_16->setStyleSheet("");
        ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[6] == "cow" ){
        basketss(5);
        connct_cow[6]=1;
    }
    if(Cultivations[6] == "sheep" ){
        basketss(3);
        connct_Sheep[6]=1;
    }
    if(Cultivations[6] == "chicken" ){
        basketss(3);
        connct_chicken[6]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push6(){
    if(connct_wheat[6]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_6->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[6]="wheat";
                ui->pushButton_16->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_6->setMovie(movie);
                movie->start();
                ui->label_worker_6->show();
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_6->show();
                seconds1 = 0;
                connct_wheat[6]=0;
                cultivations = "0";
                ui->label_timer_6->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push6(){
    if(connct_corn[6]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_6->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[6]="corn";
                ui->pushButton_16->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_6->setMovie(movie);
                movie->start();
                ui->label_worker_6->show();
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_6->show();
                seconds1 = 0;
                connct_corn[6]=0;
                cultivations = "0";
                ui->label_timer_6->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push6(){
    if(connct_cow[6]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_6->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[6]="cow";
                ui->pushButton_16->setEnabled(false);
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_6->show();
                ui->label_cow_6->setStyleSheet("");
                ui->label_cow_6->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_6->setMovie(movie);
                movie->start();
                ui->label_worker_6->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_6->show();
                 ui->label_milk_6->show();
                 ui->label_milk_6->setStyleSheet("");
                 ui->label_milk_6->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[6]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[6]==1){
                ui->pushButton_16->setEnabled(true);
                kill_cow[6]=0;
                connct_cow[6]=0;
                workerlans--;
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_6->hide();
                ui->label_worker_6->hide();
                ui->label_cow_6->hide();
                ui->pushButton_basket_6->hide();
                ui->label_timer_6->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push6(){
    if(connct_chicken[6]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_6->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[6]="chicken";
                ui->pushButton_16->setEnabled(false);
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_6->show();
                ui->label_cow_6->setStyleSheet("");
                ui->label_cow_6->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_6->setMovie(movie);
                movie->start();
                ui->label_worker_6->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_6->show();
                 ui->label_milk_6->show();
                 ui->label_milk_6->setStyleSheet("");
                 ui->label_milk_6->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[6]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[6]==1){
                ui->pushButton_16->setEnabled(true);
                kill_chicken[6]=0;
                connct_chicken[6]=0;
                workerlans--;
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_6->hide();
                ui->label_worker_6->hide();
                ui->label_cow_6->hide();
                ui->pushButton_basket_6->hide();
                ui->label_timer_6->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push6(){
    if(connct_Sheep[6]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_6->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[6]="sheep";
                ui->pushButton_16->setEnabled(false);
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_6->show();
                ui->label_cow_6->setStyleSheet("");
                ui->label_cow_6->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_6->setMovie(movie);
                movie->start();
                ui->label_worker_6->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_6->show();
                 ui->label_milk_6->show();
                 ui->label_milk_6->setStyleSheet("");
                 ui->label_milk_6->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[6]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[6]==1){
                ui->pushButton_16->setEnabled(true);
                kill_Sheep[6]=0;
                connct_Sheep[6]=0;
                workerlans--;
                ui->pushButton_16->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_6->hide();
                ui->label_worker_6->hide();
                ui->label_cow_6->hide();
                ui->pushButton_basket_6->hide();
                ui->label_timer_6->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }

            }
    }
}



void page2::on_pushButton_16_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[6]=1;
    }else if(cultivation=="corn"){
        connct_corn[6]=1;

    }else if(cultivation=="cow"){
        connct_cow[6]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[6]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[6]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::on_pushButton_basket_7_clicked()
{
    ui->pushButton_basket_7->hide();
    ui->label_milk_7->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[7] == "corn" ){
          ui->pushButton_17->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_7->hide();
        ui->pushButton_17->setStyleSheet("");
        ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[7] == "wheat" ){
        ui->pushButton_17->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_7->hide();
        ui->pushButton_17->setStyleSheet("");
        ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[7] == "cow" ){
        basketss(5);
        connct_cow[7]=1;
    }
    if(Cultivations[7] == "sheep" ){
        basketss(3);
        connct_Sheep[7]=1;
    }
    if(Cultivations[7] == "chicken" ){
        basketss(3);
        connct_chicken[7]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push7(){
    if(connct_wheat[7]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_7->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[7]="wheat";
                ui->pushButton_17->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_7->setMovie(movie);
                movie->start();
                ui->label_worker_7->show();
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_7->show();
                seconds1 = 0;
                connct_wheat[7]=0;
                cultivations = "0";
                ui->label_timer_7->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push7(){
    if(connct_corn[7]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_7->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[7]="corn";
                ui->pushButton_17->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_7->setMovie(movie);
                movie->start();
                ui->label_worker_7->show();
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_7->show();
                seconds1 = 0;
                connct_corn[7]=0;
                cultivations = "0";
                ui->label_timer_7->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push7(){
    if(connct_cow[7]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_7->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[7]="cow";
                ui->pushButton_17->setEnabled(false);
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_7->show();
                ui->label_cow_7->setStyleSheet("");
                ui->label_cow_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_7->setMovie(movie);
                movie->start();
                ui->label_worker_7->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_7->show();
                 ui->label_milk_7->show();
                 ui->label_milk_7->setStyleSheet("");
                 ui->label_milk_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[7]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[7]==1){
                ui->pushButton_17->setEnabled(true);
                kill_cow[7]=0;
                connct_cow[7]=0;
                workerlans--;
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_7->hide();
                ui->label_worker_7->hide();
                ui->label_cow_7->hide();
                ui->pushButton_basket_7->hide();
                ui->label_timer_7->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push7(){
    if(connct_chicken[7]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_7->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[7]="chicken";
                ui->pushButton_17->setEnabled(false);
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_7->show();
                ui->label_cow_7->setStyleSheet("");
                ui->label_cow_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_7->setMovie(movie);
                movie->start();
                ui->label_worker_7->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_7->show();
                 ui->label_milk_7->show();
                 ui->label_milk_7->setStyleSheet("");
                 ui->label_milk_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[7]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[7]==1){
                ui->pushButton_17->setEnabled(true);
                kill_chicken[7]=0;
                connct_chicken[7]=0;
                workerlans--;
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_7->hide();
                ui->label_worker_7->hide();
                ui->label_cow_7->hide();
                ui->pushButton_basket_7->hide();
                ui->label_timer_7->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push7(){
    if(connct_Sheep[7]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_7->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[7]="sheep";
                ui->pushButton_17->setEnabled(false);
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_7->show();
                ui->label_cow_7->setStyleSheet("");
                ui->label_cow_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_7->setMovie(movie);
                movie->start();
                ui->label_worker_7->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_7->show();
                 ui->label_milk_7->show();
                 ui->label_milk_7->setStyleSheet("");
                 ui->label_milk_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[7]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[7]==1){
                ui->pushButton_17->setEnabled(true);
                kill_Sheep[7]=0;
                connct_Sheep[7]=0;
                workerlans--;
                ui->pushButton_17->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_7->hide();
                ui->label_worker_7->hide();
                ui->label_cow_7->hide();
                ui->pushButton_basket_7->hide();
                ui->label_timer_7->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::on_pushButton_17_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[7]=1;
    }else if(cultivation=="corn"){
        connct_corn[7]=1;

    }else if(cultivation=="cow"){
        connct_cow[7]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[7]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[7]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}



void page2::on_pushButton_basket_9_clicked()
{
    ui->pushButton_basket_9->hide();
    ui->label_milk_9->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[9] == "corn" ){
          ui->pushButton_19->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_9->hide();
        ui->pushButton_19->setStyleSheet("");
        ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[9] == "wheat" ){
        ui->pushButton_19->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_9->hide();
        ui->pushButton_19->setStyleSheet("");
        ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[9] == "cow" ){
        basketss(5);
        connct_cow[9]=1;
    }
    if(Cultivations[9] == "sheep" ){
        basketss(3);
        connct_Sheep[9]=1;
    }
    if(Cultivations[9] == "chicken" ){
        basketss(3);
        connct_chicken[9]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push9(){
    if(connct_wheat[9]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_9->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[9]="wheat";
                ui->pushButton_19->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_9->setMovie(movie);
                movie->start();
                ui->label_worker_9->show();
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_9->show();
                seconds1 = 0;
                connct_wheat[9]=0;
                cultivations = "0";
                ui->label_timer_9->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push9(){
    if(connct_corn[9]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_9->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[9]="corn";
                ui->pushButton_19->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_9->setMovie(movie);
                movie->start();
                ui->label_worker_9->show();
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_9->show();
                seconds1 = 0;
                connct_corn[9]=0;
                cultivations = "0";
                ui->label_timer_9->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push9(){
    if(connct_cow[9]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_9->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[9]="cow";
                ui->pushButton_19->setEnabled(false);
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_9->show();
                ui->label_cow_9->setStyleSheet("");
                ui->label_cow_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_9->setMovie(movie);
                movie->start();
                ui->label_worker_9->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_9->show();
                 ui->label_milk_9->show();
                 ui->label_milk_9->setStyleSheet("");
                 ui->label_milk_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[9]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[9]==1){
                ui->pushButton_19->setEnabled(true);
                kill_cow[7]=0;
                connct_cow[9]=0;
                workerlans--;
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_9->hide();
                ui->label_worker_9->hide();
                ui->label_cow_9->hide();
                ui->pushButton_basket_9->hide();
                ui->label_timer_9->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }

            }

    }
}


void page2::Chickeen_push9(){
    if(connct_chicken[9]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_9->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[9]="chicken";
                ui->pushButton_19->setEnabled(false);
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_9->show();
                ui->label_cow_9->setStyleSheet("");
                ui->label_cow_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_9->setMovie(movie);
                movie->start();
                ui->label_worker_9->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_9->show();
                 ui->label_milk_9->show();
                 ui->label_milk_9->setStyleSheet("");
                 ui->label_milk_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[9]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[9]==1){
                ui->pushButton_19->setEnabled(true);
                kill_chicken[9]=0;
                connct_chicken[9]=0;
                workerlans--;
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_9->hide();
                ui->label_worker_9->hide();
                ui->label_cow_9->hide();
                ui->pushButton_basket_9->hide();
                ui->label_timer_9->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Sheep_push9(){
    if(connct_Sheep[9]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_9->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[9]="sheep";
                ui->pushButton_19->setEnabled(false);
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_9->show();
                ui->label_cow_9->setStyleSheet("");
                ui->label_cow_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_9->setMovie(movie);
                movie->start();
                ui->label_worker_9->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_9->show();
                 ui->label_milk_9->show();
                 ui->label_milk_9->setStyleSheet("");
                 ui->label_milk_9->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[9]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[9]==1){
                ui->pushButton_19->setEnabled(true);
                kill_Sheep[9]=0;
                connct_Sheep[9]=0;
                workerlans--;
                ui->pushButton_19->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_9->hide();
                ui->label_worker_9->hide();
                ui->label_cow_9->hide();
                ui->pushButton_basket_9->hide();
                ui->label_timer_9->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}



void page2::on_pushButton_19_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[9]=1;
    }else if(cultivation=="corn"){
        connct_corn[9]=1;

    }else if(cultivation=="cow"){
        connct_cow[9]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[9]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[9]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}




void page2::on_pushButton_basket_14_clicked()
{
    ui->pushButton_basket_14->hide();
    ui->label_milk_14->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[14] == "corn" ){
        ui->pushButton_24->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_14->hide();
        ui->pushButton_24->setStyleSheet("");
        ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[13] == "wheat" ){
        ui->pushButton_24->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_14->hide();
        ui->pushButton_24->setStyleSheet("");
        ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[14] == "cow" ){
        basketss(5);
        connct_cow[14]=1;
    }
    if(Cultivations[14] == "sheep" ){
        basketss(3);
        connct_Sheep[14]=1;
    }
    if(Cultivations[14] == "chicken" ){
        basketss(3);
        connct_chicken[14]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push14(){
    if(connct_wheat[14]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_14->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[14]="wheat";
                ui->pushButton_24->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_14->setMovie(movie);
                movie->start();
                ui->label_worker_14->show();
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_14->show();
                seconds1 = 0;
                connct_wheat[14]=0;
                cultivations = "0";
                ui->label_timer_14->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push14(){
    if(connct_corn[14]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_14->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[13]="corn";
                ui->pushButton_24->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_14->setMovie(movie);
                movie->start();
                ui->label_worker_14->show();
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 12){
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_14->show();
                seconds1 = 0;
                connct_corn[13]=0;
                cultivations = "0";
                ui->label_timer_14->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push14(){
    if(connct_cow[14]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_14->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[14]="cow";
                ui->pushButton_24->setEnabled(false);
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_14->show();
                ui->label_cow_14->setStyleSheet("");
                ui->label_cow_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_14->setMovie(movie);
                movie->start();
                ui->label_worker_14->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_14->show();
                 ui->label_milk_14->show();
                 ui->label_milk_14->setStyleSheet("");
                 ui->label_milk_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[14]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[14]==1){
                ui->pushButton_24->setEnabled(true);
                kill_cow[14]=0;
                connct_cow[14]=0;
                workerlans--;
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_14->hide();
                ui->label_worker_14->hide();
                ui->label_cow_14->hide();
                ui->pushButton_basket_14->hide();
                ui->label_timer_14->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push14(){
    if(connct_chicken[14]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_14->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[14]="chicken";
                ui->pushButton_24->setEnabled(false);
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_14->show();
                ui->label_cow_14->setStyleSheet("");
                ui->label_cow_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_14->setMovie(movie);
                movie->start();
                ui->label_worker_14->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_14->show();
                 ui->label_milk_14->show();
                 ui->label_milk_14->setStyleSheet("");
                 ui->label_milk_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[14]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[14]==1){
                ui->pushButton_24->setEnabled(true);
                kill_chicken[14]=0;
                connct_chicken[14]=0;
                workerlans--;
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_14->hide();
                ui->label_worker_14->hide();
                ui->label_cow_14->hide();
                ui->pushButton_basket_14->hide();
                ui->label_timer_14->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push14(){
    if(connct_Sheep[14]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_14->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[14]="sheep";
                ui->pushButton_24->setEnabled(false);
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_14->show();
                ui->label_cow_14->setStyleSheet("");
                ui->label_cow_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_14->setMovie(movie);
                movie->start();
                ui->label_worker_14->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_14->show();
                 ui->label_milk_14->show();
                 ui->label_milk_14->setStyleSheet("");
                 ui->label_milk_14->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[14]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[14]==1){
                ui->pushButton_24->setEnabled(true);
                kill_Sheep[14]=0;
                connct_Sheep[14]=0;
                workerlans--;
                ui->pushButton_24->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_14->hide();
                ui->label_worker_14->hide();
                ui->label_cow_14->hide();
                ui->pushButton_basket_14->hide();
                ui->label_timer_14->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }

            }
    }
}





void page2::on_pushButton_24_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[14]=1;
    }else if(cultivation=="corn"){
        connct_corn[14]=1;

    }else if(cultivation=="cow"){
        connct_cow[14]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[14]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[14]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}




void page2::on_pushButton_basket_13_clicked()
{
    ui->pushButton_basket_13->hide();
    ui->label_milk_13->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[13] == "corn" ){
          ui->pushButton_23->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_13->hide();
        ui->pushButton_23->setStyleSheet("");
        ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[13] == "wheat" ){
        ui->pushButton_23->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_13->hide();
        ui->pushButton_23->setStyleSheet("");
        ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[13] == "cow" ){
        basketss(5);
        connct_cow[13]=1;
    }
    if(Cultivations[13] == "sheep" ){
        basketss(3);
        connct_Sheep[13]=1;
    }
    if(Cultivations[13] == "chicken" ){
        basketss(3);
        connct_chicken[13]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push13(){
    if(connct_wheat[13]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_13->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[13]="wheat";
                ui->pushButton_23->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_13->setMovie(movie);
                movie->start();
                ui->label_worker_13->show();
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_13->show();
                seconds1 = 0;
                connct_wheat[13]=0;
                cultivations = "0";
                ui->label_timer_13->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push13(){
    if(connct_corn[13]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_13->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[13]="corn";
                ui->pushButton_23->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_13->setMovie(movie);
                movie->start();
                ui->label_worker_13->show();
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 12){
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_13->show();
                seconds1 = 0;
                connct_corn[13]=0;
                cultivations = "0";
                ui->label_timer_13->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push13(){
    if(connct_cow[13]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_13->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[13]="cow";
                ui->pushButton_23->setEnabled(false);
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_13->show();
                ui->label_cow_13->setStyleSheet("");
                ui->label_cow_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_13->setMovie(movie);
                movie->start();
                ui->label_worker_13->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_13->show();
                 ui->label_milk_13->show();
                 ui->label_milk_13->setStyleSheet("");
                 ui->label_milk_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[13]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[13]==1){
                ui->pushButton_23->setEnabled(true);
                kill_cow[13]=0;
                connct_cow[13]=0;
                workerlans--;
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_13->hide();
                ui->label_worker_13->hide();
                ui->label_cow_13->hide();
                ui->pushButton_basket_13->hide();
                ui->label_timer_13->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }

            }
    }
}


void page2::Chickeen_push13(){
    if(connct_chicken[13]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_13->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[13]="chicken";
                ui->pushButton_23->setEnabled(false);
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_13->show();
                ui->label_cow_13->setStyleSheet("");
                ui->label_cow_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_13->setMovie(movie);
                movie->start();
                ui->label_worker_13->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_13->show();
                 ui->label_milk_13->show();
                 ui->label_milk_13->setStyleSheet("");
                 ui->label_milk_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[13]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[13]==1){
                ui->pushButton_23->setEnabled(true);
                kill_chicken[13]=0;
                connct_chicken[13]=0;
                workerlans--;
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_13->hide();
                ui->label_worker_13->hide();
                ui->label_cow_13->hide();
                ui->pushButton_basket_13->hide();
                ui->label_timer_13->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push13(){
    if(connct_Sheep[13]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_13->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[13]="sheep";
                ui->pushButton_23->setEnabled(false);
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_13->show();
                ui->label_cow_13->setStyleSheet("");
                ui->label_cow_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_13->setMovie(movie);
                movie->start();
                ui->label_worker_13->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_13->show();
                 ui->label_milk_13->show();
                 ui->label_milk_13->setStyleSheet("");
                 ui->label_milk_13->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[13]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[13]==1){
                ui->pushButton_23->setEnabled(true);
                kill_Sheep[13]=0;
                connct_Sheep[13]=0;
                workerlans--;
                ui->pushButton_23->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_13->hide();
                ui->label_worker_13->hide();
                ui->label_cow_13->hide();
                ui->pushButton_basket_13->hide();
                ui->label_timer_13->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}




void page2::on_pushButton_23_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[13]=1;
    }else if(cultivation=="corn"){
        connct_corn[13]=1;

    }else if(cultivation=="cow"){
        connct_cow[13]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[13]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[13]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}






void page2::on_pushButton_basket_12_clicked()
{
    ui->pushButton_basket_12->hide();
    ui->label_milk_12->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[12] == "corn" ){
          ui->pushButton_22->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_12->hide();
        ui->pushButton_22->setStyleSheet("");
        ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[12] == "wheat" ){
        ui->pushButton_22->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_12->hide();
        ui->pushButton_22->setStyleSheet("");
        ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[12] == "cow" ){
        basketss(5);
        connct_cow[12]=1;
    }
    if(Cultivations[12] == "sheep" ){
        basketss(3);
        connct_Sheep[12]=1;
    }
    if(Cultivations[12] == "chicken" ){
        basketss(3);
        connct_chicken[12]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push12(){
    if(connct_wheat[12]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_12->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[12]="wheat";
                ui->pushButton_22->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_12->setMovie(movie);
                movie->start();
                ui->label_worker_12->show();
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_12->show();
                seconds1 = 0;
                connct_wheat[12]=0;
                cultivations = "0";
                ui->label_timer_12->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push12(){
    if(connct_corn[12]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_12->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[12]="corn";
                ui->pushButton_22->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_12->setMovie(movie);
                movie->start();
                ui->label_worker_12->show();
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 12){
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 22){
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_12->show();
                seconds1 = 0;
                connct_corn[12]=0;
                cultivations = "0";
                ui->label_timer_12->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push12(){
    if(connct_cow[12]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_12->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[12]="cow";
                ui->pushButton_22->setEnabled(false);
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_12->show();
                ui->label_cow_12->setStyleSheet("");
                ui->label_cow_12->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_12->setMovie(movie);
                movie->start();
                ui->label_worker_12->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_12->show();
                 ui->label_milk_12->show();
                 ui->label_milk_12->setStyleSheet("");
                 ui->label_milk_12->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[12]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[12]==1){
                ui->pushButton_22->setEnabled(true);
                kill_cow[12]=0;
                connct_cow[12]=0;
                workerlans--;
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_12->hide();
                ui->label_worker_12->hide();
                ui->label_cow_12->hide();
                ui->pushButton_basket_12->hide();
                ui->label_timer_12->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push12(){
    if(connct_chicken[12]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_12->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[12]="chicken";
                ui->pushButton_22->setEnabled(false);
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_12->show();
                ui->label_cow_12->setStyleSheet("");
                ui->label_cow_12->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_12->setMovie(movie);
                movie->start();
                ui->label_worker_12->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_12->show();
                 ui->label_milk_12->show();
                 ui->label_milk_12->setStyleSheet("");
                 ui->label_milk_12->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[12]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[12]==1){
                ui->pushButton_22->setEnabled(true);
                kill_chicken[12]=0;
                connct_chicken[12]=0;
                workerlans--;
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_12->hide();
                ui->label_worker_12->hide();
                ui->label_cow_12->hide();
                ui->pushButton_basket_12->hide();
                ui->label_timer_12->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push12(){
    if(connct_Sheep[12]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_12->setText(QString::number(seconds5));

            if(seconds5 == 1){
                Cultivations[12]="sheep";
                ui->pushButton_22->setEnabled(false);
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_12->show();
                ui->label_cow_12->setStyleSheet("");
                ui->label_cow_12->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_12->setMovie(movie);
                movie->start();
                ui->label_worker_12->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_12->show();
                 ui->label_milk_12->show();
                 ui->label_milk_12->setStyleSheet("");
                 ui->label_milk_12->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[12]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[12]==1){
                ui->pushButton_22->setEnabled(true);
                kill_Sheep[12]=0;
                connct_Sheep[12]=0;
                workerlans--;
                ui->pushButton_22->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_12->hide();
                ui->label_worker_12->hide();
                ui->label_cow_12->hide();
                ui->pushButton_basket_12->hide();
                ui->label_timer_12->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}






void page2::on_pushButton_22_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[12]=1;
    }else if(cultivation=="corn"){
        connct_corn[12]=1;

    }else if(cultivation=="cow"){
        connct_cow[12]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[12]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[12]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}




void page2::on_pushButton_basket_11_clicked()
{
    ui->pushButton_basket_11->hide();
    ui->label_milk_11->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[11] == "corn" ){
          ui->pushButton_21->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_11->hide();
        ui->pushButton_21->setStyleSheet("");
        ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[11] == "wheat" ){
        ui->pushButton_21->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_11->hide();
        ui->pushButton_21->setStyleSheet("");
        ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[11] == "cow" ){
        basketss(5);
        connct_cow[11]=1;
    }
    if(Cultivations[11] == "sheep" ){
        basketss(3);
        connct_Sheep[11]=1;
    }
    if(Cultivations[11] == "chicken" ){
        basketss(3);
        connct_chicken[11]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push11(){
    if(connct_wheat[11]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_11->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[11]="wheat";
                ui->pushButton_21->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_11->setMovie(movie);
                movie->start();
                ui->label_worker_11->show();
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_11->show();
                seconds1 = 0;
                connct_wheat[11]=0;
                cultivations = "0";
                ui->label_timer_11->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push11(){
    if(connct_corn[11]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_11->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[11]="corn";
                ui->pushButton_21->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_11->setMovie(movie);
                movie->start();
                ui->label_worker_11->show();
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_11->show();
                seconds1 = 0;
                connct_corn[11]=0;
                cultivations = "0";
                ui->label_timer_11->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push11(){
    if(connct_cow[11]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_11->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[11]="cow";
                ui->pushButton_21->setEnabled(false);
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_11->show();
                ui->label_cow_11->setStyleSheet("");
                ui->label_cow_11->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_11->setMovie(movie);
                movie->start();
                ui->label_worker_11->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_11->show();
                 ui->label_milk_11->show();
                 ui->label_milk_11->setStyleSheet("");
                 ui->label_milk_11->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[11]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[11]==1){
                ui->pushButton_21->setEnabled(true);
                kill_cow[11]=0;
                connct_cow[11]=0;
                workerlans--;
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_11->hide();
                ui->label_worker_11->hide();
                ui->label_cow_11->hide();
                ui->pushButton_basket_11->hide();
                ui->label_timer_11->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Chickeen_push11(){
    if(connct_chicken[11]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_11->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[11]="chicken";
                ui->pushButton_21->setEnabled(false);
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_11->show();
                ui->label_cow_11->setStyleSheet("");
                ui->label_cow_11->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_11->setMovie(movie);
                movie->start();
                ui->label_worker_11->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_11->show();
                 ui->label_milk_11->show();
                 ui->label_milk_11->setStyleSheet("");
                 ui->label_milk_11->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[11]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[11]==1){
                ui->pushButton_21->setEnabled(true);
                kill_chicken[11]=0;
                connct_chicken[11]=0;
                workerlans--;
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_11->hide();
                ui->label_worker_11->hide();
                ui->label_cow_11->hide();
                ui->pushButton_basket_11->hide();
                ui->label_timer_11->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push11(){
    if(connct_Sheep[11]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_11->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[11]="sheep";
                ui->pushButton_21->setEnabled(false);
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_11->show();
                ui->label_cow_11->setStyleSheet("");
                ui->label_cow_11->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_11->setMovie(movie);
                movie->start();
                ui->label_worker_11->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_11->show();
                 ui->label_milk_11->show();
                 ui->label_milk_11->setStyleSheet("");
                 ui->label_milk_11->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[11]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[11]==1){
                ui->pushButton_21->setEnabled(true);
                kill_Sheep[11]=0;
                connct_Sheep[11]=0;
                workerlans--;
                ui->pushButton_21->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_11->hide();
                ui->label_worker_11->hide();
                ui->label_cow_11->hide();
                ui->pushButton_basket_11->hide();
                ui->label_timer_11->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}




void page2::on_pushButton_21_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[11]=1;
    }else if(cultivation=="corn"){
        connct_corn[11]=1;

    }else if(cultivation=="cow"){
        connct_cow[11]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[11]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[11]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}




void page2::on_pushButton_basket_10_clicked()
{
    ui->pushButton_basket_10->hide();
    ui->label_milk_10->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[10] == "corn" ){
          ui->pushButton_20->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_10->hide();
        ui->pushButton_20->setStyleSheet("");
        ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[10] == "wheat" ){
        ui->pushButton_20->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_10->hide();
        ui->pushButton_20->setStyleSheet("");
        ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[10] == "cow" ){
        basketss(5);
        connct_cow[10]=1;
    }
    if(Cultivations[10] == "sheep" ){
        basketss(3);
        connct_Sheep[10]=1;
    }
    if(Cultivations[10] == "chicken" ){
        basketss(3);
        connct_chicken[10]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push10(){
    if(connct_wheat[10]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_10->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[10]="wheat";
                ui->pushButton_20->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_10->setMovie(movie);
                movie->start();
                ui->label_worker_10->show();
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_10->show();
                seconds1 = 0;
                connct_wheat[10]=0;
                cultivations = "0";
                ui->label_timer_10->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push10(){
    if(connct_corn[10]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_10->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[10]="corn";
                ui->pushButton_20->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_10->setMovie(movie);
                movie->start();
                ui->label_worker_10->show();
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_10->show();
                seconds1 = 0;
                connct_corn[10]=0;
                cultivations = "0";
                ui->label_timer_10->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push10(){
    if(connct_cow[10]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_10->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[10]="cow";
                ui->pushButton_20->setEnabled(false);
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_10->show();
                ui->label_cow_10->setStyleSheet("");
                ui->label_cow_10->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_10->setMovie(movie);
                movie->start();
                ui->label_worker_10->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_10->show();
                 ui->label_milk_10->show();
                 ui->label_milk_10->setStyleSheet("");
                 ui->label_milk_10->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[10]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[10]==1){
                ui->pushButton_20->setEnabled(true);
                kill_cow[10]=0;
                connct_cow[10]=0;
                workerlans--;
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_10->hide();
                ui->label_worker_10->hide();
                ui->label_cow_10->hide();
                ui->pushButton_basket_10->hide();
                ui->label_timer_10->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push10(){
    if(connct_chicken[10]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_10->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[10]="chicken";
                ui->pushButton_20->setEnabled(false);
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_10->show();
                ui->label_cow_10->setStyleSheet("");
                ui->label_cow_10->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_10->setMovie(movie);
                movie->start();
                ui->label_worker_10->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_10->show();
                 ui->label_milk_10->show();
                 ui->label_milk_10->setStyleSheet("");
                 ui->label_milk_10->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[10]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[10]==1){
                ui->pushButton_20->setEnabled(true);
                kill_chicken[10]=0;
                connct_chicken[10]=0;
                workerlans--;
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_10->hide();
                ui->label_worker_10->hide();
                ui->label_cow_10->hide();
                ui->pushButton_basket_10->hide();
                ui->label_timer_10->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push10(){
    if(connct_Sheep[10]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_10->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[10]="sheep";
                ui->pushButton_20->setEnabled(false);
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_10->show();
                ui->label_cow_10->setStyleSheet("");
                ui->label_cow_10->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_10->setMovie(movie);
                movie->start();
                ui->label_worker_10->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_10->show();
                 ui->label_milk_10->show();
                 ui->label_milk_10->setStyleSheet("");
                 ui->label_milk_10->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[10]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[10]==1){
                ui->pushButton_20->setEnabled(true);
                kill_Sheep[10]=0;
                connct_Sheep[10]=0;
                workerlans--;
                ui->pushButton_20->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_10->hide();
                ui->label_worker_10->hide();
                ui->label_cow_10->hide();
                ui->pushButton_basket_10->hide();
                ui->label_timer_10->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}




void page2::on_pushButton_20_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[10]=1;
    }else if(cultivation=="corn"){
        connct_corn[10]=1;

    }else if(cultivation=="cow"){
        connct_cow[10]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[10]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[10]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}




void page2::on_pushButton_basket_8_clicked()
{
    ui->pushButton_basket_8->hide();
    ui->label_milk_8->hide();
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    int workerlans=0;
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(Cultivations[8] == "corn" ){
          ui->pushButton_18->setEnabled(true);
        basketss(2);
        workerlans--;
        ui->label_worker_8->hide();
        ui->pushButton_18->setStyleSheet("");
        ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[8] == "wheat" ){
        ui->pushButton_18->setEnabled(true);
        basketss(3);
        workerlans--;
        ui->label_worker_8->hide();
        ui->pushButton_18->setStyleSheet("");
        ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
    }
    if(Cultivations[8] == "cow" ){
        basketss(5);
        connct_cow[8]=1;
    }
    if(Cultivations[8] == "sheep" ){
        basketss(3);
        connct_Sheep[8]=1;
    }
    if(Cultivations[8] == "chicken" ){
        basketss(3);
        connct_chicken[8]=1;

    }
    if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::Wheat_push8(){
    if(connct_wheat[8]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_8->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[8]="wheat";
                ui->pushButton_18->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_8->setMovie(movie);
                movie->start();
                ui->label_worker_8->show();
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 15){
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 25){
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
                ui->pushButton_basket_8->show();
                seconds1 = 0;
                connct_wheat[8]=0;
                cultivations = "0";
                ui->label_timer_8->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Corn_push8(){
    if(connct_corn[8]==1){
        static QString cultivations;
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        static int seconds1 = 0;
        seconds1++;
        ui->label_timer_8->setText(QString::number(seconds1));
            if(seconds1 == 1){
                Cultivations[8]="corn";
                ui->pushButton_18->setEnabled(false);
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_8->setMovie(movie);
                movie->start();
                ui->label_worker_8->show();
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

            }
            if(seconds1 == 10){
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
            }
            if (seconds1 == 20){
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
                ui->pushButton_basket_8->show();
                seconds1 = 0;
                connct_corn[8]=0;
                cultivations = "0";
                ui->label_timer_8->setText(QString::number(seconds1));
                if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                stream2 << cultivations;
                cultivation.close();
                }else{
                     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Cow_push8(){
    if(connct_cow[8]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_8->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[8]="cow";
                ui->pushButton_18->setEnabled(false);
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_8->show();
                ui->label_cow_8->setStyleSheet("");
                ui->label_cow_8->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_8->setMovie(movie);
                movie->start();
                ui->label_worker_8->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_8->show();
                 ui->label_milk_8->show();
                 ui->label_milk_8->setStyleSheet("");
                 ui->label_milk_8->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_cow[8]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_cow[8]==1){
                ui->pushButton_18->setEnabled(true);
                kill_cow[8]=0;
                connct_cow[8]=0;
                workerlans--;
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_8->hide();
                ui->label_worker_8->hide();
                ui->label_cow_8->hide();
                ui->pushButton_basket_8->hide();
                ui->label_timer_8->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_cow.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }

    }
}


void page2::Chickeen_push8(){
    if(connct_chicken[8]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_8->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[8]="chicken";
                ui->pushButton_18->setEnabled(false);
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_8->show();
                ui->label_cow_8->setStyleSheet("");
                ui->label_cow_8->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_8->setMovie(movie);
                movie->start();
                ui->label_worker_8->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_8->show();
                 ui->label_milk_8->show();
                 ui->label_milk_8->setStyleSheet("");
                 ui->label_milk_8->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");
                 seconds5 = 0;
                 connct_chicken[8]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_chicken[8]==1){
                ui->pushButton_18->setEnabled(true);
                kill_chicken[8]=0;
                connct_chicken[8]=0;
                workerlans--;
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_8->hide();
                ui->label_worker_8->hide();
                ui->label_cow_8->hide();
                ui->pushButton_basket_8->hide();
                ui->label_timer_8->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_chickens("D:/faz2/faz2/fils/kill_chicken.txt");
                QTextStream stream(&kill_chickens);
                if(kill_chickens.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_chickens.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}


void page2::Sheep_push8(){
    if(connct_Sheep[8]==1){
            static int seconds5 = 0;
            seconds5++;
            ui->label_timer_8->setText(QString::number(seconds5));
            if(seconds5 == 1){
                Cultivations[8]="sheep";
                ui->pushButton_18->setEnabled(false);
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
                ui->label_cow_8->show();
                ui->label_cow_8->setStyleSheet("");
                ui->label_cow_8->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
                QMovie *movie = new QMovie("D:/faz2/faz2/imagfil/q2");
                ui->label_worker_8->setMovie(movie);
                movie->start();
                ui->label_worker_8->show();

            }
            if (seconds5 == 20 ){
                 ui->pushButton_basket_8->show();
                 ui->label_milk_8->show();
                 ui->label_milk_8->setStyleSheet("");
                 ui->label_milk_8->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
                 seconds5 = 0;
                 connct_Sheep[8]=0;
            }
            int workerlans=0;
            QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
            QTextStream stream1(&workerlan);
            if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
                stream1 >> workerlans;
                workerlan.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
            if(kill_Sheep[8]==1){
                ui->pushButton_18->setEnabled(true);
                kill_Sheep[8]=0;
                connct_Sheep[8]=0;
                workerlans--;
                ui->pushButton_18->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png);");
                ui->label_milk_8->hide();
                ui->label_worker_8->hide();
                ui->label_cow_8->hide();
                ui->pushButton_basket_8->hide();
                ui->label_timer_8->setText("0");
                seconds5=0;
                int kill=0;
                QFile kill_sheeps("D:/faz2/faz2/fils/kill_sheep.txt");
                QTextStream stream(&kill_sheeps);
                if(kill_sheeps.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream << kill;
                    kill_sheeps.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
                if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
                    stream1 << workerlans;
                    workerlan.close();
                }else{
                    QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
                }
            }
    }
}



void page2::on_pushButton_18_clicked()
{
    QString cultivation;
    QFile cultivations("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&cultivations);
    if(cultivations.open(QIODevice::ReadOnly | QIODevice::Text)){
       stream2 >> cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cultivation=="wheat"){
        connct_wheat[8]=1;
    }else if(cultivation=="corn"){
        connct_corn[8]=1;

    }else if(cultivation=="cow"){
        connct_cow[8]=1;
    }
    else if(cultivation=="chicken"){
        connct_chicken[8]=1;
    }
    else if(cultivation=="sheep"){
        connct_Sheep[8]=1;
    }


    cultivation="0";
    if(cultivations.open(QIODevice::WriteOnly | QIODevice::Text)){
       stream2 << cultivation;
       cultivations.close();
    }else{
       QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::on_pushButton_look_2_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }

    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_look_2->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_3_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_look_3->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_4_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_14->setEnabled(true);
    ui->pushButton_look_4->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }

}


void page2::on_pushButton_look_5_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_15->setEnabled(true);
    ui->pushButton_look_5->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_6_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_look_6->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_7_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_17->setEnabled(true);
    ui->pushButton_look_7->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_8_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_18->setEnabled(true);
    ui->pushButton_look_8->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_9_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_19->setEnabled(true);
    ui->pushButton_look_9->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_10_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_20->setEnabled(true);
    ui->pushButton_look_10->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_11_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(
            land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_21->setEnabled(true);
    ui->pushButton_look_11->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_12_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_22->setEnabled(true);
    ui->pushButton_look_12->hide();

    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_13_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_look_13->hide();
    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}


void page2::on_pushButton_look_14_clicked()
{
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
    int coin = incoin();
    int number_of_land=0;
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");
    QTextStream in(&land);
    QTextStream out(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    if(coin>3){
    coin -= 3;
    number_of_land ++;
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_look_14->hide();
    }else{
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
    }
    outcoin(coin);
    if(land.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
}



void page2::on_pushButton_wheat_clicked()
{
    ui->lineEdit->setText("Wheat");
    QFile wheat("D:/faz2/faz2/fils/number_of_wheat.txt");
    QTextStream stream7(&wheat);
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QTextStream stream2(&worker);
    int number_of_worker=0;
    int workerlans=0;
    int number_of_wheat = 0;
    if(wheat.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream7 >> number_of_wheat;
        wheat.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(worker.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> number_of_worker;
        worker.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_wheat>0 && number_of_worker > workerlans){
        QString cultivations="wheat";
        QString baskets="wheat";
        number_of_wheat--;
        workerlans++;
        ui->label_wheat->setText(QString::number(number_of_wheat));
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream2 << cultivations;
            cultivation.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << workerlans;
            workerlan.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }

         QFile basket("D:/faz2/faz2/fils/basket.txt");
         QTextStream stream1(&basket);
         if(basket.open(QIODevice::WriteOnly | QIODevice::Text)){
               stream1 << baskets;
               basket.close();
         }else{
             QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
         }
    }
    else{
        QMessageBox::warning(this,"EROR","You don't have enough wheat or worker");                        // Declaring an error in terms of the number of wheat
    }
            if(wheat.open(QIODevice::WriteOnly | QIODevice::Text)){
                  stream7 << number_of_wheat;
                  wheat.close();
            }else{
                QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
            }
}


void page2::on_pushButton_corn_clicked()
{
    QFile corn("D:/faz2/faz2/fils/number_of_cron.txt");
    QTextStream stream8(&corn);
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QTextStream stream2(&worker);

    int number_of_worker=0;
    int workerlans=0;
    int number_of_corn = 0;
    if(corn.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream8 >> number_of_corn;
        corn.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(worker.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> number_of_worker;
        worker.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_corn>0 && number_of_worker > workerlans){
        number_of_corn--;
        ui->label_corn->setText(QString::number(number_of_corn));
        workerlans++;
        QString cultivations="corn";
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream2 << cultivations;
            cultivation.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << workerlans;
            workerlan.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        QString baskets="corn";
        QFile basket("D:/faz2/faz2/fils/basket.txt");
        QTextStream stream1(&basket);
        if(basket.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << baskets;
            basket.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
    }else{
        QMessageBox::warning(this,"EROR","You don't have enough corn or worker");                   // Declaring an error in terms of the number of corn
     }
     if(corn.open(QIODevice::WriteOnly | QIODevice::Text)){
     stream8 << number_of_corn;
     corn.close();
     }else{
     QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
     }
}

void page2::on_pushButton_cow_clicked()
{
    QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");
    QTextStream stream8(&cow);
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QTextStream stream2(&worker);
    QString cowss="D:/faz2/faz2/fils/cowland.txt";
    int cowland=infile(cowss);
    int number_of_worker=0;
    int workerlans=0;
    int number_of_cow = 0;
    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream8 >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(worker.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> number_of_worker;
        worker.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_cow>cowland && number_of_worker > workerlans){
        ui->label_cow->setText(QString::number(number_of_cow));
        workerlans++;
        cowland++;
        QString cultivations="cow";
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream2 << cultivations;
            cultivation.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << workerlans;
            workerlan.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        QString baskets="cow";
        QFile basket("D:/faz2/faz2/fils/basket.txt");
        QTextStream stream1(&basket);
        if(basket.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << baskets;
            basket.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        outfil(cowss,cowland);
    }else{
        QMessageBox::warning(this,"EROR","You don't have enough cow or worker");                  // Declaring an error in terms of the number of cow
     }
    if(cow.open(QIODevice::WriteOnly | QIODevice::Text)){
          stream8 << number_of_cow;
          cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::on_pushButton_chicken_clicked()
{
    QFile chicken("D:/faz2/faz2/fils/number_of_chicken.txt");
    QTextStream stream8(&chicken);
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QTextStream stream2(&worker);

    int number_of_worker=0;
    int workerlans=0;
    int number_of_chicken= 0;
    QString chiklan ="D:/faz2/faz2/fils/chickenland.txt";
    int chickenland=infile(chiklan);
    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream8 >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(worker.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> number_of_worker;
        worker.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_chicken>chickenland && number_of_worker > workerlans){
        ui->label_chicken->setText(QString::number(number_of_chicken));
        workerlans++;
        chickenland++;
        QString cultivations="chicken";
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream2 << cultivations;
            cultivation.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << workerlans;
            workerlan.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        QString baskets="chicken";
        QFile basket("D:/faz2/faz2/fils/basket.txt");
        QTextStream stream1(&basket);
        if(basket.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << baskets;
            basket.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        outfil(chiklan,chickenland);
    }else{
        QMessageBox::warning(this,"EROR","You don't have enough chicken or worker");                  // Declaring an error in terms of the number of chicken
     }
    if(chicken.open(QIODevice::WriteOnly | QIODevice::Text)){
          stream8 << number_of_chicken;
          chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}


void page2::on_pushButton_sheep_clicked()
{
    QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");
    QTextStream stream8(&sheep);
    QFile workerlan("D:/faz2/faz2/fils/workerlan.txt");
    QTextStream stream1(&workerlan);
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QTextStream stream2(&worker);

    int number_of_worker=0;
    int workerlans=0;
    int number_of_sheep= 0;
    int sheeplan=0;
    QFile sheeplans("D:/faz2/faz2/fils/sheeplan.txt");
    QTextStream stream9(&sheeplans);
    if(sheeplans.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream9 >> sheeplan;
        sheeplans.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream8 >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(workerlan.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> workerlans;
        workerlan.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(worker.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> number_of_worker;
        worker.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_sheep>sheeplan && number_of_worker > workerlans){
        sheeplan++;
        ui->label_sheep->setText(QString::number(number_of_sheep));
        workerlans++;
        QString cultivations="sheep";
        QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
        QTextStream stream2(&cultivation);
        if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream2 << cultivations;
            cultivation.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(workerlan.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << workerlans;
            workerlan.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        QString baskets="sheep";
        QFile basket("D:/faz2/faz2/fils/basket.txt");
        QTextStream stream1(&basket);
        if(basket.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream1 << baskets;
            basket.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(sheeplans.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream9 << sheeplan;
            sheeplans.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
    }else{
        QMessageBox::warning(this,"EROR","You don't have enough sheep or worker");                   // Declaring an error in terms of the number of sheep
     }
    if(sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
          stream8 << number_of_sheep;
          sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
}

