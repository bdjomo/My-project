#include "employeeinfo.h"
#include "ui_employeeinfo.h"

EmployeeInfo::EmployeeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInfo)
{
    ui->setupUi(this);
}

EmployeeInfo::~EmployeeInfo()
{
    delete ui;
}

void EmployeeInfo::on_pushButtonClose_clicked()
{
    this->close();
}

void EmployeeInfo::on_pushButton_Admin_clicked()
{
    Adminintration *admin;
    this->hide();
    admin = new Adminintration(this);
    admin->show();
}

void EmployeeInfo::on_pushButton_EmployeeInfo_clicked()
{
    CLogin conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOPen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM MitarbeiterInfo");

    qry->exec();
    Modal->setQuery(*qry);
    ui->tableViewEmployee->setModel(Modal);

    conn.connClose();
    qDebug() << (Modal->rowCount());
}
