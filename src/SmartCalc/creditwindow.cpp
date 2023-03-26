#include "creditwindow.h"

#include "ui_creditwindow.h"

creditwindow::creditwindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::creditwindow) {
  creditwindow::setFixedSize(631, 626);
  ui->setupUi(this);
}

creditwindow::~creditwindow() { delete ui; }

void creditwindow::on_pushButton_clicked() {
  this->close();        // Закрываем окно
  emit secondWindow();  //
}

void creditwindow::on_result_clicked() {
  std::string str_sum = ui->sumcredit->text().toStdString();
  char *sum = &str_sum[0];
  std::string str_month = ui->month->text().toStdString();
  char *month = &str_month[0];
  std::string str_procent = ui->procent->text().toStdString();
  char *procent = &str_procent[0];

  double overpayment = 0;
  double totalSum = 0;
  double sums = atof(sum);
  double months = atof(month);
  double procents = (atof(procent) / 100) / 12;
  QString new_label = "";

  if (ui->diferens->isChecked()) {
    double d = sums / months;
    double S = 0.0;
    int n = months;
    int numberMonth = n;

    for (int i = 0; i < n; i++) {
      S = differentiatedСredit(&sums, &months, &procents, &d);
      months--;
      QString num1 = QString::number(S, 'f', 2);
      QString qw = QString::number(numberMonth);
      totalSum = totalSum + S;
      new_label = new_label + num1 + " | " + qw + "month" + '\n';
      numberMonth--;
    }

    overpayment = totalSum - sums;
    QString num2 = QString::number(overpayment, 'f', 2);
    QString num3 = QString::number(totalSum, 'f', 2);

    ui->resultMonthly->setText(new_label);
    ui->resultMonthly_2->setText(num2);
    ui->resultMonthly_3->setText(num3);
  }
  if (ui->anuitetni->isChecked()) {
    sums = annuityСredit(&sums, &months, &procents, &overpayment, &totalSum);

    QString num1 = QString::number(sums, 'f', 2);
    QString num2 = QString::number(overpayment, 'f', 2);
    QString num3 = QString::number(totalSum, 'f', 2);

    ui->resultMonthly->setText(num1);
    ui->resultMonthly_2->setText(num2);
    ui->resultMonthly_3->setText(num3);
  }
}
