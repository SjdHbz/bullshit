#ifndef LAND_H
#define LAND_H

#include <QMainWindow>

namespace Ui {
class land;
}

class land : public QMainWindow
{
    Q_OBJECT

public:
    explicit land(QWidget *parent = nullptr);
    ~land();

private slots:


    void on_spinBox_land_valueChanged(int arg1);

    void on_spinBox_worker_valueChanged(int arg1);

    void on_pushButton_land_clicked();

    void on_pushButton_worker_clicked();

    void on_pushButton_clicked();

private:
    Ui::land *ui;
};

#endif // LAND_H
