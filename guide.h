#ifndef GUIDE_H
#define GUIDE_H

#include <QMainWindow>

namespace Ui {
class Guide;
}

class Guide : public QMainWindow
{
    Q_OBJECT

public:
    explicit Guide(QWidget *parent = nullptr);
    ~Guide();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Guide *ui;
};

#endif // GUIDE_H
