#include "crechnunginfo.h"
#include "ui_crechnunginfo.h"
#include "adminintration.h"
#include "QMessageBox"

CRechnungInfo::CRechnungInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRechnungInfo)
{
    ui->setupUi(this);
}

CRechnungInfo::~CRechnungInfo()
{
    delete ui;
}

void CRechnungInfo::on_pushButtonClose_clicked()
{
    this->close();
}

void CRechnungInfo::on_pushButtonClose_2_clicked()
{
    this->close();
}

void CRechnungInfo::on_pushButtonClose_AdminInfo_clicked()
{
    Adminintration *admin;
    this->hide();
    admin = new Adminintration(this);
    admin->show();
}

void CRechnungInfo::on_pushButtonAbbrecher_2_clicked()
{
    if( QMessageBox::question( this, trUtf8( "Quit Setup" ),
                               trUtf8( "Setup is not complete yet. Are you sure you want to quit setup?" ),
                               QMessageBox::Yes, QMessageBox::No ) == QMessageBox::Yes ) {
            // allow cancel
            reject();
    }
}

void CRechnungInfo::on_pushButtonSpeichern_2_clicked()
{
    CLogin conn;

    QString sTitel, sKundeName, sStrasseNr, sAdresseOrt, sAdressLand, sRechnungsNr, sRechnungsdatum, sEinheit, sMwst;
    QString sFaelligkeitsdatum, sStatus, sZahlungbedingungsgen, sHinweisNachricht,  sProduktName, sPreise, sMenge;
    QString sWaehrung, sBetrag, sRabat, sVersandKosten, sGesamtBetrag, sGeschaeftsbedingungen, sProdBeschreibung;


    //Kunden und Daten
    sTitel = ui->lineEdit_Title->text();
    sKundeName = ui->lineEdit_KundeName->text();
    sRechnungsdatum = ui->lineEdit_Rechnungsdatum->text();
    sStrasseNr = ui->lineEdit_Strasse_Nr->text();
    sAdresseOrt = ui->lineEdit_Ort->text();
    sAdressLand = ui->lineEdit_Land->text();
    sRechnungsNr = ui->lineEdit_RechNr->text();
    sRechnungsdatum = ui->lineEdit_Rechnungsdatum->text();
    sFaelligkeitsdatum = ui->lineEdit_Faelligkeitsdatum->text();
    sStatus = ui->lineEdit_Status->text();
    sZahlungbedingungsgen = ui->lineEdit_Zahlungbedingungsgen->text();
    sHinweisNachricht = ui->lineEdit_Mahnhistorie->text();

    //Rechnungszeilen
    sProduktName = ui->lineEdit_ProduktName->text();
    sPreise = ui->lineEdit_PreiseNetto->text();
    sMenge = ui->lineEdit_Menge->text();
    sEinheit = ui->lineEdit_Einheit->text();
    sMwst = ui->lineEdit_Mwst->text();
   // sWaehrung = ui->comboBoxWaehrung->_,
    sBetrag = ui->lineEdit_Betrag->text();
    sRabat = ui->lineEdit_Rabatt2->text();
    sVersandKosten = ui->lineEdit_Versandkosten->text();
    sGesamtBetrag = ui->lineEdit_GesamtBetrag->text();
    sGeschaeftsbedingungen = ui->lineEdit_Geschaefsbedingungen->text();
    sProdBeschreibung = ui->lineEdit_ProdBeschreibung->text();


    sFaelligkeitsdatum = ui->lineEdit_Faelligkeitsdatum->text();
    sStatus = ui->lineEdit_Status->text();

    sGeschaeftsbedingungen = ui->lineEdit_Geschaefsbedingungen->text();

    if(!conn.connOPen())
    {
        qDebug()<<"Failed to open a Database";
        return;
    }

    conn.connOPen();
    QSqlQuery qry;
//    qry.prepare("INSERT INTO RechnungsInformation (RechID, Titel, Rechnungsdatum, Oragisation, Zustaentig , MitarbeitSP, Mahnstufe, Mahnungsdatum, RechnungNr, Faelig, Status, Leistungszeitraum ,Schlussrechnung, Mahnhistorie, RechnungsAdrStrasse, RechnungsAdrPastfachNr, RechnungsAdrOrt, RechnungsAdrBudesland, RechnungsAdrPLZ, RechnungsAdrLand, LieferAdrStrasse, LieferAdrPostfach, LieferAdrOrt, LieferAdrBudesland, LieferAdrPLZ, LieferAdrLand, Geschaeftsbedingungen, Beschreibung, MitarbName)"
//                "VALUES('"+sRechID+"', '"+sTitel+"', '"+sRechnungsdatum+"', '"+sOragisation+"', '"+sZustaentig+"' , '"+sMitarbeitSP+"', '"+sMahnstufe+"', '"+sMahnungsdatum+"', '"+sRechnungNr+"', '"+sFaelig+"', '"+sStatus+"', '"+sLeistungszeitraum+"' ,'"+sSchlussrechnung+"', '"+sMahnhistorie+"', '"+sRechnungsAdrStrasse+"', '"+sRechnungsAdrPastfachNr+"', '"+sRechnungsAdrOrt+"', '"+sRechnungsAdrBudesland+"', '"+sRechnungsAdrPLZ+"', '"+sRechnungsAdrLand+"', '"+sLieferAdrStrasse+"', '"+sLieferAdrPostfach+"', '"+sLieferAdrOrt+"', '"+sLieferAdrBudesland+"', '"+sLieferAdrPLZ+"', '"+sLieferAdrLand+"', '"+sGeschaeftsbedingungen+"', '"+sBeschreibung+"', '"+sMitarbName+"')");


    if(qry.exec())
    {
       QMessageBox::critical(this, tr("Save"), tr("Saved"));
       conn.connClose();
    }
    else
    {
        QMessageBox::critical(this, tr("eror::"), qry.lastError().text());
    }
}
