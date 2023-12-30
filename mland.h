#ifndef MLAND_H
#define MLAND_H

#include <QMainWindow>

namespace Ui {
class mland;
}

class mland : public QMainWindow
{
    Q_OBJECT

public:
    explicit mland(QWidget *parent = nullptr);
    ~mland();

private:
    Ui::mland *ui;
};

#endif // MLAND_H
