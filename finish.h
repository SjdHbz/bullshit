#ifndef FINISH_H
#define FINISH_H

#include <QMainWindow>

namespace Ui {
class finish;
}

class finish : public QMainWindow
{
    Q_OBJECT

public:
    explicit finish(QWidget *parent = nullptr);
    ~finish();

private:
    Ui::finish *ui;
};

#endif // FINISH_H
