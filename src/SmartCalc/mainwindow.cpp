#include "mainwindow.h"

#include <QPixmap>

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  MainWindow::setFixedSize(999, 370);
  ui->setupUi(this);
  QPixmap kavai_1(":/imga/img/kavai_3.png");
  int w1 = ui->kavai_1->width();
  int h1 = ui->kavai_1->height();
  ui->kavai_1->setPixmap(kavai_1.scaled(w1, h1, Qt::KeepAspectRatio));

  QPixmap kavai_2(":/imga/img/kavai_1.jpeg");
  int w2 = ui->kavai_2->width();
  int h2 = ui->kavai_2->height();
  ui->kavai_2->setPixmap(kavai_2.scaled(w2, h2, Qt::KeepAspectRatio));

  sWindow = new defoltwindow();
  // подключаем к слоту запуска главного окна по кнопке во втором окне
  connect(sWindow, &defoltwindow::firstWindow, this, &MainWindow::show);

  crWindow = new creditwindow();
  // подключаем к слоту запуска главного окна по кнопке во втором окне
  connect(crWindow, &creditwindow::secondWindow, this, &MainWindow::show);

  dpWindow = new depositwindow();
  // подключаем к слоту запуска главного окна по кнопке во втором окне
  connect(dpWindow, &depositwindow::thirdWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  sWindow->show();  // Показываем второе окно
  this->close();    // Закрываем основное окно
}

void MainWindow::on_pushButton_2_clicked() {
  crWindow->show();  // Показываем второе окно
  this->close();     // Закрываем основное окно
}

void MainWindow::on_pushButton_3_clicked() {
  dpWindow->show();  // Показываем второе окно
  this->close();
}
