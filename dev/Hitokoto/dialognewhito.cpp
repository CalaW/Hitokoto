#include "dialognewhito.h"
#include "ui_dialognewhito.h"
#include <QMessageBox>

DialogNewHito::DialogNewHito(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewHito)
{
    ui->setupUi(this);
    ui->newHitoTimeEdt->setDateTime(QDateTime::currentDateTime());

}

DialogNewHito::~DialogNewHito()
{
    delete ui;
}

void DialogNewHito::on_buttonBox_accepted()
{
    if (ui->newHitoContentEdt->toPlainText().trimmed().isEmpty()) {
        QMessageBox::warning(this, tr("Publish Failed"), tr("Content of a Hitokoto cannot be empty!"), QMessageBox::Ok);
    }
    int index = 0;
    index = ui->newHitoTypeCombo->currentIndex();

    new_hito_ctrl.addHitokoto(ui->newHitoTimeEdt->dateTime().toSecsSinceEpoch()
                              , ui->newHitoContentEdt->toPlainText() , index);
}


void DialogNewHito::on_buttonBox_rejected()
{
}

