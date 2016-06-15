#ifndef ADMININTRATION_H
#define ADMININTRATION_H

#include <QDialog>
#include "clogin.h"
#include "crechnunginfo.h"
#include "crechnungeninformationen.h"
#include "userinfo.h"
#include "employeeinfo.h"
#include "produktinfo.h"
#include "roleinfo.h"
#include "rechnungerstellen.h"
#include "rechnungerstellen.h"

namespace Ui {
class Adminintration;
}

class Adminintration : public QDialog
{
    Q_OBJECT

public:
    explicit Adminintration(QWidget *parent = 0);
    ~Adminintration();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButton_RechnungInfo_clicked();

    void on_pushButton_RechnungErstellen_clicked();

    void on_pushButtonLogInfi_clicked();

    void on_pushButton_LagerInfo_clicked();

    void on_pushButton_MitarbeitInfo_clicked();

    void on_pushButton_ProdukteInfo_clicked();

    void on_pushButton_RoleInfo_clicked();

    void on_btnRechnungErstellen_clicked();

private:
    Ui::Adminintration *ui;
};

#endif // ADMININTRATION_H
