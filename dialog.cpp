#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPixmap im("C:\\resources\\truth.png");
    ui->label->setPixmap(im);
}

Dialog::~Dialog()
{
    delete ui;
}
