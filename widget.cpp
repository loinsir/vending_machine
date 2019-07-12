#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false); //homework
    ui->pbTea->setEnabled(false);
    ui->pbGong->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));

    QMessageBox msg;


    if (money >= 200) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGong->setEnabled(true);
    }
    else if (money >= 150 && money < 200) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGong->setEnabled(false);
    }
    else if (money >= 100 && money < 150) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
    }
    else {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbGong->setEnabled(false);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbGong_clicked()
{
    changeMoney(-200);
}

void Widget::on_return_btn_clicked()
{
    QMessageBox returnmsg;
    int coin[4] = {0,};

    for (int i = 0; money > 0; i++){
        if(money / 500 > 0){
            ++coin[0];
            money -= 500;
            continue;
        }
        else if (money / 100 > 0) {
            ++coin[1];
            money -= 100;
            continue;
        }
        else if (money / 50 > 0) {
            ++coin[2];
            money -= 50;
            continue;
        }
        else if (money / 10 > 0) {
            ++coin[3];
            money -= 10;
            continue;
        }
    }

    returnmsg.information(nullptr, "Return", "500: " + QString::number(coin[0]) + "\n100: " + QString::number(coin[1]) + "\n50:" + QString::number(coin[2])+ "\n10:" + QString::number(coin[3]));
    ui->lcdNumber->display(money);
    for (int i=0; i < 4 ; i++) {
        coin[i] = 0;
    }
}
