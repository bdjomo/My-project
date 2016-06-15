#ifndef CRECHNUNGINFO_H
#define CRECHNUNGINFO_H

#include <QDialog>
#include "clogin.h"


namespace Ui {
class CRechnungInfo;
}

class CRechnungInfo : public QDialog
{
    Q_OBJECT

public:
    explicit CRechnungInfo(QWidget *parent = 0);
    ~CRechnungInfo();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonClose_2_clicked();

    void on_pushButtonClose_AdminInfo_clicked();

    void on_pushButtonAbbrecher_2_clicked();

    void on_pushButtonSpeichern_2_clicked();

private:
    Ui::CRechnungInfo *ui;
};

#endif // CRECHNUNGINFO_H
