#include "rechnungerstellen.h"
#include "ui_rechnungerstellen.h"
#include "adminintration.h"
#include <QMessageBox>

RechnungErstellen::RechnungErstellen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RechnungErstellen)
{
    ui->setupUi(this);
}

RechnungErstellen::~RechnungErstellen()
{
    delete ui;
}

void RechnungErstellen::on_btn_Close_clicked()
{
    this->close();
}

void RechnungErstellen::on_btn_DialogAdmin_clicked()
{
    Adminintration *admin;
    this->hide();
    admin = new Adminintration(this);
    admin->show();
}

void RechnungErstellen::on_btn_Speichern__clicked()
{
    QString sTitel, sRechnungs_Nr, sZustaentig, sOrganisation, sRechnungsdatum, sMahnstufe, sLieferAdrPLZ, sLieferAdrLand;
    QString sMahnungsdatum, sZahlungsstatus, sLeistungsZeitraum, sSchlussrechnung, sOffener_Betrag, sMahnhistorie, sRechnungsadresse_Strasse;
    QString sRechnungsadresse_Ort, sLieferadresse__Ort, sRechnungsadresse_PLZ, sRechnungsadresse_Land /*sLieferadresse_Strasse*/;
    QString sLieferadresse_Bundesland, sRechnungsadresse_Bundesland, sLieferadresse_PLZ, sLieferadresse_Land, sBeschreibung;
    QString sGeschäftsbedingungen, sRechnungsAdrStrasse,sRechnungsAdrOrt, sRechnungsAdrPLZ, sRechnungsAdrLand, sLieferAdrStrasse, sLieferAdrOrt;
    QString sProdID, sProdName, sMenge, sListenpreise, sRabat, sVersandKosten, sSummeNetto, sMwst, sPreise, sGesamt_Summe;


    //Tabelle RechnungInformation
    sTitel = ui->txt_Titel->text();
    sRechnungs_Nr = ui->txt_RechNr->text();
  //  sZustaentig = ui->txt_Zustaendig->text();
    sRechnungsdatum = ui->txt_RechDatum->text();
  //  sRechnungsadresse_Strasse = ui->txt_RechAdreStrasse->text();
  //  sRechnungsadresse_PLZ = ui->txt_RechAdrePLZ->text();
  //  sRechnungsadresse_Ort = ui->txt_RechAdreOrt->text();
  //  sRechnungsadresse_Land = ui->txt_RechAdreLand->text();
  //  sRechnungsadresse_Bundesland = ui->txt_RechAdreBundesland->text();
  //  //sLieferadresse_Strasse = ui->txt_LiefAdrStrasse->text();
  //  sLieferadresse_PLZ = ui->txt_LiefAdrePLZ->text();
  //  sLieferadresse__Ort = ui->txt_LiefAdreOrt->text();
  //  sLieferadresse_Bundesland = ui->txt_LiefAdrBudesland->text();
  //  sLieferadresse_Land = ui->txt_LiefAdrLand->text();
    sOrganisation = "Softpace";
    //sSachbearbeiter = ui->txt_Zustaendig->text();
    sZahlungsstatus = ui->txt_Status->text();
    sLeistungsZeitraum = ui->txt_Leistungzeiraum->text();   
    sSchlussrechnung = ui->txt_Schlussrechnung->text();
    sRechnungsAdrStrasse = ui->txt_RechStrasse_Nr->text();
    sRechnungsAdrOrt = ui->txt_RechOrt->text();
    sRechnungsAdrPLZ = ui->txt_RechPLZ->text();
    sRechnungsAdrLand = ui->txt_RechPLZ->text();
//    sBeschreibung = ui->txt_Beschreibung->text();
    //Tabelle Produkte
//    sProdID = ui->txt_ProdID->text();
    sProdName = ui->txt_ProdName->text();
    sMenge = ui->txt_Menge->text();
//    sListenpreise = ui->txt_Listpreis->text();
    sRabat = ui->txt_Rabatt->text();
    sVersandKosten = ui->txt_Versandkosten->text();
    sSummeNetto = ui->txt_SummeNetto->text();
    sMwst = ui->txt_Mwst->text();
    sPreise = ui->txt_SummeBrutto->text();
    sGesamt_Summe = ui->txt_SummeEnde->text();


    sOffener_Betrag;
//    sMahnungsdatum = ui->txt_Mahnungsdatum->text();
    sGeschäftsbedingungen = ui->txt_Geschaefsbedingungen->text();
 //   sBeschreibung = ui->txt_Beschreibung->text();

     CLogin conn;
    if(!conn.connOPen())
    {
        qDebug()<<"No connection to db :(";
        return;
    }

    conn.connOPen();
    QSqlQuery qry;
    qry.prepare("INSERT INTO RechnungsInformation (Titel, Rechnungsdatum, Zustaentig, Mahnstufe, Mahnungsdatum, RechnungNr, Status, Leistungszeitraum, Schlussrechnung, Mahnhistorie, RechnungsAdrStrasse, RechnungsAdrOrt, RechnungsAdrPLZ, RechnungsAdrLand, LieferAdrStrasse, LieferAdrOrt, LieferAdrPLZ, LieferAdrLand, Beschreibung, Organisation) VALUES ('"+sTitel+"','"+sRechnungsdatum+"','"+sZustaentig+"','"+sMahnstufe+"','"+sMahnungsdatum+"','"+sRechnungs_Nr+"','"+sZahlungsstatus+"','"+sLeistungsZeitraum+"','"+sSchlussrechnung+"','"+sMahnhistorie+"','"+sRechnungsAdrStrasse+"','"+sRechnungsAdrOrt+"','"+sRechnungsAdrPLZ+"','"+sRechnungsAdrLand+"','"+sLieferAdrStrasse+"','"+sLieferAdrOrt+"','"+sLieferAdrPLZ+"','"+sLieferAdrLand+"','"+sBeschreibung+"','"+sOrganisation+ "')" );
    qry.prepare("INSET INTO Produkt(ProdID, ProdName, Menge, Listenpreise, Rabtt, VersandKosten, Summe_Netto, Mwst, Preise, Gesamt_Summe)VALUES ('"+sProdID+"','"+sProdName+"','"+sMenge+"','"+sListenpreise+"','"+sRabat+"','"+sVersandKosten+"','"+sSummeNetto+"','"+sMwst+"','"+sPreise+"','"+sGesamt_Summe+ "')" );

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Save"), tr("saved"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error::"), qry.lastError().text());
    }
}
