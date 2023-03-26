#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QDialog>

extern "C" {
#include "resultCredit.h"
}

namespace Ui {
class creditwindow;
}

class creditwindow : public QDialog {
  Q_OBJECT

 public:
  explicit creditwindow(QWidget *parent = nullptr);
  ~creditwindow();

 signals:
  void secondWindow();  // Сигнал для второго окна на открытие

 private slots:
  void on_pushButton_clicked();

  void on_result_clicked();

 private:
  Ui::creditwindow *ui;
};

#endif  // CREDITWINDOW_H
