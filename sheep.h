#ifndef SHEEP_H
#define SHEEP_H
#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class sheep;
}

class sheep : public QMainWindow
{
    Q_OBJECT

public:
    explicit sheep(QWidget *parent = nullptr);
    ~sheep();


private slots:
    void on_toolButton_clicked();

private:
    Ui::sheep *ui;
    QMediaPlayer *player = new
    QMediaPlayer;
};

#endif // SHEEP_H
