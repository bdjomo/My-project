#include "adminintration.h"
#include "ui_adminintration.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>


Adminintration::Adminintration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminintration)
{
    ui->setupUi(this);

    QString sFirstname, sLastName;
    QString sUsername, sPassword;

    CLogin log;
    //MessageBox!!!
    if(!log.connOPen())
        ui->Label_DatabaseConnecction->setText("Failed to open Database");
    else
        ui->Label_DatabaseConnecction->setText("Database to be connected");

    //Digital Clock
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //Date time: Nur zu testen
    QDateTime dateTime = QDateTime::currentDateTime();
    QString sDateTimeTxt = dateTime.toString();
    ui->label_DateTime->setText(sDateTimeTxt);


    log.connOPen();

    QSqlQuery qry;
    if(qry.exec("select * from UserInfo where UserName ='"+ sUsername + "' and Password ='" + sPassword + "'")){

        if(qry.next())
        {
            //sName =qry.value(0).toString();
            sLastName = qry.value(4).toString();
            ui->Label_NameUser->setText(sLastName);
            QString msg = sLastName;
            QMessageBox::warning(this, "salut", "Salut");
        }
    }
    log.connClose();
    //qDebug() << (Modal->rowCount());
}

Adminintration::~Adminintration()
{
    delete ui;
}

void Adminintration::on_pushButtonClose_clicked()
{
    this->close();
}

void Adminintration::on_pushButton_RechnungInfo_clicked()
{
    CRechnungenInformationen *rechInfo;
    this->hide();
    rechInfo = new CRechnungenInformationen(this);
    rechInfo->show();
}

void Adminintration::on_pushButton_RechnungErstellen_clicked()
{
    CRechnungInfo *rechErst;
    this->hide();
    rechErst = new CRechnungInfo(this);    
    rechErst->show();
}

void Adminintration::on_pushButtonLogInfi_clicked()
{
    UserInfo *usrInfo;
    this->hide();
    usrInfo = new UserInfo(this);
    usrInfo->show();
}

void Adminintration::on_pushButton_LagerInfo_clicked()
{

}

void Adminintration::on_pushButton_MitarbeitInfo_clicked()
{
    EmployeeInfo *empInfo;
    this->hide();
    empInfo = new EmployeeInfo(this);
    empInfo->show();
}

void Adminintration::on_pushButton_ProdukteInfo_clicked()
{
    ProduktInfo *prodInfo;
    this->hide();
    prodInfo = new ProduktInfo(this);
    prodInfo->show();
}

void Adminintration::on_pushButton_RoleInfo_clicked()
{
    RoleInfo *role;
    this->hide();
    role = new RoleInfo(this);
    role->show();
}

void Adminintration::on_btnRechnungErstellen_clicked()
{
    RechnungErstellen *rechnungErst;
    this->hide();
    rechnungErst = new RechnungErstellen(this);
    rechnungErst->show();
}
