#ifndef CRECHNUNGENINFORMATIONEN_H
#define CRECHNUNGENINFORMATIONEN_H

#include <QDialog>
#include "adminintration.h"
#include "clogin.h"

namespace Ui {
class CRechnungenInformationen;
}

class CRechnungenInformationen : public QDialog
{
    Q_OBJECT

public:
    explicit CRechnungenInformationen(QWidget *parent = 0);
    ~CRechnungenInformationen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Admin_clicked();

    void on_pushButtonClose_clicked();

    void on_pushButton_RechInfo_clicked();

private:
    Ui::CRechnungenInformationen *ui;
};

#endif // CRECHNUNGENINFORMATIONEN_H
