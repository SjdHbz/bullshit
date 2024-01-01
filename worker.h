#ifndef WORKER_H
#define WORKER_H

#include <QMainWindow>

namespace Ui {
class worker;
}

class worker : public QMainWindow
{
    Q_OBJECT

public:
    explicit worker(QWidget *parent = nullptr);
    ~worker();

private:
    Ui::worker *ui;
};

#endif // WORKER_H
