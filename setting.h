#ifndef SETTING_H
#define SETTING_H

#include <QMainWindow>
#include "QMediaPlayer"
namespace Ui {
class setting;
}

class setting : public QMainWindow
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = nullptr);
    ~setting();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_username_clicked();

    void on_pushButton_Password_clicked();

    void on_pushButton_Phone_clicked();

private:
    Ui::setting *ui;
    QMediaPlayer *music = new QMediaPlayer;
    QString Email[10],email[10];
    QString Password[10],password[10];
    int players=0;
    int key=0;

};

#endif // SETTING_H
