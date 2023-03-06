#include "defoltwindow.h"
#include "ui_defoltwindow.h"

defoltwindow::defoltwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::defoltwindow)
{
    ui->setupUi(this);


        connect(ui->num0,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num1,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num2,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num3,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num4,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num5,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num6,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num7,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num8,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->num9,SIGNAL(clicked()),this, SLOT(digit_numbers()));
        connect(ui->plus,SIGNAL(clicked()),this, SLOT(math_operations()));
        connect(ui->minus,SIGNAL(clicked()),this, SLOT(math_operations()));
        connect(ui->division,SIGNAL(clicked()),this, SLOT(math_operations()));
        connect(ui->mult,SIGNAL(clicked()),this, SLOT(math_operations()));
        connect(ui->ButtonPow,SIGNAL(clicked()),this, SLOT(math_operations()));
        connect(ui->ButtonMod,SIGNAL(clicked()),this,SLOT(math_operations()));
        connect(ui->ButtonSin,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonAsin,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonCos,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonAcos,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonTan,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonAtan,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonLn,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonLog,SIGNAL(clicked()), this,SLOT(functions()));
        connect(ui->ButtonPoint,SIGNAL(clicked()), this,SLOT(on_ButtonPoint_clicked()));
        connect(ui->Button_LeftBracket,SIGNAL(clicked()),this, SLOT(math_operations()));
        connect(ui->Button_RightBracket,SIGNAL(clicked()),this, SLOT(math_operations()));
        connect(ui->result,SIGNAL(clicked()),this, SLOT(pushString()));
}

defoltwindow::~defoltwindow()
{
    delete ui;
}

void defoltwindow::on_Back_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); //
}



void defoltwindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_0) {
       QString new_label = ui->result_number->text() + "0";
         ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_1) {
        QString new_label = ui->result_number->text() + "1";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_2) {
        QString new_label = ui->result_number->text() + "2";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_3) {
        QString new_label = ui->result_number->text() + "3";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_4) {
        QString new_label = ui->result_number->text() + "4";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_5) {
        QString new_label = ui->result_number->text() + "5";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_6) {
        QString new_label = ui->result_number->text() + "6";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_7) {
        QString new_label = ui->result_number->text() + "7";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_8) {
        QString new_label = ui->result_number->text() + "8";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_9) {
        QString new_label = ui->result_number->text() + "9";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_Plus) {
        QString new_label = ui->result_number->text() + "+";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_Minus) {
        QString new_label = ui->result_number->text() + "-";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_Slash) {
        QString new_label = ui->result_number->text() + "/";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_Asterisk) {
        QString new_label = ui->result_number->text() + "*";
          ui->result_number->setText(new_label);
    } else if (e->key() == Qt::Key_Backspace) {
          ui->result_number->setText("");
    } else if (e->key() == Qt::Key_Enter) {
        pushString();
  }
}

void defoltwindow::digit_numbers() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label = ui->result_number->text() + button->text();

  ui->result_number->setText(new_label);
}

void defoltwindow::math_operations() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;

  new_label = ui->result_number->text();

  if (button->text() == "/" && !(ui->result_number->text().endsWith("/")) &&
      !(ui->result_number->text().endsWith("/"))) {
    new_label += "/";
  } else if (button->text() == "*" &&
             !(ui->result_number->text().endsWith("*")) &&
             !(ui->result_number->text().endsWith("*"))) {
    new_label += "*";
  } else if (button->text() == "+" &&
             !(ui->result_number->text().endsWith("+"))) {
    new_label += "+";
  } else if (button->text() == "-" &&
             !(ui->result_number->text().endsWith("-"))) {
    new_label += "-";
  } else if (button->text() == "pow" &&
             !(ui->result_number->text().endsWith("^"))) {
    new_label += "^";
  } else if (button->text() == "mod" &&
             !(ui->result_number->text().endsWith("%"))) {
    new_label += "%";
  } else if (button->text() == "(") {
    new_label += "(";
  } else if (button->text() == ")") {
    new_label += ")";
  }

  ui->result_number->setText(new_label);
}

void defoltwindow::functions() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;

  new_label = ui->result_number->text() + button->text() + "(";

  ui->result_number->setText(new_label);
}

void defoltwindow::on_delete_2_clicked()
{
    ui->result_number->setText("");
}


//void MainWindow::s21_on_pushButton_X_clicked() {
//  QString new_label;

//  if (!(ui->result_number->text().endsWith("x")))
//    new_label = ui->result_number->text() + "x";

//  ui->result_text->setText(new_label);
//}

void defoltwindow::on_ButtonPoint_clicked()
{
    if (!(ui->result_number->text().endsWith('.')))
        ui->result_number->setText(ui->result_number->text() + ".");
}

void defoltwindow::pushString()
{
//    std::string str = ui->result_number->text().toStdString();
//        char *expression = &str[0];


//        char *a = resultcredit(expression);
//        QString q = QString::fromLocal8Bit(a);
//        ui->result_number->setText(q);

                ui->result_number->setText("1");
}




