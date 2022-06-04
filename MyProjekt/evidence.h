#ifndef EVIDENCE_H
#define EVIDENCE_H
#pragma once
#include <QFormLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMenu>
#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QTabWidget>
#include <QTextEdit>
#include <QFrame>
#include <QGroupBox>

#include "login.h"
#include "user.h"
#include "smeny.h"

class Evidence : public QMainWindow
{
    Q_OBJECT

public:
    Evidence(QList<User> users, QList<smeny> Smeny, QWidget *parent = 0);

    QMenu* filemenu;
    QAction* exit_act;
    QAction* log_out;
    QTabWidget *tabMain;


    QFrame* main_frame;

    QTableView* table;
    QVBoxLayout* layout;
    QStandardItemModel* model;
    QTabWidget *tab;

    QFrame* fMainInfo;
    QFormLayout* form_l;
    QLineEdit* name_edit;
    QLineEdit* sname_edit;
    QLineEdit* age_edit;
    QLineEdit* email_edit;



    QList<User> users ;
    QList<smeny> Smeny;

    bool admin = true;


    QWidget* tab1;
    QGridLayout* tab1_l;
    QLineEdit* ulice_edit;
    QLineEdit* cp_edit;
    QLineEdit* mesto_edit;
    QLineEdit* psc_edit;

    QFrame* tab2;
    QVBoxLayout* tab2_l;
    QTextEdit* text;

    QFrame* fButtons;
    QHBoxLayout* but_l;
    QPushButton* btn_new;
    QPushButton* btn_save;
    QPushButton* btn_del;
    QPushButton* btn_update;
    QPushButton* detail;


    QMenu* SmenyMenu;
    QFrame* SmenyFrame;

    QTableView* table2;
    QVBoxLayout* layout2;
    QStandardItemModel* model2;
    QTabWidget *tab22;


    QFrame* fMainInfo2;
    QFormLayout* form_l2;
    QLineEdit* datum_edit;
    QLineEdit* kapacita_edit;

    QTextEdit* popisek ;

    QFrame* smenaButtons;
    QHBoxLayout* but_smena;
    QPushButton* btn_smena_new;
    QPushButton* btn_smena_update;
    QPushButton* btn_smena_del;
    QPushButton* btn_smena_clear;
    QPushButton* btn_smena_detail;

    ~Evidence();


private slots:
    void newCon();
    void saveCon();
    void deleteCon();
    void updateCon();
    void customerDetaitCon();
    void onTableClicked(const QModelIndex &inde);

    void newSmenaCon();
    void saveSmenaCon();
    void deleteSmenaCon();
    void updateSmenaCon();
    void detailSmenaCon();

    void onTableClicked2(const QModelIndex &inde);


    void logOut();
private:
   void fillTable(QTableView* table);
   void fillTable2(QTableView* table);
   void createMenu();
   void createMenuSmeny();
};

#endif // EVIDENCE_H
