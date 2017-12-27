#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QApplication>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QToolTip>

class MainWindow : public QMainWindow
{
    Q_OBJECT
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
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectpageBuildup();
    void connectpageCleanup();

public slots:
    void connection();

private:
    QGridLayout *mainLayout;
    QGridLayout *connectLayout;
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

};

#endif // MAINWINDOW_H
