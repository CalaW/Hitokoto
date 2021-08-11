#ifndef CHANGEPWDDIALOG_H
#define CHANGEPWDDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class ChangePwdDialog;
}

class ChangePwdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePwdDialog(QWidget *parent = nullptr);
    ~ChangePwdDialog();

signals:
    void changePwdConfirm(const QString& prevPwd, const QString& newPwd);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ChangePwdDialog *ui;
};

#endif // CHANGEPWDDIALOG_H
