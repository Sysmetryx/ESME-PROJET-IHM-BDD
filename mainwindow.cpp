#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainLayout = new QGridLayout;
    connectpageBuildup();
    this->setCentralWidget (new QWidget(this));
    this->centralWidget()->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}

void MainWindow::connectpageBuildup()
{
    portDesc = new QLabel();
    portDesc->setText("Port :");
    mainLayout->addWidget(portDesc, 0, 0, 1, 1);
    hostDesc = new QLabel();
    hostDesc->setText("Hote :");
    mainLayout->addWidget(hostDesc, 1, 0, 1, 1);
    userDesc = new QLabel();
    userDesc->setText("Utilisateur :");
    mainLayout->addWidget(userDesc, 2, 0, 1, 1);
    pwdDesc = new QLabel();
    pwdDesc->setText("Mot de passe :");
    mainLayout->addWidget(pwdDesc, 3, 0, 1, 1);
    nameDesc = new QLabel();
    nameDesc->setText("Nom :");
    mainLayout->addWidget(nameDesc, 4, 0, 1, 1);
    portText = new QLineEdit();
    mainLayout->addWidget(portText, 0, 1, 1, 1 );
    portText->setText(QString::number(port));
    hostText = new QLineEdit();
    mainLayout->addWidget(hostText, 1, 1, 1, 1);
    hostText->setText(host);
    userText = new QLineEdit();
    mainLayout->addWidget(userText, 2, 1, 1, 1);
    userText->setText(user);
    pwdText = new QLineEdit();
    mainLayout->addWidget(pwdText, 3, 1, 1, 1);
    pwdText->setText(pwd);
    pwdText->setEchoMode(QLineEdit::Password);
    nameText = new QLineEdit();
    mainLayout->addWidget(nameText, 4, 1, 1, 1);
    nameText->setText(name);
    connector = new QPushButton("Connexion", this);
    connect(connector, &QPushButton::clicked, this, &MainWindow::connection);
    mainLayout->addWidget(connector, 5, 3, 1, 1);
}

void MainWindow::connectpageCleanup()
{
    delete connector;
    delete portText;
    delete hostText;
    delete userText;
    delete pwdText;
    delete nameText;
    delete portDesc;
    delete hostDesc;
    delete userDesc;
    delete pwdDesc;
    delete nameDesc;
}

void MainWindow::connection()
{
    bool check = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    host = hostText->text();
    user = userText->text();
    port = portText->text().toInt(&check, 10);
    pwd = pwdText->text();
    name = nameText->text();
    db.setPort(port);
    db.setHostName(host);
    db.setUserName(user);
    db.setPassword(pwd);
    db.setDatabaseName(name);
    if(db.open())
    {
         QMessageBox::about(this, "Succes", "Vous etes maintenant connectes");
         connectpageCleanup();
         mainpageBuildup();
    }
    else
    {
         QMessageBox::about(this, "Echec", "La connexion a echouee");
    }
}

