#include "creditwindow.h"
#include "ui_creditwindow.h"

creditwindow::creditwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creditwindow)
{
    ui->setupUi(this);
}

creditwindow::~creditwindow()
{
    delete ui;
}

void creditwindow::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow(); //
}


void creditwindow::on_result_clicked()
{
    std::string str_sum = ui->sumcredit->text().toStdString();
    char *sum = &str_sum[0];
    std::string str_month = ui->month->text().toStdString();
    char *month = &str_month[0];
    std::string str_procent = ui->procent->text().toStdString();
    char *procent = &str_procent[0];

    int checkRadioButtton = 0;
    double overpayment = 0;
    double totalSum = 0;
    double sums = 0;

    if (ui->diferens->isChecked()) {
        checkRadioButtton = 0;
    }
    if (ui->anuitetni->isChecked()) {
        sums = annuityСredit(sum, month, procent, &overpayment, &totalSum);
    }




    QString num1 = QString::number(sums, 'f', 2);
    QString num2 = QString::number(overpayment, 'f', 2);
    QString num3 = QString::number(totalSum, 'f', 2);
    QString num4 = QString::number(checkRadioButtton, 'f', 2);

    ui->resultMonthly->setText(num1);
    ui->resultMonthly_2->setText(num2);
    ui->resultMonthly_3->setText(num3);
    ui->y_4->setText(num4);
}

