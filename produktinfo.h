#ifndef PRODUKTINFO_H
#define PRODUKTINFO_H

#include <QDialog>
#include "adminintration.h"
#include "clogin.h"

namespace Ui {
class ProduktInfo;
}

class ProduktInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ProduktInfo(QWidget *parent = 0);
    ~ProduktInfo();

private slots:
    void on_pushButton_ProduktInfo_clicked();

    void on_pushButtonClose_clicked();

    void on_pushButton_Admin_clicked();

private:
    Ui::ProduktInfo *ui;
};

#endif // PRODUKTINFO_H
