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
#include <QVBoxLayout>
#include <vector>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QTableView>
#include <QStandardItemModel>
#include <QList>
#include <QStackedWidget>
#include <QCheckBox>
#define q2c(string) string.toStdString()

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectpageBuildup();
    void connectpageCleanup();
    void connectpageRebuild();
    void mainpageBuildup();
    void customreqBuildup();
    void customreqCleanup();
    void customreqRebuild();
    void extractTables();
    void createTableBox();
    void createFieldBox();
    void mode1Buildup();
    void selectField(QString activeTable);
    QString prepareQuery1();
    QString prepareQuery1bis();

public slots:
    void connection();  
    void customQuery();
    void selectMode(QString activeMod);
    void execReq1();
    void makeInter();

private:
    /*---misc---*/
    QToolBar *mainMenu;
    QTableView *tableDisplay;
    QStandardItemModel *model;
    /*--- TABLES INFO ---*/
    std::vector<string> tableNames;
    QGridLayout *mainLayout;
    /*--- FIELD INFO ---*/
    std::vector<string> fieldNames;
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
    QString name = "auchan";
    /*--- CUSTOMREQ PAGE ---*/
    QComboBox *reqSelect;
    QLabel *reqDesc;
    QLabel *tableDesc;
    QLabel *customReqDesc;
    QLineEdit *customReq;
    QPushButton *customExec;
    /*--- REQ1 ---*/
    QString filtertype = "=";
    QLabel *MP1tableDesc;
    QComboBox *tableSelect;
    QComboBox *fieldSelect;
    QLineEdit *value;
    QComboBox *filter1;
    QComboBox *exactBox;
    QCheckBox *borderBox;
    QLineEdit *lowvalue;
    QLabel *lowvalueDesc;
    QLineEdit *highvalue;
    QLabel *highvalueDesc;

};

#endif // MAINWINDOW_H
