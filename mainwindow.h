#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QLabel>
#include <QPushButton>
#include <QtextEdit>
#include <QMessageBox>
#include <QGridLayout>
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <math.h>
#include <QTextBlock>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QComboBox>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void connection();
    void connectpageBuildup();
    void connectpageCleanup();
    void mainpageBuildup();
    void mp2Buildup();
    void mp3Buildup();
    void mp1Buildup();
    void cleanup();
    ~MainWindow();

public slots:
    void customPrepExec();
    void selectMode(QString request);
    void selectTable(QString table);
    void MP1prepExecReq();

private:
    QGridLayout *mainLayout;
    QSqlQuery query;
    /*--- CONNECT PAGE ---*/
    QPushButton *connector;
    QLabel *portDesc;
    QLineEdit *portText;
    QLabel *hostDesc;
    QLineEdit *hostText;
    QLabel *userDesc;
    QLineEdit *userText;
    QLabel *pwdDesc;
    QLineEdit *pwdText;
    QLabel *nameDesc;
    QLineEdit *nameText;
    int port = 3306;
    QString host = "localhost";
    QString user = "root";
    QString pwd = "root";
    QString name = "Auchan";
    /*--- REQ1 / MP ---*/
    QComboBox *reqSelect;
    QLabel *reqDesc;
    QLabel *customReqDesc;
    QLineEdit *customReq;
    QPushButton *customExec;
    QLabel *MP1tableDesc;
    QComboBox *MP1tableSelect;
    QLabel *MP1fieldDesc;
    QComboBox *MP1fieldSelectClient;
    QComboBox *MP1fieldSelectApprovisionnement;
    QComboBox *MP1fieldSelectCommandes;
    QComboBox *MP1fieldSelectDetailsCommande;
    QComboBox *MP1fieldSelectEmployes;
    QComboBox *MP1fieldSelectFournisseurs;
    QComboBox *MP1fieldSelectMagasins;
    QComboBox *MP1fieldSelectProduits;
    QComboBox *MP1fieldSelectStocks;
    QLabel *MP1filterDesc;
    QComboBox *MP1filterSelect;
    QLabel *MP1valueDesc;
    QLineEdit *MP1value;
    QPushButton *MP1execReq;
    /*--- REQ2 ---*/
    //CLIENTS
    QGridLayout *clientLayout;
    QLineEdit *clientsId;
    QLineEdit *clientNom;
    QLineEdit *clientDateNaissance;
    QLineEdit *clientEmail;
    QLineEdit *clientTelephone;
    QLineEdit *clientAdresse;
    QLineEdit *clientCodePostal;
    QLineEdit *clientPays;
    QLineEdit *clientDateInscription;
    QLineEdit *clientCarteFidelite;
    QLabel *clientsIdDesc;
    QLabel *clientNomDesc;
    QLabel *clientDateNaissanceDesc;
    QLabel *clientEmailDesc;
    QLabel *clientTelephoneDesc;
    QLabel *clientAdresseDesc;
    QLabel *clientCodePostalDesc;
    QLabel *clientPaysDesc;
    QLabel *clientDateInscriptionDesc;
    QLabel *clientCarteFideliteDesc;
    //MAGASINS
    QLineEdit *magasinsId;
    QLineEdit *magasinsAdresse;
    QLineEdit *magasinsCodePostal;
    QLineEdit *magasinsTelephone;
    QLineEdit *magasinsPays;
    QLineEdit *magasinsDateOuverture;
    QLabel *magasinsIdDesc;
    QLabel *magasinsAdresseDesc;
    QLabel *magasinsCodePostalDesc;
    QLabel *magasinsTelephoneDesc;
    QLabel *magasinsPaysDesc;
    QLabel *magasinsDateOuvertureDesc;
    //Produits
    QLineEdit *produitsId;
    QLineEdit *produitsNom;
    QLineEdit *produitsCategorie;
    QLineEdit *produitsDescription;
    QLineEdit *produitsPrixVente;
    QLabel *produitsIdDesc;
    QLabel *produitsNomDesc;
    QLabel *produitsCategorieDesc;
    QLabel *produitsDescriptionDesc;
    QLabel *produitsPrixVenteDesc;
    //Fournisseurs
    QLineEdit *fournisseursId;
    QLineEdit *fournisseursNom;
    QLineEdit *fournisseursTelephone;
    QLineEdit *fournisseursAdresse;
    QLineEdit *fournisseursCodePostal;
    QLineEdit *fournisseursPays;
    QLabel *fournisseursIdDesc;
    QLabel *fournisseursNomDesc;
    QLabel *fournisseursTelephoneDesc;
    QLabel *fournisseursAdresseDesc;
    QLabel *fournisseursCodePostalDesc;
    QLabel *fournisseursPaysDesc;
    //


};

#endif // MAINWINDOW_H
