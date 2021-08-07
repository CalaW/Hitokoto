#include "adnewuserdialog.h"
#include "ui_adnewuserdialog.h"

adNewUserDialog::adNewUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adNewUserDialog)
{
    ui->setupUi(this);
}

adNewUserDialog::~adNewUserDialog()
{
    delete ui;
}


void adNewUserDialog::on_buttonBox_accepted()
{
    emit adAddUserConfirm(ui->newUserNameEdt->text(), ui->newUserPwdEdt->text());
}

