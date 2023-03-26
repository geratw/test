#include "form.h"

#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
  Form::setFixedSize(732, 537);
  ui->setupUi(this);
}

Form::~Form() { delete ui; }

void Form::slot(QString a, QString Xmin, QString Xmax, QString Ymin,
                QString Ymax) {
  ui->label->setText(a);
  std::string str0 = a.toStdString();
  char *strRes = &str0[0];
  std::string str = Xmin.toStdString();
  char *startX = &str[0];
  std::string str1 = Xmax.toStdString();
  char *finishX = &str1[0];
  std::string str2 = Ymin.toStdString();
  char *startY = &str2[0];
  std::string str3 = Ymax.toStdString();
  char *finishY = &str3[0];

  double MinX = atof(startX);
  double MaxX = atof(finishX);
  double MinY = atof(startY);
  double MaxY = atof(finishY);
  if (Xmin < Xmax && Ymin < Ymax) {
    double h = (MaxX - MinX) / 500;
    int N = (MaxX - MinX) / h + 1;
    QVector<double> x(N), y(N);
    int i = 0;

    for (double X = MinX; X <= MaxX; X += h) {
      double Y = 0;
      double error = start(strRes, &Y, X);

      if (error && Y <= MaxY && Y >= MinY) {
        x[i] = X;
        ui->statusBar->setText("success");
        y[i] = Y;
        i++;
      } else {
        ui->statusBar->setText("fail");
      }
    }
    ui->graf->clearGraphs();

    ui->graf->addGraph();

    ui->graf->graph(0)->setData(x, y);

    ui->graf->xAxis->setLabel("x");
    ui->graf->yAxis->setLabel("y");

    ui->graf->xAxis->setRange(MinX, MaxX);  //Для оси Ox

    //    double minY = y[0], maxY = y[0];
    //    for (int i = 1; i < N; i++) {
    //      if (y[i] < minY) minY = y[i];
    //      if (y[i] > maxY) maxY = y[i];
    //    }
    ui->graf->yAxis->setRange(MinY, MaxY);

    ui->graf->replot();
  }
}

void Form::on_pushButton_clicked() {
  this->close();  // Закрываем окно
  emit signal();  // И вызываем сигнал на открытие главного окна
}
