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

page2::page2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page2)
{
    QMap < int , QPushButton *> buttonmap;
    QMap < int , QLabel *> milk;
    QMap < int , QLabel *> cows;
    QMap < int , QPushButton *> basket;

    buttonmap[1]=ui->pushButton_7;
    buttonmap[2]=ui->pushButton_9;
    milk[1]=ui->label_milk;
    milk[2]=ui->label_milk_2;
    cows[1]=ui->label_cow;
    cows[2]=ui->label_cow_2;
    basket[1]=ui->pushButton_basket;
    basket[2]=ui->pushButton_basket_2;

    ui->setupUi(this);
    ui->pushButton_basket->hide();
    ui->label_cow->hide();
    ui->label_milk->hide();
    ui->pushButton_basket_2->hide();
    ui->label_cow_2->hide();
    ui->label_milk_2->hide();
    ui->label_2->hide();

    ui->label->hide();
    refresh();
    ui->label_player->setText("Login Page Player" + QString::number(play));

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&page2::updateTime);
    timer->start(1000);
}


void page2::refresh()
{

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

       int coin = 10;
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
}


void page2::basketss(int pric)
{
    QFile file("D:/faz2/faz2/fils/coin.txt");
    QTextStream in(&file);
    QTextStream out(&file);
    QTextStream out2(&file);

    int coin;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> coin;
        file.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
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
        int coin;
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


int page2::incoin(QString fils)
{
        int num;
        QFile file("fils");
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
    int number;
    QFile numbers("D:/faz2/faz2/fils/number.txt");
    QTextStream in1(&numbers);

    if(numbers.open(QIODevice::ReadOnly | QIODevice::Text)){
        in1 >> number;
        numbers.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    QMap < int , QPushButton *> buttonmap;
    QMap < int , QLabel *> milk;
    QMap < int , QLabel *> cows;
    QMap < int , QPushButton *>  basket;

    buttonmap[1]=ui->pushButton_7;
    buttonmap[2]=ui->pushButton_9;
    milk[1]=ui->label_milk;
    milk[2]=ui->label_milk_2;
    cows[1]=ui->label_cow;
    cows[2]=ui->label_cow_2;
    basket[1]=ui->pushButton_basket;
    basket[2]=ui->pushButton_basket_2;
    static int seconds = 0;
    seconds++;
    QString cultivations;
    QFile cultivation("D:/faz2/faz2/fils/cultivation.txt");
    QTextStream stream2(&cultivation);
    if(cultivation.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> cultivations;
        cultivation.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }



    if (cultivations=="wheat"){
//        updatewheat();


        static int seconds1 = 0;
        seconds1++;
        if(seconds1 == 1){
//            ui->pushButton_7->setEnabled(false);
//            ui->pushButton_7->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
            buttonmap[number]->setEnabled(false);
            buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");

        }
        if(seconds1 == 15){
            buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
        }
        if (seconds1 == 25 ){
             buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/ppcorn.png);");
             basket[number]->show();
             seconds1 = 0;
             cultivations = "0";
             if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                 stream2 << cultivations;
                 cultivation.close();
             }else{
                 QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
             }
        }



    }
    else if (cultivations=="corn"){
        static int seconds2 = 0;
        static int secondscount = 0;
        seconds2++ ;
        secondscount++;

        if(seconds2 == 1){
            buttonmap[number]->setEnabled(false);
            buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
        }
        if(seconds2 == 10){
            buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (5).png)");
        }
        if (seconds2 == 20 ){
             buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/rsi.png)");
             basket[number]->show();

             seconds2 = 0;
             if(sw==1){
             cultivations = "0";
             secondscount=0;
             sw=0;
             }
             if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                 stream2 << cultivations;
                 cultivation.close();
             }else{
                 QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
             }
        }
                 if(secondscount==25||secondscount==30||secondscount==35){
                    if(sw==0){
                    ui->label->show();
                    int coin =incoin();
                    coin--;
                    if(secondscount==35){
                        secondscount=0;
                        coin++;
                    }
                    outcoin(coin);
                    }
                }
    }
    else if(cultivations=="chicken"){
        static int seconds3 = 0;
        seconds3++;
        if(seconds3 == 1){
            buttonmap[number]->setEnabled(false);
            buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
            cows[number]->show();
            cows[number]->setStyleSheet("");
            cows[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-rooster-icon.png)");
        }
        if (seconds3 == 20 ){
            basket[number]->show();
            milk[number]->show();
            milk[number]->setStyleSheet("");
            milk[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/favpng_chicken-egg-icon.png)");

             seconds3 = 0;
             cultivations = "0";
             if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                 stream2 << cultivations;
                 cultivation.close();
             }else{
                 QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
             }
        }
    }
    else if(cultivations=="sheep"){
        static int seconds4 = 0;
        seconds4++;
        int sheeplan=0;
        int number_of_sheep=0;
        QFile sheeplans("D:/faz2/faz2/fils/sheeplan.txt");
        QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");

        QTextStream stream9(&sheeplans);
        QTextStream stream8(&sheep);

        if(sheeplans.open(QIODevice::ReadOnly | QIODevice::Text)){
            stream9 >> sheeplan;
            sheeplans.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
            stream9 >> number_of_sheep;
            sheep.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        if(seconds4 == 1){
            buttonmap[number]->setEnabled(false);
            buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
            cows[number]->show();
            cows[number]->setStyleSheet("");
            cows[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/sheepgoat.png)");
        }
        if (seconds4 == 15 ){
            if(sheeplan>number_of_sheep){
                cultivations = "0";
                sheeplan--;
            }
             basket[number]->show();
             milk[number]->show();
             milk[number]->setStyleSheet("");
             milk[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
             seconds4 = 0;
             if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                 stream2 << cultivations;
                 cultivation.close();
             }else{
                 QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
             }
        }
    }
    else if(cultivations=="cow"){
        static int seconds5 = 0;
        seconds5++;
        if(seconds5 == 1){
            buttonmap[number]->setEnabled(false);
            buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-450072032-Vector Icons of Land Farms (4).png)");
            cows[number]->show();
            cows[number]->setStyleSheet("");
            cows[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/Lovepik_com-401736967-cow.png)");

        }
        if (seconds5 == 20 ){
             basket[number]->show();
             milk[number]->show();
             milk[number]->setStyleSheet("");
             milk[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/milk-bucket-7808176-6347464.webp)");
             seconds5 = 0;
             cultivations = "0";
             if(cultivation.open(QIODevice::WriteOnly | QIODevice::Text)){
                 stream2 << cultivations;
                 cultivation.close();
             }else{
                 QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
             }
        }
    }




    static int players=0;
    QFile player("D:/faz2/faz2/fils/number_of_players.txt");
    QTextStream stream1(&player);
    if(player.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> players;
        player.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    if (seconds == 10 && play<=players)                                                    // check if 3 minutes have passed
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
                    ui->lineEdit_2->setText(Username);
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
        ui->lineEdit->setText(coins);
        score =QSqlDatabase::addDatabase("QSQLITE");
        score.setDatabaseName("d:///score.db");                                           //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
        score.open();
        score.exec("INSERT INTO username(UserName,Score,number)VALUES('"+Username+"','"+coins+"','"+numbr+"')");
        score.close();

        play++;
        ui->label_player->setText("Login Page Player" + QString::number(play));
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
        ui->lineEdit->setText(QString::number(scr[i]));
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

    QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");

    QTextStream stream8(&sheep);

    int number_of_sheep= 0;
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream8 >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
          stream8 << number_of_sheep;
          sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    QFile file("D:/faz2/faz2/fils/coin.txt");
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QFile land("D:/faz2/faz2/fils/number_of_land.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    worker.open(QIODevice::ReadOnly | QIODevice::Text);
    land.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QTextStream stream(&worker);
    QTextStream in2(&land);
    int number_of_land;
    int coin;
    int number_of_worker;
    in >> coin;
    stream >> number_of_worker;
    in2 >> number_of_land;
    file.close();
    worker.close();
    ui->lineEdit_coin->setText(" = " + QString::number(coin));
    ui->lineEdit_worker->setText(" = " + QString::number(number_of_worker));
    ui->lineEdit_land->setText(" = " + QString::number(number_of_land));

//    if(number_of_sheep){

//    }
}









page2::~page2()
{
    delete ui;
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


void page2::on_pushButton_7_clicked()
{
    int number=1;
    QFile numbers("D:/faz2/faz2/fils/number.txt");
    QTextStream stream(&numbers);

    if(numbers.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << number;
        numbers.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    mland* MLAND = new mland();
    MLAND ->show();
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
    int number;
    sw=1;
    QFile numbers("D:/faz2/faz2/fils/number.txt");
    QTextStream in1(&numbers);

    if(numbers.open(QIODevice::ReadOnly | QIODevice::Text)){
        in1 >> number;
        numbers.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    QMap < int , QPushButton *> buttonmap;
    QMap < int , QPushButton *> basket;

    QMap < int , QLabel *> milk;
    QMap < int , QLabel *> cows;
    buttonmap[1]=ui->pushButton_7;
    buttonmap[2]=ui->pushButton_9;
    milk[1]=ui->label_milk;
    milk[2]=ui->label_milk_2;
    cows[1]=ui->label_cow;
    cows[2]=ui->label_cow_2;
    basket[1]=ui->pushButton_basket;
    basket[2]=ui->pushButton_basket_2;
    ui->label->hide();
    cows[number]->hide();
    milk[number]->hide();
    if(buttonmap.contains(number)){
      buttonmap[number]->setEnabled(true);
    }
    QFile file("D:/faz2/faz2/fils/coin.txt");
    QTextStream in(&file);
    QTextStream out(&file);
    QTextStream out2(&file);

    int coin;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> coin;
        file.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    QString baskets;
    QFile baskett("D:/faz2/faz2/fils/basket.txt");
    QTextStream stream2(&baskett);
    if(baskett.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> baskets;
        baskett.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(baskets == "corn" ){
        basketss(2);
        QFile corn("D:/faz2/faz2/fils/number_of_cron.txt");
        QTextStream stream8(&corn);

        int number_of_corn = 0;
        if(corn.open(QIODevice::ReadOnly | QIODevice::Text)){
            stream8 >> number_of_corn;
            corn.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        number_of_corn++;
        if(corn.open(QIODevice::WriteOnly | QIODevice::Text)){
              stream8 << number_of_corn;
              corn.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
    }
    if(baskets == "wheat" ){
        basketss(3);
        QFile wheat("D:/faz2/faz2/fils/number_of_wheat.txt");
        QTextStream stream7(&wheat);

        int number_of_wheat = 0;
        if(wheat.open(QIODevice::ReadOnly | QIODevice::Text)){
            stream7 >> number_of_wheat;
            wheat.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        number_of_wheat++;
        if(wheat.open(QIODevice::WriteOnly | QIODevice::Text)){
              stream7 << number_of_wheat;
              wheat.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
    }
    if(baskets == "cow" ){
        basketss(5);
        QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");
        QTextStream stream8(&cow);

        int number_of_cow = 0;
        if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
            stream8 >> number_of_cow;
            cow.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        number_of_cow++;
        if(cow.open(QIODevice::WriteOnly | QIODevice::Text)){
              stream8 << number_of_cow;
              cow.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }

    }
    if(baskets == "sheep" ){
        basketss(3);

    }
    if(baskets == "chicken" ){
        basketss(3);
        QFile chicken("D:/faz2/faz2/fils/number_of_chicken.txt");
        QTextStream stream8(&chicken);

        int number_of_chicken= 0;
        if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
            stream8 >> number_of_chicken;
            chicken.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        number_of_chicken++;
        if(chicken.open(QIODevice::WriteOnly | QIODevice::Text)){
              stream8 << number_of_chicken;
              chicken.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
    }
    basket[number]->hide();
    buttonmap[number]->setStyleSheet("");
    buttonmap[number]->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
}






void page2::on_pushButton_9_clicked()
{
    int number=2;
    QFile numbers("D:/faz2/faz2/fils/number.txt");
    QTextStream stream(&numbers);

    if(numbers.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << number;
        numbers.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    mland* MLAND = new mland();
    MLAND ->show();
}


void page2::on_pushButton_Butcher_clicked()
{
    Butcher* BUTCHER = new Butcher();
    BUTCHER->show();
}




