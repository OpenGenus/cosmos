#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private:
    Ui::Dialog *ui;
protected:
    void paintEvent(QPaintEvent *E);
private slots:
    void on_Dialog_accepted();
    void on_pushButton_clicked();
};
class Hola{


};
#endif // DIALOG_H
