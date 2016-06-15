#ifndef CLOGIN_H
#define CLOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "crechnunginfo.h"
#include "adminintration.h"
#include "rechnungerstellen.h"

namespace Ui {
class CLogin;
}

class CLogin : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOPen()
    {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
//        mydb.setDatabaseName("C:/sqlite2/DB_BuchhaltungRechnung.sqlite");
        mydb.setDatabaseName("C:/sqlite2/DB_Company/DB_Company.sqlite");

        if(!mydb.open())
        {
            qDebug()<<("Failed to open Database");
            return false;
        }
        else
        {
            qDebug()<<("Database to be connected");
            return true;
        }
    }

public:
    long logName(QString sName, QString sLastName);

public:
    explicit CLogin(QWidget *parent = 0);
    ~CLogin();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Close_clicked();

private:
    Ui::CLogin *ui;
};

#endif // CLOGIN_H
