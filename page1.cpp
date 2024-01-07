#include "page1.h"
#include "page2.h"
#include "ui_page1.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QString"
#include "QSqlQuery"
#include "QMessageBox"
#include "QtPrintSupport/QPrinter"
#include <QPainter>
#include <QRandomGenerator>
#include <fstream>
#include "QFile"
#include "QTextStream"
#include <QMediaPlayer>
int success=1;
int play=1;
int players=0;
QString paswors;            //استرینگ پسورد
QString email;              //استرینگ ایمیل
QString UserName;           //استرینگ یوزر نیم
QString inventory;          //استرینگ موجودی
QString phone;              //استرینگ شماره تلفن
QString actual;             //استرینگ کد کپچا

QMediaPlayer *player = new
QMediaPlayer;
page1::page1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::page1)
{
    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/garm.mp3"));
    player->setVolume(50);
    player->play();
    ui->pushButton->setEnabled(false);
    ui->label->hide();
    ui->label_2->hide();
    ui->comboBox->hide();
    ui->comboBox_3->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_2->hide();
    ui->pushButton_3->hide();
    ui->label_5->hide();
    ui->pushButton->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->radioButton->hide();
    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:/faz2/faz2/paigafaz12.db");
    database.open();
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);                  //قطع دسترسی به رمز عبور و تمام لاین ادیت ها
    ui->lineEdit_5->setEnabled(false);
    ui->lineEdit_6->setEnabled(false);
    ui->lineEdit_7->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->label_5->setText("Lpgin Page Player" + QString::number(success));       //نمایش نام صفحه مختص هر بازیکن
    QRegularExpression regex6("^[0-9]*$");                      //شرط موجودی
    QValidator *validatot1= new QRegularExpressionValidator(regex6,this);
    ui->lineEdit_6->setValidator(validatot1);                   //گرفتن موجودی در خط ۱۰۸ شرط موجودی
    QValidator *validatot2= new QRegularExpressionValidator(regex6,this);
    ui->lineEdit_2->setValidator(validatot2);
    QRegularExpression regex5("^[a-zA-Z0-9]*$");                //شروط رمز
    QValidator *validatot= new QRegularExpressionValidator(regex5,this);             //قطع دسترسی به کارکتر های غیر عدد و حروف
    ui->lineEdit_4->setValidator(validatot);
}

page1::~page1()
{
    delete ui;
}

