#ifndef COW_H
#define COW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class cow;
}

class cow : public QMainWindow
{
    Q_OBJECT

public:
    explicit cow(QWidget *parent = nullptr);
    ~cow();

private slots:
    void on_toolButton_clicked();

private:
    Ui::cow *ui;
    QMediaPlayer *player = new
    QMediaPlayer;
};

#endif // COW_H
