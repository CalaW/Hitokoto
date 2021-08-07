#ifndef DIALOGNEWHITO_H
#define DIALOGNEWHITO_H

#include <QDialog>
#include "newhitocontroller.h"

namespace Ui {
class DialogNewHito;
}

class DialogNewHito : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewHito(QWidget *parent = nullptr);
    ~DialogNewHito();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogNewHito *ui;
    NewHitoController new_hito_ctrl;
};

#endif // DIALOGNEWHITO_H