void MainWindow::mainpageBuildup()
{
    /* --- ALWAYS SHOWING --- */
    customReqDesc = new QLabel("Requete speciale (MySQL)");
    mainLayout->addWidget(customReqDesc, 0,1,1,1,Qt::AlignRight);
    customReq = new QLineEdit();
    mainLayout->addWidget(customReq, 1,1,1,3);
    customExec = new QPushButton("Executer");
    connect(customExec, SIGNAL(clicked(bool)), this, SLOT(customPrepExec()));
    mainLayout->addWidget(customExec, 2,1,1,1,Qt::AlignTop);
    /* --- REQ1 --- */
    reqDesc = new QLabel("Choix de la requete :");
    mainLayout->addWidget(reqDesc,0,0,1,1,Qt::AlignTop);
    reqSelect = new QComboBox();
    reqSelect->addItem("REQUETE1");
    reqSelect->addItem("REQUETE2");
    reqSelect->addItem("REQUETE3");
    connect(reqSelect, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectMode(QString)));
    mainLayout->addWidget(reqSelect,1,0,1,1,Qt::AlignTop);
    MP1tableDesc = new QLabel("Choix de la table :");
    mainLayout->addWidget(MP1tableDesc, 2,0,1,1,Qt::AlignTop);
    MP1tableSelect = new QComboBox();
    MP1tableSelect->addItem("clients");
    MP1tableSelect->addItem("employes");
    MP1tableSelect->addItem("fournisseurs");
    MP1tableSelect->addItem("magasins");
    MP1tableSelect->addItem("produits");
    MP1tableSelect->addItem("commandes");
    MP1tableSelect->addItem("approvisionnement");
    MP1tableSelect->addItem("stocks");
    MP1tableSelect->addItem("details_commande");
    connect(MP1tableSelect, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectTable(QString)));
    mainLayout->addWidget(MP1tableSelect, 3,0,1,1,Qt::AlignTop);
    MP1fieldDesc = new QLabel("Choix du champs :");
    mainLayout->addWidget(MP1fieldDesc, 4,0,1,1,Qt::AlignTop);
    MP1fieldSelectClient = new QComboBox();
    MP1fieldSelectClient->addItem("id");
    MP1fieldSelectClient->addItem("nom");
    MP1fieldSelectClient->addItem("date_naissance");
    MP1fieldSelectClient->addItem("email");
    MP1fieldSelectClient->addItem("telephone");
    MP1fieldSelectClient->addItem("adresse");
    MP1fieldSelectClient->addItem("code_postal");
    MP1fieldSelectClient->addItem("pays");
    MP1fieldSelectClient->addItem("date_inscription");
    MP1fieldSelectClient->addItem("carte_fidelite");
    mainLayout->addWidget(MP1fieldSelectClient, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectClient->setVisible(true);
    MP1filterDesc = new QLabel("Choix du filtre :");
    mainLayout->addWidget(MP1filterDesc, 6,0,1,1,Qt::AlignTop);
    MP1filterSelect = new QComboBox();
    MP1filterSelect->addItem("=");
    MP1filterSelect->addItem("<=");
    MP1filterSelect->addItem(">=");
    MP1filterSelect->addItem("<");
    MP1filterSelect->addItem(">");
    mainLayout->addWidget(MP1filterSelect, 7,0,1,1,Qt::AlignTop);
    MP1valueDesc = new QLabel("Choix d'une valeur");
    mainLayout->addWidget(MP1valueDesc, 8,0,1,1,Qt::AlignTop);
    MP1value = new QLineEdit();
    mainLayout->addWidget(MP1value, 9,0,1,1,Qt::AlignTop);
    MP1execReq = new QPushButton("Executer");
    connect(MP1execReq, SIGNAL(clicked(bool)), this, SLOT(MP1prepExecReq()));
    mainLayout->addWidget(MP1execReq, 10,0,1,1,Qt::AlignTop);
    MP1fieldSelectApprovisionnement = new QComboBox();
    MP1fieldSelectApprovisionnement->addItem("numMagasin");
    MP1fieldSelectApprovisionnement->addItem("numProduit");
    MP1fieldSelectApprovisionnement->addItem("numFournisseur");
    MP1fieldSelectApprovisionnement->addItem("date_livraison");
    MP1fieldSelectApprovisionnement->addItem("quantite");
    MP1fieldSelectApprovisionnement->addItem("prix_achat_unitaire");
    mainLayout->addWidget(MP1fieldSelectApprovisionnement, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectApprovisionnement->setVisible(false);
    MP1fieldSelectCommandes = new QComboBox();
    MP1fieldSelectCommandes->addItem("id");
    MP1fieldSelectCommandes->addItem("idClient");
    MP1fieldSelectCommandes->addItem("idMagasin");
    MP1fieldSelectCommandes->addItem("date_commande");
    MP1fieldSelectCommandes->addItem("employeResponsableVente");
    MP1fieldSelectCommandes->addItem("mode_paiement");
    mainLayout->addWidget(MP1fieldSelectCommandes, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectCommandes->setVisible(false);
    MP1fieldSelectDetailsCommande = new QComboBox();
    MP1fieldSelectDetailsCommande->addItem("idCommande");
    MP1fieldSelectDetailsCommande->addItem("idProduit");
    MP1fieldSelectDetailsCommande->addItem("quantite");
    mainLayout->addWidget(MP1fieldSelectDetailsCommande, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectDetailsCommande->setVisible(false);
    MP1fieldSelectEmployes = new QComboBox();
    MP1fieldSelectEmployes->addItem("id");
    MP1fieldSelectEmployes->addItem("nom");
    MP1fieldSelectEmployes->addItem("date_naissance");
    MP1fieldSelectEmployes->addItem("email");
    MP1fieldSelectEmployes->addItem("telephone");
    MP1fieldSelectEmployes->addItem("adresse");
    MP1fieldSelectEmployes->addItem("code_postal");
    MP1fieldSelectEmployes->addItem("pays");
    MP1fieldSelectEmployes->addItem("date_recrutement");
    MP1fieldSelectEmployes->addItem("salaire");
    MP1fieldSelectEmployes->addItem("titre_poset");
    MP1fieldSelectEmployes->addItem("id_magasin");
    mainLayout->addWidget(MP1fieldSelectEmployes, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectEmployes->setVisible(false);
    MP1fieldSelectFournisseurs = new QComboBox();
    MP1fieldSelectFournisseurs->addItem("id");
    MP1fieldSelectFournisseurs->addItem("nom");
    MP1fieldSelectFournisseurs->addItem("telephone");
    MP1fieldSelectFournisseurs->addItem("adresse");
    MP1fieldSelectFournisseurs->addItem("code_postal");
    MP1fieldSelectFournisseurs->addItem("pays");
    mainLayout->addWidget(MP1fieldSelectFournisseurs, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectFournisseurs->setVisible(false);
    MP1fieldSelectMagasins = new QComboBox();
    MP1fieldSelectMagasins->addItem("id");
    MP1fieldSelectMagasins->addItem("adresse");
    MP1fieldSelectMagasins->addItem("code_postal");
    MP1fieldSelectMagasins->addItem("telephone");
    MP1fieldSelectMagasins->addItem("pays");
    MP1fieldSelectMagasins->addItem("date_ouverture");
    mainLayout->addWidget(MP1fieldSelectMagasins, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectMagasins->setVisible(false);
    MP1fieldSelectProduits = new QComboBox();
    MP1fieldSelectProduits->addItem("id");
    MP1fieldSelectProduits->addItem("nom");
    MP1fieldSelectProduits->addItem("categorie");
    MP1fieldSelectProduits->addItem("description");
    MP1fieldSelectProduits->addItem("prix_vente_unitaire");
    mainLayout->addWidget(MP1fieldSelectProduits, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectProduits->setVisible(false);
    MP1fieldSelectStocks = new QComboBox();
    MP1fieldSelectStocks->addItem("idProduit");
    MP1fieldSelectStocks->addItem("idMagasin");
    MP1fieldSelectStocks->addItem("quantite_restante");
    mainLayout->addWidget(MP1fieldSelectStocks, 5,0,1,1,Qt::AlignTop);
    MP1fieldSelectStocks->setVisible(false);

    /* --- REQ2 --- */

}

void MainWindow::selectMode(QString request)
{
    if(request == "REQUETE1")
    {
        cleanup();
        mp1Buildup();
    }
    else if(request == "REQUETE2")
    {
        cleanup();
        mp2Buildup();
    }
    else if(request == "REQUETE3")
    {
        cleanup();
        mp3Buildup();
    }
    else
    {
        QMessageBox::about(this, "ERROR", "Une erreur s'est produite ! code : 0E01");
    }
}

void MainWindow::selectTable(QString table)
{
    if(table == "clients")
    {
        MP1fieldSelectClient->setVisible(true);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(false);
    }
    else if(table == "employes")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(true);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(false);

    }
    else if(table == "fournisseurs")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(true);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(false);

    }
    else if(table == "magasins")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(true);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(false);

    }
    else if(table == "produits")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(true);
        MP1fieldSelectStocks->setVisible(false);

    }
    else if(table == "commandes")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(true);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(false);

    }
    else if(table == "approvisionnement")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(true);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(false);

    }
    else if(table == "stocks")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(false);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(true);

    }
    else if(table == "details_commande")
    {
        MP1fieldSelectClient->setVisible(false);
        MP1fieldSelectApprovisionnement->setVisible(false);
        MP1fieldSelectCommandes->setVisible(false);
        MP1fieldSelectDetailsCommande->setVisible(true);
        MP1fieldSelectEmployes->setVisible(false);
        MP1fieldSelectFournisseurs->setVisible(false);
        MP1fieldSelectMagasins->setVisible(false);
        MP1fieldSelectProduits->setVisible(false);
        MP1fieldSelectStocks->setVisible(false);

    }
    else
    {
        QMessageBox::about(this, "ERROR", "Une erreur s'est produite ! Code : 0E02");
    }
}

