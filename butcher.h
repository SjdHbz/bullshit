#ifndef BUTCHER_H
#define BUTCHER_H

#include <QMainWindow>

namespace Ui {
class Butcher;
}

class Butcher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Butcher(QWidget *parent = nullptr);
    ~Butcher();

private slots:
    void outcoin(int coin);

    int incoin();

    void on_pushButton_kill_Chicken_clicked();

    void on_pushButton_kill_cow_clicked();

    void on_pushButton_kill_Sheep_clicked();

private:
    Ui::Butcher *ui;
};

#endif // BUTCHER_H
