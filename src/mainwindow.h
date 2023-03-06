#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <defoltwindow.h>
#include <creditwindow.h>
#include <depositwindow.h>

//QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    defoltwindow *sWindow;
    creditwindow *crWindow;
    depositwindow *dpWindow;
};
#endif // MAINWINDOW_H
