#include "setting.h"
#include "ui_setting.h"
#include "QMediaPlayer"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QMessageBox"
#include "QFile"
setting::setting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_username->hide();
    ui->pushButton_Phone->hide();
    ui->pushButton_Password->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_6->hide();
    music->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/lansvoic.mp3"));
    QSqlDatabase scores;
    QFile player("D:/faz2/faz2/fils/number_of_players.txt");
    QTextStream stream1(&player);
    if(player.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> players;
        player.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    scores=QSqlDatabase::addDatabase("QSQLITE");
    scores.setDatabaseName("d:///database.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
    for(int i = 0; i <= players ; i++){
        if(scores.open()){
            QSqlQuery qury;
            QString pric =  QString::number(i);
            if(qury.exec("SELECT Email FROM Loginpaigah WHERE number='"+pric+"' ")){
                if(qury.next()){
                    Email[i] = qury.value(0).toString();
                }
            }
            scores.close();
        }else {
            qDebug() << "failed db.";
        }
    }
    for(int i = 0; i <= players ; i++){
        if(scores.open()){
            QSqlQuery qury;
            QString pric =  QString::number(i);
            if(qury.exec("SELECT Pasword FROM Loginpaigah WHERE number='"+pric+"' ")){
                if(qury.next()){
                    Password[i] = qury.value(0).toString();
                }
            }
            scores.close();
        }else {
            qDebug() << "failed db.";
        }
    }
}


setting::~setting()
{
    delete ui;
}



void setting::on_pushButton_clicked()
{
    for(int i=0;i<players;i++){
        email[i]=ui->lineEdit->text();
        password[i]=ui->lineEdit_2->text();
        if(Email[i]==email[i]&&Password[i]==password[i]){
            key=i;
            ui->lineEdit->hide();
            ui->lineEdit_2->hide();
            ui->pushButton->hide();
            ui->label->hide();
            ui->label_2->setText("");
            ui->pushButton_2->show();
            ui->pushButton_3->show();
            ui->pushButton_5->show();
        }else{
            ui->label_2->setText("The password is wrong");
        }
    }
}


void setting::on_pushButton_username_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:///database.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
    if(!db.open()){

    }
    QSqlQuery query;
    QString username=ui->lineEdit_3->text();
    QString pric =  QString::number(key);
    query.prepare("UPDATE Loginpaigah SET Username = :username WHERE number = :pric");
    query.bindValue(":username",username);
    query.bindValue(":pric",pric);
    if(query.exec()){
        ui->label_2->setText("Username updated successfully");
    }
    else{
        ui->label_2->setText("EROR:Username update failed");
    }
    db.close();
}


void setting::on_pushButton_Password_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:///database.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
    if(!db.open()){

    }
    QSqlQuery query;
    QString password=ui->lineEdit_4->text();
    QString pric =  QString::number(key);
    query.prepare("UPDATE Loginpaigah SET Pasword = :password WHERE number = :pric");
    query.bindValue(":password",password);
    query.bindValue(":pric",pric);
    if(query.exec()){
        ui->label_2->setText("Password updated successfully");
    }
    else{
        ui->label_2->setText("EROR:Password update failed");
    }
    db.close();
}


void setting::on_pushButton_Phone_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:///database.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
    if(!db.open()){

    }
    QSqlQuery query;
    QString phone=ui->lineEdit_6->text();
    QString pric =  QString::number(key);
    query.prepare("UPDATE Loginpaigah SET Phone = :phone WHERE number = :pric");
    query.bindValue(":phone",phone);
    query.bindValue(":pric",pric);
    if(query.exec()){
        ui->label_2->setText("Phone updated successfully");
    }
    else{
        ui->label_2->setText("EROR:Phone update failed");
    }
    db.close();
}

