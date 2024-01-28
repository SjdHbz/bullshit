#include "guide.h"
#include "ui_guide.h"
#include "QDebug"
#include "QString"
#include "QRegularExpression"
#include "QRegularExpressionValidator"
Guide::Guide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Guide)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(true);
//    QRegularExpression regex("^[a-z]*$");
//    QValidator *validatot= new QRegularExpressionValidator(regex,this);
//    ui->lineEdit->setValidator(validatot);
}

Guide::~Guide()
{
    delete ui;
}

void Guide::on_pushButton_clicked()
{
    QString line = ui->lineEdit->text();
    QString Search_corn="corn";
    QString Search_wheat="wheat";
    QString Search_cow="cow";
    QString Search_chicken="chicken";
    QString Search_sheep="sheep";
    QString Search_Delay="delay";
    QString Search_Late="late";
    if(line.isEmpty()){
        ui->label_guid1->setText("Empty");
        ui->label_guid1_2->setText("");
        ui->label_guid1_3->setText("");
        ui->label_guid1_4->setText("");
        ui->label_guid1_5->setText("");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");

    }
    if(line.contains(Search_corn)){
        ui->label_guid1->setText("By buying corn seeds from the store,");
        ui->label_guid1_2->setText("the amount of corn is added to the purchased");
        ui->label_guid1_3->setText("size and inThe amount is displayed at the top");
        ui->label_guid1_4->setText("of the game screen. You can plant your corn by");
        ui->label_guid1_5->setText("clicking on the corn icon and moving it to the");
        ui->label_guid1_6->setText("ground.");
        ui->label_guid1_7->setText("Note: buying corn will be 2 coins and collecting");
        ui->label_guid1_8->setText("corn will be 2 coins and will not have any benefit");
        ui->label_guid1_9->setText("in game points.");
    }
    if(line.contains(Search_wheat)){
        ui->label_guid1->setText("By buying wheat seeds from the store,");
        ui->label_guid1_2->setText("the amount of wheat is added to the purchased");
        ui->label_guid1_3->setText("size and inThe amount is displayed at the top");
        ui->label_guid1_4->setText("of the game screen. You can plant your wheat by");
        ui->label_guid1_5->setText("clicking on the wheat icon and moving it to the");
        ui->label_guid1_6->setText("ground.");
        ui->label_guid1_7->setText("Note: By buying and cultivating");
        ui->label_guid1_8->setText("this product, you will earn 1 coin.");
        ui->label_guid1_9->setText("");
    }
    if(line.contains(Search_cow)){
        ui->label_guid1->setText("By buying a cow from the store,");
        ui->label_guid1_2->setText("the cow is transferred to the cow");
        ui->label_guid1_3->setText("house until you breed it!");
        ui->label_guid1_4->setText("The cow is not taken off the ground");
        ui->label_guid1_5->setText("until it is killed.");
        ui->label_guid1_6->setText("The cow gives two products, milk and");
        ui->label_guid1_7->setText("meat, which you will harvest every 20 ");
        ui->label_guid1_8->setText("seconds during breeding, and each milk");
        ui->label_guid1_9->setText("product will be worth 5 coins.");
    }
    if(line.contains(Search_sheep)){
        ui->label_guid1->setText("By buying a sheep from the store,");
        ui->label_guid1_2->setText("you can breed it in the fields by ");
        ui->label_guid1_3->setText("selecting the sheep icon at the top");
        ui->label_guid1_4->setText("of the game screen.");
        ui->label_guid1_5->setText("A sheep is killed only when it is taken");
        ui->label_guid1_6->setText("off the ground and it has two products:");
        ui->label_guid1_7->setText("milk and meat, its milk is 4 coins and");
        ui->label_guid1_8->setText("its meat is 4 coins.");
        ui->label_guid1_9->setText("");
    }
    if(line.contains(Search_chicken)){
        ui->label_guid1->setText("By buying chicken from the store,");
        ui->label_guid1_2->setText("the chickens are kept in the chicken");
        ui->label_guid1_3->setText("house until they go to the land for");
        ui->label_guid1_4->setText("breeding, and there is only one way ");
        ui->label_guid1_5->setText("to empty the said land, and that is to ");
        ui->label_guid1_6->setText("kill the chicken.");
        ui->label_guid1_7->setText("Chicken has two products, egg and meat,");
        ui->label_guid1_8->setText("where the egg is 3 coins and the meat is 2 coins");
        ui->label_guid1_9->setText("");

    }
    if(line.contains(Search_Delay)||line.contains(Search_Late)){
        ui->label_guid1->setText("In case of decrease, one coin will be deducted");
        ui->label_guid1_2->setText("from the value of the product every 5 seconds");
        ui->label_guid1_3->setText("until the price of the product is zero");
        ui->label_guid1_4->setText("");
        ui->label_guid1_5->setText("");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
    }
}

