#include "changepwddialog.h"
#include "ui_changepwddialog.h"

ChangePwdDialog::ChangePwdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePwdDialog)
{
    ui->setupUi(this);
}

ChangePwdDialog::~ChangePwdDialog()
{
    delete ui;
}

void ChangePwdDialog::on_buttonBox_accepted()
{
    emit changePwdConfirm(ui->prevPwd->text(), ui->newPwd->text());
}