void MainWindow::MP1prepExecReq()
{

}

void MainWindow::customPrepExec()
{

}

void MainWindow::mp1Buildup()
{
    MP1tableDesc->setVisible(true);
    MP1tableSelect->setVisible(true);
    MP1fieldDesc->setVisible(true);
    MP1fieldSelectClient->setVisible(true);
    MP1filterDesc->setVisible(true);
    MP1filterSelect->setVisible(true);
    MP1valueDesc->setVisible(true);
    MP1value->setVisible(true);
}

void MainWindow::cleanup()
{
    MP1tableDesc->setVisible(false);
    MP1tableSelect->setVisible(false);
    MP1fieldDesc->setVisible(false);
    MP1fieldSelectClient->setVisible(false);
    MP1filterDesc->setVisible(false);
    MP1filterSelect->setVisible(false);
    MP1valueDesc->setVisible(false);
    MP1value->setVisible(false);
    MP1fieldSelectClient->setVisible(false);
    MP1fieldSelectApprovisionnement->setVisible(false);
    MP1fieldSelectCommandes->setVisible(false);
    MP1fieldSelectDetailsCommande->setVisible(false);
    MP1fieldSelectEmployes->setVisible(false);
    MP1fieldSelectFournisseurs->setVisible(false);
    MP1fieldSelectMagasins->setVisible(false);
    MP1fieldSelectProduits->setVisible(false);
    MP1fieldSelectStocks->setVisible(false);
}

void MainWindow::mp2Buildup()
{
    MP1tableSelect->setVisible(true);
}

void MainWindow::mp3Buildup()
{

}
