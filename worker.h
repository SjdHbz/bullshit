#ifndef WORKER_H
#define WORKER_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class worker;
}

class worker : public QMainWindow
{
    Q_OBJECT

public:
    explicit worker(QWidget *parent = nullptr);
    ~worker();

private slots:
    void on_toolButton_clicked();

private:
    Ui::worker *ui;
    QMediaPlayer *player = new
    QMediaPlayer;
};

#endif // WORKER_H
