#include "adusermandialog.h"
#include "ui_adusermandialog.h"

adUserManDialog::adUserManDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adUserManDialog)
{
    ui->setupUi(this);
}

adUserManDialog::~adUserManDialog()
{
    delete ui;
}
