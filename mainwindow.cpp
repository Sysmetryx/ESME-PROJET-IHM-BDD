/*
___________________________________________________________________________________________________________________________________________________________________________________________________________________
|
|       EEEEEE       sSSSS  MM       MM     EEEEEE                      LAPORTE Nathan 2Z2                          V0.1                                EEEEEE       sSSSS  MM       MM     EEEEEE
|       EE         sS       MMMM   MMMM     EE                          laporte_n@esme.fr                           DECEMBRE 2017                       EE         sS       MMMM   MMMM     EE
|       EEEEE       sSS     MM  MM   MM     EEEEEE                      https://github.com/Sysmetryx/               PROJET IHM-BDD                      EEEEE       sSS     MM  MM   MM     EEEEEE
|       EE            Ss    MM       MM     EE                                                                      GUI/SQL                             EE            Ss    MM       MM     EE
|       EEEEE    SSSSs      MM       MM     EEEEEE                                                                  IHM sous Qt5 // BDD avec MySQL      EEEEE    SSSSs      MM       MM     EEEEEE
|_____________________________________________________________________________________________________________________________________________________________________________________________________________________
FONCTIONNEL :
Page de connexion à une base de données. Les infos de bases sont pour le root, mais si les comptes sont bien à jour, on peut se connecter à l'aide d'un compte utilisateur.
A VENIR :
Page de requête
*/
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainLayout = new QGridLayout; //Layout principal sur lequel viennet se greffer les layouts secondaires
    connectpageBuildup(); //Construit la page de connexion
    this->setCentralWidget (new QWidget(this));
    this->centralWidget()->setLayout(mainLayout);
}

void MainWindow::connectpageBuildup()
{
    portDesc = new QLabel(); //Label qui décrit le port
    portDesc->setText("Port :");
    mainLayout->addWidget(portDesc, 0, 0, 1, 1);
    hostDesc = new QLabel();//Label qui décrit l'hôte
    hostDesc->setText("Hote :");
    mainLayout->addWidget(hostDesc, 1, 0, 1, 1);
    userDesc = new QLabel();//Label qui décrit l'utilisateur
    userDesc->setText("Utilisateur :");
    mainLayout->addWidget(userDesc, 2, 0, 1, 1);
    pwdDesc = new QLabel();//Label qui décrit le mot de passe
    pwdDesc->setText("Mot de passe :");
    mainLayout->addWidget(pwdDesc, 3, 0, 1, 1);
    nameDesc = new QLabel();//Label qui décrit le nom de la base
    nameDesc->setText("Nom :");
    mainLayout->addWidget(nameDesc, 4, 0, 1, 1);
    portText = new QLineEdit();
    mainLayout->addWidget(portText, 0, 1, 1, 1 );
    portText->setToolTip("Entrez un numéro de port pour la connexion.");
    portText->setText(QString::number(port));
    hostText = new QLineEdit();
    hostText->setToolTip("Entrez une adresse d'hote pour la connexion.");
    mainLayout->addWidget(hostText, 1, 1, 1, 1);
    hostText->setText(host);
    userText = new QLineEdit();
    userText->setToolTip("Entrez un nom d'utilisateur pour la connexion.");
    mainLayout->addWidget(userText, 2, 1, 1, 1);
    userText->setText(user);
    pwdText = new QLineEdit();
    pwdText->setToolTip("Entrez un mot de passe pour la connexion.");
    mainLayout->addWidget(pwdText, 3, 1, 1, 1);
    pwdText->setText(pwd);
    pwdText->setEchoMode(QLineEdit::Password);
    nameText = new QLineEdit();
    nameText->setToolTip("Entrez un nom pour la base de données.");
    mainLayout->addWidget(nameText, 4, 1, 1, 1);
    nameText->setText(name);
    connector = new QPushButton("Connexion", this);
    connect(connector, &QPushButton::clicked, this, &MainWindow::connection);
    mainLayout->addWidget(connector, 5, 3, 1, 1);
}
void MainWindow::connectpageCleanup()
{
    connector->setVisible(false);
    portDesc->setVisible(false);
    portText->setVisible(false);
    hostDesc->setVisible(false);
    hostText->setVisible(false);
    userDesc->setVisible(false);
    userText->setVisible(false);
    pwdDesc->setVisible(false);
    pwdText->setVisible(false);
    nameDesc->setVisible(false);
    nameText->setVisible(false);
}
void MainWindow::connectpageRebuild()
{
    connector->setVisible(true);
    portDesc->setVisible(true);
    portText->setVisible(true);
    hostDesc->setVisible(true);
    hostText->setVisible(true);
    userDesc->setVisible(true);
    userText->setVisible(true);
    pwdDesc->setVisible(true);
    pwdText->setVisible(true);
    nameDesc->setVisible(true);
    nameText->setVisible(true);
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
         QMessageBox::about(this, "Connexion Réussie", "Vous êtes maintenant connecté");
         connectpageCleanup();
         mainpageBuildup();
    }
    else
    {
         QMessageBox::about(this, "Connexion échouée", "La connexion a échoué");
    }
}


