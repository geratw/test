#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QDialog>

namespace Ui {
class depositwindow;
}

class depositwindow : public QDialog {
  Q_OBJECT

 public:
  explicit depositwindow(QWidget *parent = nullptr);
  ~depositwindow();

 signals:
  void thirdWindow();  // Сигнал для первого окна на открытие

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::depositwindow *ui;
};

#endif  // DEPOSITWINDOW_H
