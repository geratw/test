#ifndef DEFOLTWINDOW_H
#define DEFOLTWINDOW_H

#include <QDialog>
#include <QKeyEvent>

extern "C" {
#include "resultCredit.h"
}


namespace Ui {
class defoltwindow;
}

class defoltwindow : public QDialog
{
    Q_OBJECT

public:
    explicit defoltwindow(QWidget *parent = nullptr);
    ~defoltwindow();

protected:
    void keyPressEvent(QKeyEvent *e) override;

signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    void on_Back_clicked();
    void digit_numbers();
    void math_operations();
    void functions();
    void on_delete_2_clicked();
    void on_ButtonPoint_clicked();
    void pushString();

private:
    Ui::defoltwindow *ui;
};

#endif // DEFOLTWINDOW_H

