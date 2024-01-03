#ifndef PAGE2_H
#define PAGE2_H
#include <QTime>
#include <QTimer>
#include <QMainWindow>
#include <QElapsedTimer>
namespace Ui {
class page2;
}

class page2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = nullptr);
     QTimer *timer;
     QElapsedTimer elapsedTimer;
    ~page2();

private slots:
    void updateTime();

    void on_pushButton_3_clicked();

    void on_pushButton__clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::page2 *ui;

};

#endif // PAGE2_H
