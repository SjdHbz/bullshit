#ifndef COW_H
#define COW_H

#include <QMainWindow>

namespace Ui {
class cow;
}

class cow : public QMainWindow
{
    Q_OBJECT

public:
    explicit cow(QWidget *parent = nullptr);
    ~cow();

private:
    Ui::cow *ui;
};

#endif // COW_H
