#include<iostream>
#include<QDebug>

#include "login.h"
#include "ui_login.h"


login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

//void login::on_pushButton_login_clicked()
//{
////    Qstring entered_username = ui->lineEdit_id->text().toLower();
////    Qstring entered_password = ui->lineEdit_password->text();
//}

