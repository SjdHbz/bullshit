#ifndef MLAND_H
#define MLAND_H

#include <QMainWindow>
#include <QMediaPlayer>
namespace Ui {
class mland;
}

class mland : public QMainWindow
{
    Q_OBJECT

public:
    explicit mland(QWidget *parent = nullptr);
    ~mland();

private slots:
    void on_toolButton_clicked();

private:
    Ui::mland *ui;
    QMediaPlayer *player = new
    QMediaPlayer;
};

#endif // MLAND_H
