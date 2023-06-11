#include "credit_calc.h"
#include "ui_credit_calc.h"

Credit_calc::Credit_calc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit_calc)
{
    ui->setupUi(this);
}

Credit_calc::~Credit_calc()
{
    delete ui;
}

void Credit_calc::on_Calc_clicked()
{
    if (ui->type_diff->isChecked()) {
        double credit_sum = ui->credit_sum->text().toDouble();
        double credit_percent = ui->credit_percent->text().toDouble() / 100;
        int credit_time = ui->credit_time->text().toDouble() * 12;

        double first_payment = credit_sum * credit_percent / 12 + credit_sum / credit_time;
        double last_payment = (credit_sum / credit_time) * (1 + credit_percent / 12);

        double payment_sum = 0;
        double payment = credit_sum / credit_time;
        double obligation = credit_sum;
        for (int month = 0; month < credit_time; month++) {
            payment_sum += payment + obligation * credit_percent / 12;
            obligation -= payment;
        }
        ui->all_payings->setText(QString::number(payment_sum, 'f', 2));
        ui->month_payment->setText(QString::number(first_payment, 'f', 2) + " ... " + QString::number(last_payment, 'f', 2));
        ui->pereplata->setText(QString::number(payment_sum - credit_sum, 'f', 2));
    }
    else if (ui->type_annual->isChecked()) {
        double credit_sum = ui->credit_sum->text().toDouble();
        double credit_percent = ui->credit_percent->text().toDouble() / 100;
        int credit_time = ui->credit_time->text().toDouble() * 12;

        double payment = credit_sum * pow((1 + credit_percent / 12), credit_time) * (credit_percent / 12) / (pow((1 + credit_percent / 12), credit_time) - 1);
        payment -= payment / 1000;
        double payment_sum = payment * credit_time;

        ui->all_payings->setText(QString::number(payment_sum, 'f', 2));
        ui->month_payment->setText(QString::number(payment, 'f', 2));
        ui->pereplata->setText(QString::number(payment_sum - credit_sum, 'f', 2));


    } else {
        ui->all_payings->setText("Chose payment type");
        ui->month_payment->setText("Chose payment type");
        ui->pereplata->setText("Chose payment type");
    }
}

