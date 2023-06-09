#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_arcsin, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_arccos, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_arctan, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_open_braket, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_close_braket, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(expression_dif()));
    connect(ui->pushButton_power, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(expression()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(expression()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::expression()
{
    QPushButton *button = (QPushButton *)sender();

    QString label_expression = (ui->label_main->text() + button->text());

    ui->label_main->setText(label_expression);
    ui->label_result->setText("");
}

void MainWindow::expression_dif()
{
    QPushButton *button = (QPushButton *)sender();

    QString label_expression = (ui->label_main->text() + button->text() + "(");

    ui->label_main->setText(label_expression);
    ui->label_result->setText("");
}

void MainWindow::on_pushButton_clean_clicked()
{
    ui->label_main->setText("");
    ui->label_result->setText("");
}


void MainWindow::on_pushButton_backspace_clicked()
{
    QString label_expression = (ui->label_main->text());
    ui->label_main->setText(label_expression.left(label_expression.size() - 1));
    ui->label_result->setText("");
}


void MainWindow::on_pushButton_equal_clicked()
{
    std::string s =ui->label_main->text().toStdString();
    char* c_strs = const_cast<char*>(s.c_str());
    double result = 0;
    bool ok = true;
    double var = ui->lineEdit->text().toDouble(&ok);
    if (!ok) var = 0;
    int status = calculate(c_strs, &result, var);
    QString result_str = QString::number(result, 'g', 7);
    ui->label_result->setText(result_str);
    if (status == 0 || !ok) {
        ui->label_result->setText("Error");
    }
}


void MainWindow::on_graph_triggered()
{
    form = new Graph;
    form->show();

    connect(this, &MainWindow::signal, form, &Graph::slot);

    std::string s =ui->label_main->text().toStdString();
    char* str = const_cast<char*>(s.c_str());

    emit signal(str);
//    Graph window;
//    window.setModal(true);
//    window.exec();

}

