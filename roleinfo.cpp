#include "roleinfo.h"
#include "ui_roleinfo.h"

RoleInfo::RoleInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoleInfo)
{
    ui->setupUi(this);
}

RoleInfo::~RoleInfo()
{
    delete ui;
}

void RoleInfo::on_pushButtonClose_clicked()
{
    this->close();
}

void RoleInfo::on_pushButton_Admin_clicked()
{
    Adminintration *admin;
    this->hide();
    admin = new Adminintration(this);
    admin->show();
}

void RoleInfo::on_pushButton_RoleInfo_clicked()
{
    CLogin conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOPen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM Role");

    qry->exec();
    Modal->setQuery(*qry);
    ui->tableViewRoleInfo->setModel(Modal);

    conn.connClose();
    qDebug() << (Modal->rowCount());
}
