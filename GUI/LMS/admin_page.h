#ifndef ADMIN_PAGE_H
#define ADMIN_PAGE_H

#include <QDialog>

namespace Ui {
class admin_page;
}

class admin_page : public QDialog
{
    Q_OBJECT

public:
    explicit admin_page(QWidget *parent = nullptr);
    ~admin_page();

private:
    Ui::admin_page *ui;
};

#endif // ADMIN_PAGE_H
