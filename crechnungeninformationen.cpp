#include "crechnungeninformationen.h"
#include "ui_crechnungeninformationen.h"

CRechnungenInformationen::CRechnungenInformationen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRechnungenInformationen)
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

CRechnungenInformationen::~CRechnungenInformationen()
{
    delete ui;
}

void CRechnungenInformationen::on_pushButton_clicked()
{
    this->close();
}

void CRechnungenInformationen::on_pushButton_Admin_clicked()
{
    Adminintration *admin;
    this->hide();
    admin = new Adminintration(this);
    admin->show();
}

void CRechnungenInformationen::on_pushButtonClose_clicked()
{
    this->close();
}

void CRechnungenInformationen::on_pushButton_RechInfo_clicked()
{
    CLogin conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOPen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM RechnungsInformation");

    qry->exec();
    Modal->setQuery(*qry);
    ui->tableViewRechnungInformation->setModel(Modal);

    conn.connClose();
    qDebug() << (Modal->rowCount());
}
