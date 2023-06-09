#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graph.h>
#include <credit_calc.h>

extern "C" {
#include "../calculate.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void expression();

    void expression_dif();

    void on_pushButton_clean_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_equal_clicked();

    void on_graph_triggered();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_action_triggered();


private:
    Ui::MainWindow *ui;
    Graph *form;

signals:
    void signal(char *);

};
#endif // MAINWINDOW_H
