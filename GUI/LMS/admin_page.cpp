#include "admin_page.h"
#include "ui_admin_page.h"

admin_page::admin_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_page)
{
    ui->setupUi(this);
}

admin_page::~admin_page()
{
    delete ui;
}
