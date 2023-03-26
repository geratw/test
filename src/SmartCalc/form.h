#ifndef FORM_H
#define FORM_H

#include <QVector>
#include <QWidget>
#include <QtMath>

extern "C" {
#include "new.h"
}

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

 public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();

 signals:
  void signal();  // пробую удали нахуй

 private:
  Ui::Form *ui;

 public slots:
  void slot(QString a, QString Xmin, QString Xmax, QString Ymin, QString Ymax);

 private slots:
  void on_pushButton_clicked();
};

#endif  // FORM_H
