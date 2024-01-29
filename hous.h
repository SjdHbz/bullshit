#ifndef HOUS_H
#define HOUS_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class hous;
}

class hous : public QMainWindow
{
    Q_OBJECT

public:
    explicit hous(QWidget *parent = nullptr);
    ~hous();

private slots:
    void outcoin(int coin);

    int incoin();

//    void on_pushButton_chicken_clicked();

//    void on_spinBox_chicken_valueChanged(int arg1);

//    void on_pushButton_cow_clicked();

//    void on_spinBox_cow_valueChanged(int arg1);

//    void on_pushButton_sheep_clicked();

//    void on_spinBox_sheep_valueChanged(int arg1);

    void on_toolButton_clicked();

private:
    Ui::hous *ui;
    QMediaPlayer *player = new
    QMediaPlayer;
};

#endif // HOUS_H
