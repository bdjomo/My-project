#include "clogin.h"
#include "ui_clogin.h"

#include <QTime>
#include <QDateTime>
#include <QMessageBox>

CLogin::CLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CLogin)
{
    ui->setupUi(this);

    //MessageBox!!!
    if(!connOPen())
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

CLogin::~CLogin()
{
    delete ui;
}

void CLogin::on_pushButton_Login_clicked()
{
    QString sUsername, sPassword, sFirstname;
    sUsername = ui->lineEdit_UserName->text();
    sPassword = ui->lineEdit_Password->text();

    if(!connOPen())
    {
        qDebug()<<"Failed to open a Database";
        return;
    }

    connOPen();
    QSqlQuery qry;
    qry.prepare("select UserName, Password, Firstname from UserInfo where UserName ='"+ sUsername + "' and Password ='" + sPassword + "'");
//    qry.prepare("select * from User_Login where UserName ='"+ sUsername + "' and Password ='" + sPassword + "'");
    if(qry.exec())
    {
        int iCount = 0;
        while(qry.next())
        {
            iCount++;
        }

        if(iCount == 1)
        {/*
             Adminintration *admin;
             QString msg = "UserName = " + qry.value(0).toString() + " \n" +
                           "Password = " + qry.value(1).toString() + " \n" +
                           "Firstname = " + qry.value(2).toString();
             QMessageBox::warning(this, "salut", msg);
             sFirstname = qry.value(2).toString();
             ui->Label_DatabaseConnecction->setText("sFirstname");
//             ui->Label_DatabaseConnecction->setText("Username and Password is correct!!!!");
             connClose();
//             this->hide();
//             admin = new Adminintration(this);
//             admin->show();*/


            CRechnungInfo *rechnungInfo; //blaise
            ui->Label_DatabaseConnecction->setText("Username and Password is correct!!!!");
            connClose();
            this->hide();
            Adminintration *admin = new Adminintration(this);
            admin->show();/*
            rechnungInfo = new CRechnungInfo(this);
            rechnungInfo->show();*/
        }
        if(iCount > 1)
            ui->Label_DatabaseConnecction->setText("Duplicate Username and Password is correct!!!!");
        if(iCount < 1)
            ui->Label_DatabaseConnecction->setText("Username and Password is not correct!!!!");
    }

}

void CLogin::on_pushButton_Close_clicked()
{
    this->close();
}

long CLogin::logName(QString sName, QString sLastName)
{
    QString sUsername, sPassword;

    if(!connOPen())
    {
        qDebug()<<"Failed to open a Database";
        return 1;
    }

    connOPen();
    QSqlQuery qry;
    qry.prepare("select * from UserInfo where UserName ='"+ sUsername + "' and Password ='" + sPassword + "'");

    if(qry.exec())
    {
        sName =qry.value(0).toString();
        sLastName = qry.value(0).toString();
    }

   /* QListView *myList;
    QSqlQueryModel *Modal = new QSqlQueryModel();    
    QString sVal;// = myList->model()->data(0).toString();

    if(!connOPen())
    {
        qDebug()<<"Failed to open a Database";
        return 0;
    }

    connOPen();
    QSqlQuery *qry = new QSqlQuery(mydb);;
    qry->prepare("select FirstName, LastName from UserInfo where FirstName ='"+ sVal + "' and LastName ='" + sVal + "'");
    if(qry->exec())
    {
        Modal->setQuery(*qry);
        int iCount = 0;
        while(qry->next())
        {
            iCount++;
        }

        sName = sVal;
        sLastName = sVal;
    //    ui->lineEdit_UserName->text() = myList->setModel(Modal).toString();
        */
        return 0;
}
