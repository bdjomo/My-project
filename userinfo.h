#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include "adminintration.h"

namespace Ui {
class UserInfo;
}

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = 0);
    ~UserInfo();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButton_Admin_clicked();

    void on_pushButton_UserInfo_clicked();

private:
    Ui::UserInfo *ui;
};

#endif // USERINFO_H
