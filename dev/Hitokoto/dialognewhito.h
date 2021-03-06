/**
 * @file dialognewhito.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Dialog to add new hitokoto
 * 
 * auto generated by qt
 * 
 * @version 0.1
 * @date 2021-08-07
 * 
 */

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
