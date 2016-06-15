#include "produktinfo.h"
#include "ui_produktinfo.h"

ProduktInfo::ProduktInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProduktInfo)
{
    ui->setupUi(this);
}

ProduktInfo::~ProduktInfo()
{
    delete ui;
}

void ProduktInfo::on_pushButton_ProduktInfo_clicked()
{
    CLogin conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOPen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM Produkte");

    qry->exec();
    Modal->setQuery(*qry);
    ui->tableViewProdukt->setModel(Modal);

    conn.connClose();
    qDebug() << (Modal->rowCount());
}

void ProduktInfo::on_pushButtonClose_clicked()
{
    this->close();
}

void ProduktInfo::on_pushButton_Admin_clicked()
{
    Adminintration *admin;
    this->hide();
    admin = new Adminintration(this);
    admin->show();
}
