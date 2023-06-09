#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>

extern "C" {
#include "../calculate.h"
}
//#include <mainwindow.h>




namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    char* c_strs;
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

public slots:
    void slot(char *str);
    void on_pushButton_clicked();

private:
    Ui::Graph *ui;
    double x_begin, y_begin, x_end, y_end, step;
    QVector<double>x,y;
};

#endif // GRAPH_H
