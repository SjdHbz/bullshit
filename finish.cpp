#include "finish.h"
#include "ui_finish.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QString"
#include "QDebug"
#include "iostream"
#include "algorithm"
#include "QFile"
#include "QMessageBox"
using namespace std;
finish::finish(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);
    QString Username[10];
    QString scor;
    int scr[10];
    for(int i=0;i<10;i++){
        scr[i]=-100;
    }
    int players=0;
    QFile player("D:/faz2/faz2/fils/number_of_players.txt");
    QTextStream stream1(&player);
    if(player.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> players;
        player.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    players++;
    QSqlDatabase scores;
    scores=QSqlDatabase::addDatabase("QSQLITE");
    scores.setDatabaseName("d:///score.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
    for(int i = 0; i <= players ; i++){
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
    for(int i = 1; i <= players ; i++){
        int min=i;
        for(int j=i+1;j<=players;j++){
            if (scr[j]<scr[min]){
                min=j;
            }
        }
        swap(scr[i],scr[min]);
        swap(Username[i],Username[min]);
    }

    for (int i=players;i>1;i--){
        QSqlDatabase score;
        QString coins=QString::number(scr[i]);
        score =QSqlDatabase::addDatabase("QSQLITE");
        score.setDatabaseName("d:///scoretartib.db");                                           //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
        score.open();
        score.exec("INSERT INTO username(UserName,Score)VALUES('"+Username[i]+"','"+coins+"')");
        score.close();
    }
    scores=QSqlDatabase::addDatabase("QSQLITE");
    scores.setDatabaseName("d:///scoretartib.db");                                 //فایل دیتا بیس خود را در درایو دی جایگزاری کنید
    scores.open();
    QSqlQuery q;
    q.exec("SELECT * FROM username");
    QSqlQueryModel * m = new QSqlQueryModel ;
    m->setQuery(q);
    ui->tableView->setModel(m);
    scores.close();
}


finish::~finish()
{
    delete ui;
}

