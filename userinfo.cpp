#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);

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

    //Date time
    QDateTime dateTime = QDateTime::currentDateTime();
    QString sDateTimeTxt = dateTime.toString();
    ui->label_DateTime->setText(sDateTimeTxt);
}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::on_pushButtonClose_clicked()
{
    this->close();
}

void UserInfo::on_pushButton_Admin_clicked()
{
    Adminintration *admin;
    this->hide();
    admin = new Adminintration(this);
    admin->show();
}

void UserInfo::on_pushButton_UserInfo_clicked()
{
    CLogin conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOPen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM UserInfo");

    qry->exec();
    Modal->setQuery(*qry);
    ui->tableView_UserInfo->setModel(Modal);
//    ui->tat>tableView->setModel(Modal);

    conn.connClose();
    qDebug() << (Modal->rowCount());
}
