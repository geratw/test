#include "depositwindow.h"

#include "ui_depositwindow.h"

depositwindow::depositwindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::depositwindow) {
  depositwindow::setFixedSize(621, 711);
  ui->setupUi(this);
}

depositwindow::~depositwindow() { delete ui; }

void depositwindow::on_pushButton_clicked() {
  this->close();       // Закрываем окно
  emit thirdWindow();  //
}
