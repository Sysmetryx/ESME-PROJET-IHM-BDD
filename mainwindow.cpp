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
    connectLayout = new QGridLayout; //Layout secondaire dédié à la page de cpnnexion
    connectpageBuildup(); //Construit la page de connexion
    this->setCentralWidget (new QWidget(this));
    this->centralWidget()->setLayout(mainLayout);
}

void MainWindow::connectpageBuildup()
{
    portDesc = new QLabel(); //Label qui décrit le port
    portDesc->setText("Port :");
    connectLayout->addWidget(portDesc, 0, 0, 1, 1);
    hostDesc = new QLabel();//Label qui décrit l'hôte
    hostDesc->setText("Hote :");
    connectLayout->addWidget(hostDesc, 1, 0, 1, 1);
    userDesc = new QLabel();//Label qui décrit l'utilisateur
    userDesc->setText("Utilisateur :");
    connectLayout->addWidget(userDesc, 2, 0, 1, 1);
    pwdDesc = new QLabel();//Label qui décrit le mot de passe
    pwdDesc->setText("Mot de passe :");
    connectLayout->addWidget(pwdDesc, 3, 0, 1, 1);
    nameDesc = new QLabel();//Label qui décrit le nom de la base
    nameDesc->setText("Nom :");
    connectLayout->addWidget(nameDesc, 4, 0, 1, 1);
    portText = new QLineEdit();
    connectLayout->addWidget(portText, 0, 1, 1, 1 );
    portText->setToolTip("Entrez un numéro de port pour la connexion.");
    portText->setText(QString::number(port));
    hostText = new QLineEdit();
    hostText->setToolTip("Entrez une adresse d'hote pour la connexion.");
    connectLayout->addWidget(hostText, 1, 1, 1, 1);
    hostText->setText(host);
    userText = new QLineEdit();
    userText->setToolTip("Entrez un nom d'utilisateur pour la connexion.");
    connectLayout->addWidget(userText, 2, 1, 1, 1);
    userText->setText(user);
    pwdText = new QLineEdit();
    pwdText->setToolTip("Entrez un mot de passe pour la connexion.");
    connectLayout->addWidget(pwdText, 3, 1, 1, 1);
    pwdText->setText(pwd);
    pwdText->setEchoMode(QLineEdit::Password);
    nameText = new QLineEdit();
    nameText->setToolTip("Entrez un nom pour la base de données.");
    connectLayout->addWidget(nameText, 4, 1, 1, 1);
    nameText->setText(name);
    connector = new QPushButton("Connexion", this);
    connect(connector, &QPushButton::clicked, this, &MainWindow::connection);
    connectLayout->addWidget(connector, 5, 3, 1, 1);
    mainLayout->addLayout(connectLayout,0,0);
}

void MainWindow::connectpageCleanup()
{
    delete connector;
    delete portDesc;
    delete portText;
    delete hostDesc;
    delete hostText;
    delete userDesc;
    delete userText;
    delete pwdDesc;
    delete pwdText;
    delete nameDesc;
    delete nameText;
    delete connectLayout;
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
    }
    else
    {
         QMessageBox::about(this, "Connexion échouée", "La connexion a échoué");
    }
}


MainWindow::~MainWindow()
{

}
