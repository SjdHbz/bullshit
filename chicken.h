#ifndef CHICKEN_H
#define CHICKEN_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class chicken;
}

class chicken : public QMainWindow
{
    Q_OBJECT

public:
    explicit chicken(QWidget *parent = nullptr);
    ~chicken();

private slots:
    void on_toolButton_clicked();

private:
    Ui::chicken *ui;
    QMediaPlayer *player = new
    QMediaPlayer;
};

#endif // CHICKEN_H
