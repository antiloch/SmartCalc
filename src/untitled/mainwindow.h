#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_clean_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_equal_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
