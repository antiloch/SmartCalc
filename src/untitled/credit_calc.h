#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QDialog>

namespace Ui {
class Credit_calc;
}

class Credit_calc : public QDialog
{
    Q_OBJECT

public:
    explicit Credit_calc(QWidget *parent = nullptr);
    ~Credit_calc();

private slots:
    void on_Calc_clicked();

private:
    Ui::Credit_calc *ui;
};

#endif // CREDIT_CALC_H
