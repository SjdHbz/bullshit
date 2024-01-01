#ifndef CHICKEN_H
#define CHICKEN_H

#include <QMainWindow>

namespace Ui {
class chicken;
}

class chicken : public QMainWindow
{
    Q_OBJECT

public:
    explicit chicken(QWidget *parent = nullptr);
    ~chicken();

private:
    Ui::chicken *ui;
};

#endif // CHICKEN_H