void page1::on_pushButton_5_clicked()
{
    QFile player("D:/faz2/faz2/number_of_players.txt");
    QTextStream stream(&player);
    if(player.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << players;
        player.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->label->show();
    ui->label_2->show();
    ui->comboBox->show();
    ui->comboBox_3->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->lineEdit_6->show();
    ui->lineEdit_7->show();
    ui->lineEdit_2->show();
    ui->pushButton_3->show();
    ui->pushButton->show();
    ui->label_5->show();
    ui->label_4->show();
    ui->radioButton->show();
    QMessageBox::information(this,"iformation","  First, you must choose your email format");
}

void page1::on_comboBox5_activated(int index)
{
    players=index;
    if (index!=0){
    ui->pushButton_5->setEnabled(true);
    }
    else{
        QMessageBox::information(this,"EROR","Please enter the number of players");
        ui->pushButton_5->setEnabled(false);
    }
}


void page1::on_pushButton_clicked()         //گزینه لاگین
{
    int ema=0;
    QString Prohibitions;
    Prohibitions = "*+-/$)(#^%";
    email = ui->lineEdit_3->text();                 //بررسی ایمیل برای وارد نکردن کارکتر های ممنوعه
    paswors=ui->lineEdit_4->text();
    if(email==NULL && paswors==NULL){
        QMessageBox::warning(this,"EROR","Password and email are required");
    }
    else{
    if(email==NULL||paswors==NULL){
        QMessageBox::warning(this,"EROR","You have not entered your email or password");
        ema=0;
      }
    }
    for (int i = 0; i < email.length(); i++) {
        for (int j = 0; j < Prohibitions.length(); j++) {
            if (email[i] == Prohibitions[j]) {
                QMessageBox::warning(this,
                                     "EROR", "Please do not use" //اگر کارکتر ممنوعه وارد شود مسج باکس ارور ظاهر میشود
                                             "<li>"
                                             " *+-/$)(#^% "
                                             "<li>"
                                             "characters");
                ui->lineEdit_3->clear();            // و لاین ادیت ایمیل خالی میشود
                return;
            }
            else {
                ema=1;
            }
        }
    }
    QRegularExpression re("(.*)(@)([^@]+)$");
    QRegularExpressionMatch match = re.match(email);
    if (match.hasMatch()) {
        QString localPart = match.captured(1);
        QString atSymbol = match.captured(2);
        QString domain = match.captured(3);
        QRegularExpression domainCheck("(gmail.com|email.com|mail.um.ac)$");
        QRegularExpressionMatch domainMatch = domainCheck.match(domain.right(10));
        if (!domainMatch.hasMatch()) {
            QMessageBox::warning(this, "EROR", "Email domain is not allowed");
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            return;
        }
        email = localPart + atSymbol + domain;
        ui->lineEdit_3->setText(email);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
    } else {
        QMessageBox::warning(this, "EROR", "The email is invalid");
        ema=0;
    }
    UserName=ui->lineEdit_5->text();
    if(UserName==NULL){
        QMessageBox::warning(this,"EROR","You have not entered your username");
                ema=0;
    }

    inventory = ui->lineEdit_6->text();                 //گرفتن موجودی
    int invent=inventory.toInt();
    if(invent == 0){
        QMessageBox::warning(this,"EROR","You have not entered an inventory");
        ema=0;
    }
    QString compare= ui->lineEdit_2->text();
    ui->lineEdit_2->setText(actual);
    if(compare!=actual){
        QMessageBox::warning(this,"EROR","The captcha code was entered incorrectly");
        ui->lineEdit_2->clear();
        ema=0;
    }
    if(ema==1 ){
        if(play<=players){
        play++;
        QSqlQuery paigah;
        email=ui->lineEdit_3->text();
        paswors=ui->lineEdit_4->text();             //ریختن متغیر ها داخل کلاس گیرنده معلومات
        UserName=ui->lineEdit_5->text();
        phone = ui->lineEdit_7->text();
        inventory  = ui->lineEdit_6->text();            //تبدیل موجودی از حالت استرینگ به اینت
        //fsaاضافه کردن به داده بایگاه
        paigah.exec("INSERT INTO Loginpaigah(Email,Pasword,Username,Inventory,Phone)VALUES('"+email+"','"+paswors+"','"+UserName+"','"+inventory+"','"+phone+"')");

        ui->lineEdit_3->clear();
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->clear();          //اگر رمز و ایمیل به درستی وارد شد دسترسی به هردوی ان ها را میگیرد
        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_5->clear();
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_6->clear();
        ui->lineEdit_6->setEnabled(false);
        ui->lineEdit_7->clear();
        ui->lineEdit_7->setEnabled(false);
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setEnabled(false);

        success++;
        ui->label_5->setText("Lpgin Page Player" + QString::number(success));
        on_pushButton_3_clicked();
        }

    }                                               //این شرط اخرین دستوری است که در این گزینه گذاشته میشود و برای بستن صفحه لاگین خواهد بود
    if(play>players){
        player->stop();
        this->hide();
        page2* newPage = new page2();
        newPage->show();

    }
}
void page1::on_pushButton_3_clicked()           //برای ساخت کد کپچا
{
    QPixmap captchaImage(100,50);           // سایز کد
    captchaImage.fill(Qt::white);           //رنگ بک گراند عکس
    QPainter painter(&captchaImage);
    QFont chillerFont("Chiller",30);        //سایز و نوع فونت
    chillerFont.setStrikeOut(true);         //فونت خط روی حرف
    painter.setFont(chillerFont);
    painter.setPen(Qt::black);                 //رنگ فونت
    QString captchaCode=QString::number(QRandomGenerator::global()->bounded(1000,10000));
    painter.drawText(10,30,captchaCode);
    ui->captchaLabel->setPixmap(captchaImage);          //ریختن عکس در لیبل
    actual=captchaCode;         // گرفتن کد کپچا برای مقایسه
}

void page1::on_comboBox_activated(int index)
{
    QRegularExpression regex("[^\\s@]+@gmail.com");
    QRegularExpression regex1("[^//s@]+@email.com");        //برای تعیین فرمت ایمیل و ده کارکتر اخرش
    QRegularExpression regex2("[^//s@]+@mail.um.ac");

    if (index == 0) {
        QValidator *validator = new QRegularExpressionValidator(regex, this);
        ui->lineEdit_3->setValidator(validator);
        ui->lineEdit_3->setEnabled(true);           //دسترسی به همه لاین ادیت ها بجز 7 باز میشود
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->pushButton->setToolTip("Enter the game");    //تول تیپ برای هر ایندیکس

    }
    if (index == 1) {
        QValidator *validator = new QRegularExpressionValidator(regex1, this);
        ui->lineEdit_3->setValidator(validator);
        ui->lineEdit_3->setEnabled(true);           //دسترسی به هر دو لاین ادیت داده میشود
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->pushButton->setToolTip("Enter the game");
    }
    if (index == 2) {
        QValidator *validator = new QRegularExpressionValidator(regex2, this);
        ui->lineEdit_3->setValidator(validator);
        ui->lineEdit_3->setEnabled(true);           //دسترسی به هر دو لاین ادیت داده میشود
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_6->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->pushButton->setToolTip("Enter the game");       //گزینه لاگین دسترسی باز میشود و تول تیب ان برای راهنمایی نشان داده میشود-
    }
}

void page1::on_radioButton_clicked(bool checked)
{
    if(checked){
    ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
    ui->label_3->show();
    ui->label_4->hide();
    }
    else{
        ui->lineEdit_4->setEchoMode(QLineEdit::Password);
        ui->label_3->hide();
        ui->label_4->show();
    }

}



void page1::on_comboBox_3_activated(int index)
{
    QRegularExpression regex7("^[0-9]*$");
    QValidator *validatot3= new QRegularExpressionValidator(regex7,this);
    ui->lineEdit_7->setValidator(validatot3);  //شرط موجودی
    switch (index) {
    case 0:
        ui->lineEdit_7->setText("0098");
        ui->lineEdit_7->setEnabled(true);


        break;
    case 1:
        ui->lineEdit_7->setText("0093");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 2:
        ui->lineEdit_7->setText("0039");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 3:
        ui->lineEdit_7->setText("0092");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 4:
        ui->lineEdit_7->setText("0086");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 5:
        ui->lineEdit_7->setText("001");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 6:
        ui->lineEdit_7->setText("0044");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 7:
        ui->lineEdit_7->setText("0091");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 8:
        ui->lineEdit_7->setText("0081");
        ui->lineEdit_7->setEnabled(true);

        break;
    case 9:
        ui->lineEdit_7->setText("00970");
        ui->lineEdit_7->setEnabled(true);

        break;

    }
}


void page1::on_pushButton_2_clicked()
{
    player->stop();
    this->hide();
    page2* newPage = new page2();
    newPage->show();
}

