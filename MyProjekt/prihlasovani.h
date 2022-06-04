
#ifndef PRIHLASOVANI_H
#define PRIHLASOVANI_H
#pragma once
#include "login.h"

#include "smeny.h"
#include "user.h"
#include "evidence.h"




class prihlasovani : public QMainWindow
{
    Q_OBJECT
public:
    explicit prihlasovani(QList<User> users,
    QList<smeny> Smeny, User user, QWidget *parent = nullptr);

    ~prihlasovani();

    QMenu* filemenu;
    QAction* exit_act;
    QAction* log_out;
    QTabWidget *tabMain;


    QFrame* tab2;
    QVBoxLayout* tab2_l;
    QTextEdit* text;

    QList<User> users ;
    QList<smeny> Smeny;
    User user;

    QMenu* SmenyMenu;
    QFrame* SmenyFrame;

    QTableView* table2;
    QVBoxLayout* layout2;
    QStandardItemModel* model2;
    QTabWidget *tab22;


    QFrame* fMainInfo2;
    QFormLayout* form_l2;



    QFrame* smenaButtons;
    QHBoxLayout* but_smena;

    QPushButton* btn_odhlas;
    QPushButton* btn_prihlas;
    QPushButton* btn_smena_detail;
private slots:



    void detailSmenaCon();

    void onTableClicked2(const QModelIndex &inde);
    void smenaLogIn();
    void smenaLogOut();
    void logOut();


    void fillTable2(QTableView* table);

    void createMenuSmeny();


};

#endif // PRIHLASOVANI_H
