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
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }
    if(line.contains("collection")||line.contains("Collection")){
        ui->label_guid1->setText("Product collection is in the ");
        ui->label_guid1_2->setText("form of coins");
        ui->label_guid1_3->setText("(You will receive coins by ");
        ui->label_guid1_4->setText("collecting the product).");
        ui->label_guid1_5->setText("");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("image: url(:/new/prefix1/imagfil/1043472.png);");
    }
    else if((line.contains("how")||line.contains("How"))&&(line.contains("cow")||line.contains("Cow"))){
        ui->label_guid1->setText("You must first have a cow in the");
        ui->label_guid1_2->setText("cow house and then click on the cow");
        ui->label_guid1_3->setText("icon at the top of the screen and ");
        ui->label_guid1_4->setText("then click on the land to breed ");
        ui->label_guid1_5->setText("the cow on the said land.");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_images/guid_cow.jpg)");
        ui->label_land->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
        ui->label_butcher->setStyleSheet("");

    }
    else if((line.contains("how")||line.contains("How"))&&(line.contains("sheep")||line.contains("Sheep"))){
        ui->label_guid1->setText("You must first have a sheep in the");
        ui->label_guid1_2->setText("sheep house and then click on the sheep");
        ui->label_guid1_3->setText("icon at the top of the screen and ");
        ui->label_guid1_4->setText("then click on the land to breed ");
        ui->label_guid1_5->setText("the sheep on the said land.");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_images/guid_sheep.jpg)");
        ui->label_land->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
        ui->label_butcher->setStyleSheet("");
    }
    else if((line.contains("how")||line.contains("How"))&&(line.contains("chicken")||line.contains("chicken"))){
        ui->label_guid1->setText("You must first have a chicken in the");
        ui->label_guid1_2->setText("chicken house and then click on the chicken");
        ui->label_guid1_3->setText("icon at the top of the screen and ");
        ui->label_guid1_4->setText("then click on the land to breed ");
        ui->label_guid1_5->setText("the chicken on the said land.");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_images/guid_chicken.jpg)");
        ui->label_land->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains("kill")||line.contains("butcher")||line.contains("Butcher")||line.contains("Kill")){
        ui->label_guid1->setText("You can kill your animal by killing");
        ui->label_guid1_2->setText("it in the butchery area and get its");
        ui->label_guid1_3->setText("meat product and also empty the land.");
        ui->label_guid1_4->setText("");
        ui->label_guid1_5->setText("");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("border-image: url(:/new/prefix1/imagfil/butcher shop.png)");
    }
    else if((line.contains("how")||line.contains("How"))&&(line.contains("wheat")||line.contains("Corn"))){
        ui->label_guid1->setText("You must have wheat seeds in your");
        ui->label_guid1_2->setText("warehouse and then click on the ");
        ui->label_guid1_3->setText("wheat icon from the top of the");
        ui->label_guid1_4->setText("game screen and move it to the");
        ui->label_guid1_5->setText("ground to kill the seed.");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_images/guid_wheat.jpg)");
        ui->label_land->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
        ui->label_butcher->setStyleSheet("");
    }
    else if((line.contains("how")||line.contains("How"))&&(line.contains("corn")||line.contains("Corn"))){
        ui->label_guid1->setText("You must have wheat seeds in your");
        ui->label_guid1_2->setText("warehouse and then click on the");
        ui->label_guid1_3->setText("wheat icon from the top of the");
        ui->label_guid1_4->setText("game screen and move it to the");
        ui->label_guid1_5->setText("ground to kill the seed.");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_images/guid_corn.jpg)");
        ui->label_land->setStyleSheet("border-image: url(:/new/prefix1/imagfil/lanppc.png)");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains(Search_corn)||line.contains("Corn")){
        ui->label_guid1->setText("By buying corn seeds from the store,");
        ui->label_guid1_2->setText("the amount of corn is added to the purchased");
        ui->label_guid1_3->setText("size and inThe amount is displayed at the top");
        ui->label_guid1_4->setText("of the game screen. You can plant your corn by");
        ui->label_guid1_5->setText("clicking on the corn icon and moving it to the");
        ui->label_guid1_6->setText("ground.");
        ui->label_guid1_7->setText("Note: buying corn will be 2 coins and collecting");
        ui->label_guid1_8->setText("corn will be 2 coins and will not have any benefit");
        ui->label_guid1_9->setText("in game points.");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("image: url(:/new/prefix1/imagfil/storshop.png)");
        ui->label_butcher->setStyleSheet("image: url(:/new/prefix1/imagfil/corn.png)");
    }
    else if(line.contains(Search_wheat)||line.contains("Wheat")){
        ui->label_guid1->setText("By buying wheat seeds from the store,");
        ui->label_guid1_2->setText("the amount of wheat is added to the purchased");
        ui->label_guid1_3->setText("size and inThe amount is displayed at the top");
        ui->label_guid1_4->setText("of the game screen. You can plant your wheat by");
        ui->label_guid1_5->setText("clicking on the wheat icon and moving it to the");
        ui->label_guid1_6->setText("ground.");
        ui->label_guid1_7->setText("Note: By buying and cultivating");
        ui->label_guid1_8->setText("this product, you will earn 1 coin.");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("image: url(:/new/prefix1/imagfil/storshop.png)");
        ui->label_butcher->setStyleSheet("image: url(:/new/prefix1/imagfil/wheat.png)");
    }
    else if(line.contains("milk")||line.contains("Milk")){
        ui->label_guid1->setText("Milk is one of the products that");
        ui->label_guid1_2->setText("can be harvested from sheep and cows.");
        ui->label_guid1_3->setText("You will earn 5 coins for collecting");
        ui->label_guid1_4->setText("cow milk and 4 coins for sheep milk.");
        ui->label_guid1_5->setText("You can collect the milk by clicking");
        ui->label_guid1_6->setText("on the basket icon.");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains("meat")||line.contains("Meat")){
        ui->label_guid1->setText("Meat is a harvestable product from");
        ui->label_guid1_2->setText("all animals in the game. You can collect");
        ui->label_guid1_3->setText("its meat by killing the said animal");
        ui->label_guid1_4->setText("and 6 coins for the meat of each cow");
        ui->label_guid1_5->setText("Sheep meat 4 coins");
        ui->label_guid1_6->setText("And chicken meat 3 coins.");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains("egg")||line.contains("Egg")){
        ui->label_guid1->setText("Eggs are a product obtained from chickens,");
        ui->label_guid1_2->setText("which produce one egg every 20 seconds by ");
        ui->label_guid1_3->setText("raising chickens in the ground.");
        ui->label_guid1_4->setText("And after collecting 3 coins you");
        ui->label_guid1_5->setText("will profit.");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains(Search_cow)||line.contains("Cow")){
        ui->label_guid1->setText("By buying a cow from the store,");
        ui->label_guid1_2->setText("the cow is transferred to the cow");
        ui->label_guid1_3->setText("house until you breed it!");
        ui->label_guid1_4->setText("The cow is not taken off the ground");
        ui->label_guid1_5->setText("until it is killed.");
        ui->label_guid1_6->setText("The cow gives two products, milk and");
        ui->label_guid1_7->setText("meat, which you will harvest every 20 ");
        ui->label_guid1_8->setText("seconds during breeding, and each milk");
        ui->label_guid1_9->setText("product will be worth 5 coins.");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("image: url(:/new/prefix1/imagfil/storshop.png)");
        ui->label_butcher->setStyleSheet("image: url(:/new/prefix1/imagfil/6859854.png)");
    }
    else if(line.contains(Search_sheep)||line.contains("Sheep")){
        ui->label_guid1->setText("By buying a sheep from the store,");
        ui->label_guid1_2->setText("you can breed it in the fields by ");
        ui->label_guid1_3->setText("selecting the sheep icon at the top");
        ui->label_guid1_4->setText("of the game screen.");
        ui->label_guid1_5->setText("A sheep is killed only when it is taken");
        ui->label_guid1_6->setText("off the ground and it has two products:");
        ui->label_guid1_7->setText("milk and meat, its milk is 4 coins and");
        ui->label_guid1_8->setText("its meat is 4 coins.");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("image: url(:/new/prefix1/imagfil/storshop.png)");
        ui->label_butcher->setStyleSheet("image: url(:/new/prefix1/imagfil/371725.png)");
    }
    else if(line.contains(Search_chicken)||line.contains("Chicken")){
        ui->label_guid1->setText("By buying chicken from the store,");
        ui->label_guid1_2->setText("the chickens are kept in the chicken");
        ui->label_guid1_3->setText("house until they go to the land for");
        ui->label_guid1_4->setText("breeding, and there is only one way ");
        ui->label_guid1_5->setText("to empty the said land, and that is to ");
        ui->label_guid1_6->setText("kill the chicken.");
        ui->label_guid1_7->setText("Chicken has two products, egg and meat,");
        ui->label_guid1_8->setText("where the egg is 3 coins and the meat is 2 coins");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("image: url(:/new/prefix1/imagfil/storshop.png)");
        ui->label_butcher->setStyleSheet("image: url(:/new/prefix1/imagfil/3773808.png)");

    }
    else if(line.contains(Search_Delay)||line.contains(Search_Late)||line.contains("Delay")||line.contains("Late")){
        ui->label_guid1->setText("In case of decrease, one coin will be deducted");
        ui->label_guid1_2->setText("from the value of the product every 5 seconds");
        ui->label_guid1_3->setText("until the price of the product is zero");
        ui->label_guid1_4->setText("");
        ui->label_guid1_5->setText("");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains("worker")||line.contains("Worker")){
        ui->label_guid1->setText("By buying a laborer and planting");
        ui->label_guid1_2->setText("seeds or raising an animal, the laborer");
        ui->label_guid1_3->setText("will work and go to the selected land and");
        ui->label_guid1_4->setText("will be in the land until the crop is");
        ui->label_guid1_5->setText("harvested or the animal is killed.");
        ui->label_guid1_6->setText("Note: The worker will not be sold in any way.");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_images/guid_worker.jpg)");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains("land")||line.contains("Land")){
        ui->label_guid1->setText("You can buy a land by clicking");
        ui->label_guid1_2->setText("on the lock icon.");
        ui->label_guid1_3->setText("It is possible to grow seeds and");
        ui->label_guid1_4->setText("raise animals in the land.");
        ui->label_guid1_5->setText("Each field costs 3 coins and the");
        ui->label_guid1_6->setText("field will not be sold until the");
        ui->label_guid1_7->setText("end of the game.");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_land/guid_sheep.jpg)");
        ui->label_land->setStyleSheet("image: url(:/new/prefix1/imagfil/look.png)");
        ui->label_butcher->setStyleSheet("");
    }
    else if(line.contains("coin")||line.contains("Corn")){
        ui->label_guid1->setText("You have 10 coins at the beginning");
        ui->label_guid1_2->setText("of the game, you can buy all the items");
        ui->label_guid1_3->setText("in the store with coins, and you can");
        ui->label_guid1_4->setText("also buy land and workers.");
        ui->label_guid1_5->setText("At the time of withdrawal you will");
        ui->label_guid1_6->setText("withdraw coins.");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("border-image: url(:/new/prefix1/guid_coin/guid_sheep.jpg)");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");

    }
    else if(line.contains("play")||line.contains("Play")){
        ui->label_guid1->setText("This game will be multiplayer,");
        ui->label_guid1_2->setText("you can specify the number of ");
        ui->label_guid1_3->setText("players at the beginning of the game.");
        ui->label_guid1_4->setText("The game time for each player");
        ui->label_guid1_5->setText("is 3 minutes and you have to get");
        ui->label_guid1_6->setText("your maximum points from the game");
        ui->label_guid1_7->setText("to win the game.");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }else {
        ui->label_guid1->setText("Oops!");
        ui->label_guid1_2->setText("");
        ui->label_guid1_3->setText("");
        ui->label_guid1_4->setText("");
        ui->label_guid1_5->setText("");
        ui->label_guid1_6->setText("");
        ui->label_guid1_7->setText("");
        ui->label_guid1_8->setText("");
        ui->label_guid1_9->setText("");
        ui->label_image->setStyleSheet("");
        ui->label_land->setStyleSheet("");
        ui->label_butcher->setStyleSheet("");
    }
}

