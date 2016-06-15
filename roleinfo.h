#ifndef ROLEINFO_H
#define ROLEINFO_H

#include <QDialog>
#include "adminintration.h"

namespace Ui {
class RoleInfo;
}

class RoleInfo : public QDialog
{
    Q_OBJECT

public:
    explicit RoleInfo(QWidget *parent = 0);
    ~RoleInfo();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButton_Admin_clicked();

    void on_pushButton_RoleInfo_clicked();

private:
    Ui::RoleInfo *ui;
};

#endif // ROLEINFO_H
