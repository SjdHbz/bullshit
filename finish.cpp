#include "finish.h"
#include "ui_finish.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QString"
#include "QDebug"
finish::finish(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);
    QSqlDatabase scores;
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