MainWindow::~MainWindow()
{

}

void MainWindow::mainpageBuildup()
{
    mode2Buildup();
    mode2Cleanup();
    mode1Buildup();
    /*
    mainMenu = new QToolBar();
    this->addToolBar("mainMenu");
    QAction *ouvrir = new QAction("Ouvrir", this);
    this->connect(ouvrir, SIGNAL(triggered), qApp, SLOT(void));
    ouvrir->setShortcut(QKeySequence("Ctrl+L"));
    //ouvrir->setIcon(QIcon("B:\\Users\\NATHZN\\Desktop\\ouvrir.png"));
    ouvrir->setToolTip("Ouvrir un script .txt");
    mainMenu->addAction(ouvrir);
    QAction *sauvegarder = new QAction("Sauvegarder", this);
    this->connect(sauvegarder, SIGNAL(triggered), qApp, SLOT(void));
    sauvegarder->setShortcut(QKeySequence("Ctrl+S"));
    sauvegarder->setToolTip("Sauvegarder le resultat d'une requête");
    mainMenu->addAction(sauvegarder);
    QAction *refresh = new QAction("Rafraichir", this);
    this->connect(refresh, SIGNAL(triggered), qApp, SLOT(void));
    refresh->setShortcut(QKeySequence("Ctrl+R"));
    refresh->setToolTip("Rafraichir la base de données");
    mainMenu->addAction(refresh);*/ //WORK IN PROGRESS
    reqDesc = new QLabel("Choisissez une requête :");
    mainLayout->addWidget(reqDesc,0,0,1,1,Qt::AlignLeft);
    reqSelect = new QComboBox();
    reqSelect->addItem("Filtre Clients");
    //reqSelect->addItem("Extraction personalisée depuis une table");
    reqSelect->addItem("Insertion de données");
   // reqSelect->addItem("Recherche croisée");*/ //NOT DONE YET
    connect(reqSelect, SIGNAL(currentTextChanged(QString)), this, SLOT(selectMode()));
    mainLayout->addWidget(reqSelect,1,0,1,1,Qt::AlignLeft);
    customreqBuildup();

}

void MainWindow::selectMode()
{
    if(reqSelect->currentText() == "Filtre Clients")
    {
        mode1Rebuild();
    }
    else if(reqSelect->currentText() == "Insertion de données");
    {
        mode1Cleanup();
    }
}

void MainWindow::mode1Buildup()
{
    extractTables();
    mod1TableDesc = new QLabel("Cette requête a pour but \n de filtrer la table client \n avec ce paramètre :");
    mainLayout->addWidget(mod1TableDesc,3,0,1,1,Qt::AlignLeft);
    QSqlQuery query;
    if(query.exec("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE (TABLE_SCHEMA='auchan' AND TABLE_NAME='approvisionnement')"))
    {
        while(query.next())
        {
            fieldNames.push_back(q2c(query.value(0).toString()));
        }
        createFieldBox();
    }
    else
    {
        QMessageBox::about(this, "Tables non récupérées", "La récupération des tables a échouée");
    }
    exactBox = new QComboBox;
    exactBox->addItem("Contient");
    exactBox->addItem("Commence par");
    exactBox->addItem("fini par");
    exactBox->addItem("Condition");
    mainLayout->addWidget(exactBox, 5,0,1,1,Qt::AlignLeft);
    filter1 = new QComboBox;
    filter1->addItem("=");
    filter1->addItem("<=");
    filter1->addItem(">=");
    filter1->addItem("<");
    filter1->addItem(">");
    mainLayout->addWidget(filter1,6,0,1,1,Qt::AlignLeft);
    value = new QLineEdit();
    mainLayout->addWidget(value,7,0,1,1,Qt::AlignLeft);
    value->setObjectName("test1");
    borderBox = new QCheckBox("Cochez pour avoir une valeur \n comprise dans un ensemble", this);
    connect(borderBox, SIGNAL(clicked(bool)), this, SLOT(makeInter()));
    mainLayout->addWidget(borderBox, 8,0,1,1,Qt::AlignLeft);
    lowvalueDesc = new QLabel("Entrez la valeur minimum");
    mainLayout->addWidget(lowvalueDesc, 9,0,1,1,Qt::AlignLeft);
    lowvalueDesc->setVisible(false);
    lowvalue = new QLineEdit();
    mainLayout->addWidget(lowvalue, 10,0,1,1,Qt::AlignLeft);
    lowvalue->setVisible(false);
    highvalueDesc = new QLabel("Entrez la valeur maximum");
    mainLayout->addWidget(highvalueDesc, 11,0,1,1,Qt::AlignLeft);
    highvalueDesc->setVisible(false);
    highvalue = new QLineEdit();
    mainLayout->addWidget(highvalue, 12,0,1,1,Qt::AlignLeft);
    highvalue->setVisible(false);
    recherche1 = new QPushButton("recherche");
    connect(recherche1, SIGNAL(clicked(bool)), this, SLOT(execReq1()));
    mainLayout->addWidget(recherche1,13,0,1,1,Qt::AlignLeft);


}

