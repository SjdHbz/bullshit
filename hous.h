#ifndef HOUS_H
#define HOUS_H

#include <QMainWindow>

namespace Ui {
class hous;
}

class hous : public QMainWindow
{
    Q_OBJECT

public:
    explicit hous(QWidget *parent = nullptr);
    ~hous();

private:
    Ui::hous *ui;
};

#endif // HOUS_H
