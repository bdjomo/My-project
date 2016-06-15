#ifndef RECHNUNGERSTELLEN_H
#define RECHNUNGERSTELLEN_H

#include <QDialog>
#include "clogin.h"

namespace Ui {
class RechnungErstellen;
}

class RechnungErstellen : public QDialog
{
    Q_OBJECT

public:
    explicit RechnungErstellen(QWidget *parent = 0);
    ~RechnungErstellen();

private slots:
    void on_btn_Close_clicked();

    void on_btn_DialogAdmin_clicked();

    void on_btn_Speichern__clicked();

private:
    Ui::RechnungErstellen *ui;
};

#endif // RECHNUNGERSTELLEN_H