void MainWindow::mode1Cleanup()
{
    mod1TableDesc->hide();
    fieldSelect->hide();
    value->hide();
    filter1->hide();
    exactBox->hide();
    borderBox->hide();
    lowvalue->hide();
    highvalue->hide();
    recherche1->hide();
    highvalueDesc->hide();
    lowvalueDesc->hide();
}

void MainWindow::mode1Rebuild()
{
    mod1TableDesc->show();
    fieldSelect->show();
    value->show();
    filter1->show();
    exactBox->show();
    borderBox->show();
    lowvalue->show();
    lowvalueDesc->show();
    highvalue->show();
    highvalueDesc->show();
    recherche1->show();
}

void MainWindow::customreqBuildup()
{
    customReqDesc = new QLabel("Requete speciale (MySQL)");
    mainLayout->addWidget(customReqDesc, 0,1,1,1,Qt::AlignTop);
    customReq = new QLineEdit();
    mainLayout->addWidget(customReq, 1,1,1,25,Qt::AlignTop);
    customExec = new QPushButton("Executer");
    connect(customExec, SIGNAL(clicked(bool)), this, SLOT(customQuery()));
    mainLayout->addWidget(customExec, 2,15,1,1,Qt::AlignTop);
}

void MainWindow::customreqCleanup()
{
    reqSelect->setVisible(false);
    reqDesc->setVisible(false);
    customReqDesc->setVisible(false);
    customReq->setVisible(false);
    customExec->setVisible(false);
}

void MainWindow::customreqRebuild()
{
    reqSelect->setVisible(true);
    reqDesc->setVisible(true);
    customReqDesc->setVisible(true);
    customReq->setVisible(true);
    customExec->setVisible(true);
}

void MainWindow::extractTables()
{
    QSqlQuery query;
    QString para1 = name;
    QString reqFull = para1.prepend("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.tables where table_schema='").append("'");
    if(query.exec(reqFull))
    {
        while(query.next())
        {
            tableNames.push_back(q2c(query.value(0).toString()));
        }
        QMessageBox::about(this, "Tables récupérées", "Les tables ont été extraites");
        createTableBox();
    }
    else
    {
        QMessageBox::about(this, "Tables non récupérées", "La récupération des tables a échouée");
    }
}

void MainWindow::selectField(QString activeTable)
{
    for(int i = 0; i < tableNames.size(); i++)
    {
        if(activeTable == QString::fromStdString(tableNames[i]))
        {
            QSqlQuery query;
            QString para1 = name;
            QString para2 = activeTable;
            QString reqFull = para1.prepend("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE (TABLE_SCHEMA='").append("' AND TABLE_NAME='").append(para2).append("')");
            if(query.exec(reqFull))
            {
                fieldNames.clear();
                while(query.next())
                {

                   fieldNames.push_back(q2c(query.value(0).toString()));

                }
                for(int i = 0; i < fieldSelect->count(); i++)
                    fieldSelect->removeItem(i);
                createFieldBox();
            }
            else
            {
                QMessageBox::about(this, "Champs non récupérées", "La récupération des champs a échouée, \n aucune table avec ce nom !");
            }
        }
        else
        {
            //QMessageBox::about(this, "Champs non récupérés", "La récupération des champs a échouée, \n aucune table avec ce nom 2 !");
        }
    }
}


void MainWindow::createFieldBox()
{
    fieldSelect->clear();
    for(int i =0; i < fieldNames.size(); i++)
    {
        QString temp = QString::fromStdString(fieldNames[i]);
        fieldSelect->addItem(temp);
    }
    mainLayout->addWidget(fieldSelect, 4,0,1,1,Qt::AlignLeft);
}

void MainWindow::createTableBox()
{
    tableSelect = new QComboBox();
    for(int i =0; i < tableNames.size(); i++)
    {
        QString temp = QString::fromStdString(tableNames[i]);
        tableSelect->addItem(temp);
    }
    connect(tableSelect, SIGNAL(currentTextChanged(QString)), this, SLOT(selectField(QString)));
    mainLayout->addWidget(tableSelect, 2,0,1,1,Qt::AlignLeft);
}

