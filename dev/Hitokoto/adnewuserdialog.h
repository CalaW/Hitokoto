#ifndef ADNEWUSERDIALOG_H
#define ADNEWUSERDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class adNewUserDialog;
}

class adNewUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adNewUserDialog(QWidget *parent = nullptr);
    ~adNewUserDialog();

signals:
    void adAddUserConfirm(const QString& name, const QString& pwd);

private slots:

    void on_buttonBox_accepted();

private:
    Ui::adNewUserDialog *ui;
};

#endif // ADNEWUSERDIALOG_H
