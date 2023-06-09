#include "graph.h"
#include "ui_graph.h"
#include "ui_mainwindow.h"

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
}

Graph::~Graph()
{
    delete ui;
}

void Graph::slot(char *str)
{
    ui->expression->setText(str);
}

void Graph::on_pushButton_clicked()
{

    x_begin = ui->x_begin->value();
    x_end = ui->x_end->value();
    y_begin = ui->y_begin->value();
    y_end = ui->y_end->value();

    step = (x_end - x_begin) / 1000;
    ui->widget->xAxis->setRange(x_begin, x_end);
    ui->widget->yAxis->setRange(y_begin, y_end);

    double result = 0;
    int status = 1;
    std::string s =ui->expression->text().toStdString();
    char* c_strs = const_cast<char*>(s.c_str());
//    char* c_strs = "x^2";

    for(double current_x = x_begin; current_x < x_end || status == 0; current_x += step)
    {
        status = calculate(c_strs, &result, current_x);
        x.push_back(current_x);
        y.push_back(result);
    }

    if (status == 1) {
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x,y);
        ui->widget->replot();
    }
}

