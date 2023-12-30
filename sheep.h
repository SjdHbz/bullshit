#ifndef SHEEP_H
#define SHEEP_H
#include <QMainWindow>
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
    void on_pushButton_sheep_clicked();

private:
    Ui::sheep *ui;
};

#endif // SHEEP_H