void MainWindow::customQuery()
{
    QSqlQuery query;
    QString sqlQuery = customReq->text();
    bool firstTime = true;
    int rows = 0;
    int columns = 0;
    QStandardItem *element;
    model = new QStandardItemModel(1,columns,this);
    if(query.exec(sqlQuery));
    {
        columns = query.record().count();
        while(query.next())
        {
            for(int i = 0; i < columns; i++)
            {
                if(firstTime)
                {
                    model->setHeaderData(i, Qt::Horizontal, query.record().fieldName(i));
                }
                element = new QStandardItem(query.value(i).toString());
                element->setEditable(false);
                model->setItem(rows,i,element);
            }
         rows++;
        }
    }
    tableDisplay = new QTableView();
    tableDisplay->setModel(model);
    tableDisplay->setSortingEnabled(true);
    mainLayout->addWidget(tableDisplay, 3,1,25,25);
}


void MainWindow::execReq1()
{
    QString queryText;
    if(!borderBox->isChecked())
    {
        queryText = prepareQuery1();
    }
    else
    {
        queryText = prepareQuery1bis();
    }
    QMessageBox::about(this, "request :", queryText);
    QSqlQuery query;
    int rows = 0;
    int columns = fieldNames.size();
    QStandardItem *element;
    model = new QStandardItemModel(1,columns,this);
    for(int i =0; i < columns; i++)
        model->setHeaderData(i, Qt::Horizontal, QString::fromStdString(fieldNames[i]));
    if(query.exec(queryText));
    {
        while(query.next())
        {
            for(int j = 0; j < columns; j++)
            {
                element = new QStandardItem(query.value(j).toString());
                element->setEditable(false);
                model->setItem(rows,j,element);
            }
        rows++;
        }
    }
    tableDisplay = new QTableView();
    tableDisplay->setModel(model);
    tableDisplay->setSortingEnabled(true);
    mainLayout->addWidget(tableDisplay, 3,1,25,25);
}

QString MainWindow::prepareQuery1()
{
    QString tableUsed = tableSelect->currentText();
    QString queryPrepared;
    QString filterType;
    int type = exactBox->currentIndex();
    switch (type){
    case 0:
        tableUsed.prepend("SELECT * FROM ");
        tableUsed.append(" ");
        queryPrepared = tableUsed.append("WHERE(").append(fieldSelect->currentText()).append(" LIKE '%").append(value->text()).append("%')");
    break;
    case 1:
        tableUsed.prepend("SELECT * FROM ");
        tableUsed.append(" ");
        queryPrepared = tableUsed.append("WHERE(").append(fieldSelect->currentText()).append(" LIKE '").append(value->text()).append("%')");
    break;
    case 2:
        tableUsed.prepend("SELECT * FROM ");
        tableUsed.append(" ");
        queryPrepared = tableUsed.append("WHERE(").append(fieldSelect->currentText()).append(" LIKE '%").append(value->text()).append("')");
    break;
    case 3:
    filterType = filter1->currentText();
    tableUsed.prepend("SELECT * FROM ");
    tableUsed.append(" ");
    queryPrepared = tableUsed.append("WHERE(").append(fieldSelect->currentText()).append(" ").append(filterType).append(" '").append(value->text()).append("')");
    break;
    }
    return queryPrepared;
}

void MainWindow::makeInter()
{
    if(borderBox->isChecked())
    {
        value->setVisible(false);
        filter1->setVisible(false);
        exactBox->setVisible(false);
        lowvalueDesc->setVisible(true);
        lowvalue->setVisible(true);
        highvalueDesc->setVisible(true);
        highvalue->setVisible(true);
    }
    else
    {
        value->setVisible(true);
        filter1->setVisible(true);
        exactBox->setVisible(true);
        lowvalueDesc->setVisible(false);
        lowvalue->setVisible(false);
        highvalueDesc->setVisible(false);
        highvalue->setVisible(false);
    }
}

QString MainWindow::prepareQuery1bis()
{
    QString tableUsed = tableSelect->currentText();
    QString queryPrepared;
    tableUsed.prepend("SELECT * FROM ");
    tableUsed.append(" ");
    queryPrepared = tableUsed.append("WHERE(").append(fieldSelect->currentText()).append(" <= '").append(highvalue->text()).append("' ").append("AND ").append(fieldSelect->currentText()).append(" >= '").append(lowvalue->text()).append("')");
    return queryPrepared;
}

void MainWindow::mode2Buildup()
{

}

void MainWindow::mode2Rebuild()
{

}
void MainWindow::mode2Cleanup()
{

}
