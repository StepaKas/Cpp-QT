#include "evidence.h"
#include <QLabel>
#include <QLineEdit>
#include <QHeaderView>
#include <QMenuBar>
#include <QWidget>
#include <QMessageBox>
#include <iostream>
#include <string>
#include "globals.h"

Evidence::Evidence(QList<User> users, QList<smeny> Smeny,QWidget *parent)
    : QMainWindow(parent) , users(users), Smeny(Smeny)
{/*
    (QString name ,QString surname ,QString email ,QString password ,QString Ulice ,QString Mesto ,QString PSC ,
             QString C_P ,QString Poznamka ,QString DatumNarozeni )*/

/*
    User u1 ("David", "Davidson", "david.davidson@seznam.cz","abc123", "U davida", "Jeruzalem", "1958 8", "5", "David zabil goliase",
        "19/4/2500 BC" );
    User u2 ("Golias", "Golemson", "gol.gol@seznam.cz","abc123", "Goliasova", "Jeruzalem", "1622 8", "3", "Goliase zabil david",
        "20/9/2530 BC" );
    User u3 ("Jidas", "Jidasson", "jid.jid@seznam.cz","abc123", "Jezisova", "Devata", "369 86", "1", "Zradil...",
        "19/4/2500 BC" );
    User u4 ("Hades", "Kronson", "had.had@seznam.cz","abc123", "U trojhlaveho", "Peklo", "365 98", "5", "Buh podsveti",
        "1/1/10000 BC" );
    User u5 ("John", "Johnson", "jon.jon@gmail.com","abc123", "Novy", "New York", "96 5 57", "53", "Hodne pracuje, velke svaly, hodne unese",
        "19/4/1998" );
    User u6 ("Peter", "Peterson", "pete.pete@seznam.cz","abc123", "Stara", "San Francisco", "65 87 8", "10", "Bacha na něho, zlobí",
        "20/9/1990 BC" );
    User u7 ("Tereza", "Mala", "ter.mal@seznam.cz","abc123", "K Mytu", "Darkovice", "32 55 8", "63", "Dobrá v kuchyni, nedávejte ji ke kase neumí počítat",
        "19/4/1995 BC" );
    User u8 ("Kristina", "Spechava", "kri.spe@seznam.cz","abc123", "U Modreho", "Hlucin", "365 89", "-1", "Celkem ok",
        "1/1/1998 BC" );

    User u9 ("Ondrej", "Trkavy", "ond.trk@seznam.cz","abc123", "U Ondry", "Ostrava", "1958 8", "5", "Dobry borec",
        "19/4/1996 BC" );
    User u10 ("Marek", "Straceny", "mar.lost@gmail.cz","abc123", "Masarykova", "Praha", "36 52 8", "3", "Hodne rychly",
        "20/9/1974 BC" );
    User u11 ("Nikola", "Tesla", "tes.nik@seznam.cz","abc123", "Severni", "Belehrad", "369 86", "1", "Pomaly",
        "19/4/1900 BC" );
    User u12 ("Mikulas", "Kopernik", "toci.se@seznam.cz","abc123", "U zapaleneho", "Kostnice", "365 98", "5", "Hodne hruby",
        "1/1/1500 BC" );
    u9.isAdmin = true;
     //kapacita(kapacita),  datum(datum), popisek(popisek)

    smeny s1 (5 , "25/6/2020","Bude teplo, vemte si pití. Pojedem dlouho do večera.");
    smeny s2 (2 , "27/6/2020","Bude zima, vemte si teplé oblečení. Pojedem dlouho do večera.");
    smeny s3 (3 , "29/6/2020","Nejaka informace PH");
    users = {u1, u2 ,u3 ,u4, u5,u6,u7,u8,u9,u10,u11,u12};
    Smeny = {s1, s2, s3};
    Smeny[0].AddUser(users[0]);
    Smeny[0].AddUser(users[1]);
    Smeny[0].AddUser(users[2]);
    Smeny[0].AddUser(users[3]);
    Smeny[0].AddUser(users[4]);

    Smeny[1].AddUser(users[11]);
    Smeny[1].AddUser(users[10]);

    Smeny[2].AddUser(users[4]);
    Smeny[2].AddUser(users[3]);
    Smeny[2].AddUser(users[9]);*/


    createMenu();

    layout = new QVBoxLayout();

    table = new QTableView();
    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fillTable(table);



    name_edit = new QLineEdit();
    name_edit->setMaximumWidth(100);
    sname_edit = new QLineEdit();
    sname_edit->setMaximumWidth(100);
    age_edit = new QLineEdit();
    age_edit->setMaximumWidth(100);
    email_edit = new QLineEdit();
    email_edit->setMaximumWidth(100);

    fMainInfo = new QFrame();

    form_l = new QFormLayout();

    form_l->setRowWrapPolicy(QFormLayout::DontWrapRows);
    form_l->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    form_l->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    form_l->setLabelAlignment(Qt::AlignLeft);

    form_l->addRow(new QLabel(QString("Jmeno:")), name_edit);
    form_l->addRow(new QLabel(QString("Prijmeni:")), sname_edit);
    form_l->addRow(new QLabel(QString("Vek:")), age_edit);
    form_l->addRow(new QLabel(QString("Email:")), email_edit);
    fMainInfo->setLayout(form_l);

    layout->addWidget(table);
    layout->addWidget(fMainInfo);

    tab = new QTabWidget();
    tab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout->addWidget(tab);

    tab1 = new QFrame();
    tab1_l = new QGridLayout();

    ulice_edit = new QLineEdit();
    cp_edit = new QLineEdit();
    mesto_edit = new QLineEdit();
    psc_edit = new QLineEdit();

    ulice_edit->setMaximumWidth(100);
    cp_edit->setMaximumWidth(30);
    mesto_edit->setMaximumWidth(100);
    psc_edit->setMaximumWidth(50);

    tab1_l->addWidget(new QLabel(QString("Ulice:")), 0, 0);
    tab1_l->addWidget(ulice_edit, 0, 1);
    tab1_l->addWidget(new QLabel(QString("Mesto:")), 1, 0);
    tab1_l->addWidget(mesto_edit, 1, 1);
    tab1_l->addWidget(new QLabel(QString("PSC:")), 2, 0);
    tab1_l->addWidget(psc_edit, 2, 1);
    tab1_l->addWidget(new QLabel(QString("c.p.:")), 0, 2);
    tab1_l->addWidget(cp_edit, 0, 3);

    tab1_l->setSizeConstraint(QLayout::SetFixedSize);
    tab1->setLayout(tab1_l);
    tab->addTab(tab1, QString("Adresa"));

    text = new QTextEdit();
    text->setMaximumHeight(75);

    tab2 = new QFrame();
    tab2_l = new QVBoxLayout();
    tab2_l->addWidget(text);
    tab2->setLayout(tab2_l);
    tab->addTab(tab2, QString("Poznamka"));

    // Tlacitka: Novy, Ulozit, Smazat

    fButtons = new QFrame();
    but_l = new QHBoxLayout();

    btn_new = new QPushButton("Vyčisti");
    but_l->addWidget(btn_new);
    btn_save = new QPushButton("Nový");
    but_l->addWidget(btn_save);
    btn_del = new QPushButton("Smazat");
    but_l->addWidget(btn_del);
    btn_update = new QPushButton("Uprav");
    but_l->addWidget(btn_update);
    detail = new QPushButton("Detail");
    but_l->addWidget(detail);

    connect(btn_new, SIGNAL (released()), this, SLOT (newCon()));
    connect(btn_save, SIGNAL (released()), this, SLOT (saveCon()));
    connect(btn_del, SIGNAL (released()), this, SLOT (deleteCon()));
    connect(btn_update, SIGNAL (released()), this, SLOT (updateCon()));
    connect(detail, SIGNAL (released()), this, SLOT (customerDetaitCon()));

    connect(table, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));

    fButtons->setLayout(but_l);
    layout->addWidget(fButtons);


    main_frame = new QFrame();
    main_frame->setLayout(layout);


//dole je smena


    layout2 = new QVBoxLayout();

    table2 = new QTableView();
    table2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fillTable2(table2);



    datum_edit = new QLineEdit();
    datum_edit->setMaximumWidth(100);
    kapacita_edit = new QLineEdit();
    kapacita_edit->setMaximumWidth(100);

    popisek  = new QTextEdit ();
    popisek->setMaximumHeight(75);


    fMainInfo2 = new QFrame();

    form_l2 = new QFormLayout();

    form_l2->setRowWrapPolicy(QFormLayout::DontWrapRows);
    form_l2->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    form_l2->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    form_l2->setLabelAlignment(Qt::AlignLeft);

    form_l2->addRow(new QLabel(QString("Datum:")), datum_edit);
    form_l2->addRow(new QLabel(QString("Kapacita:")), kapacita_edit);
    form_l2->addRow(popisek);
    fMainInfo2->setLayout(form_l2);




    smenaButtons = new QFrame();
    but_smena = new QHBoxLayout();

    btn_smena_clear = new QPushButton("Vyčisti");
    but_smena->addWidget(btn_smena_clear);
    btn_smena_new = new QPushButton("Nový");
    but_smena->addWidget(btn_smena_new);
    btn_smena_del = new QPushButton("Smazat");
    but_smena->addWidget(btn_smena_del);
    btn_smena_update = new QPushButton("Uprav");
    but_smena->addWidget(btn_smena_update);
    btn_smena_detail = new QPushButton("Detail");
    but_smena->addWidget(btn_smena_detail);

    connect(btn_smena_clear, SIGNAL (released()), this, SLOT (newSmenaCon()));
    connect(btn_smena_new, SIGNAL (released()), this, SLOT (saveSmenaCon()));
    connect(btn_smena_del, SIGNAL (released()), this, SLOT (deleteSmenaCon()));
    connect(btn_smena_update, SIGNAL (released()), this, SLOT (updateSmenaCon()));
    connect(btn_smena_detail, SIGNAL (released()), this, SLOT (detailSmenaCon()));

    connect(table2, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked2(const QModelIndex &)));



    smenaButtons->setLayout(but_smena);

    layout2->addWidget(smenaButtons);

    layout2->addWidget(table2);
    layout2->addWidget(fMainInfo2);



    SmenyFrame = new QFrame();
    SmenyFrame->setLayout(layout2);
    tabMain = new QTabWidget();
    tabMain->addTab(main_frame, QString("Uživatelé"));
    tabMain->addTab(SmenyFrame, QString("Směny"));

    setCentralWidget(tabMain);
}

void Evidence::newCon()
{
    name_edit->clear();
    sname_edit->clear();
    age_edit->clear();
    psc_edit->clear();
    cp_edit->clear();
    mesto_edit->clear();
    ulice_edit->clear();
    email_edit->clear();
    text->clear();
    fillTable(table);

}
void Evidence:: newSmenaCon(){
    datum_edit->clear();
    kapacita_edit->clear();
    popisek->clear();
    fillTable2(table2);
}
void Evidence::saveCon()
{
    if(name_edit->text() == "" || sname_edit->text() == "" || age_edit->text() == "")
    {
        QMessageBox::information(this, "Info", "Uživatele nelze přidat,\nmusíte vyplnit veškeré údaje");
        return;
    }
    /*
    (QString name ,QString surname ,QString email ,QString password ,QString Ulice ,QString Mesto ,QString PSC ,
             QString C_P ,QString Poznamka ,QString DatumNarozeni )*/

    User u (name_edit->text(),sname_edit->text(), email_edit->text(), "PASSWORD_PLACOHOLDER",ulice_edit->text(), mesto_edit->text(),psc_edit->text(),
            cp_edit->text(), text->toPlainText(), age_edit->text());
     users.append(u);


    fillTable(table);

    QMessageBox::about(this, "Info", "Uživatele byl úspěšně\npřidán");
}

void Evidence:: saveSmenaCon(){
    if(datum_edit->text() == "" || kapacita_edit->text() == "" || popisek->toPlainText() == "")
    {
        QMessageBox::information(this, "Info", "Směnu nelze přidat,\nmusíte vyplnit veškeré údaje");
        return;
    }

//(int kapacita,QString datum, QString popisek)

    smeny s (kapacita_edit->text().toInt(),(datum_edit->text()) ,popisek->toPlainText() );
     Smeny.append(s);

    fillTable2(table2);

    QMessageBox::about(this, "Info", "Směna byla úspěšně\npřidána");
}

void Evidence::deleteCon()
{
    int index = -1;

    QModelIndexList selection = table->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex in = selection.at(i);
        {
            index = in.row();
            break;
        }
    }

    if(index != -1)     //platný index pole na které uživatel klikl
    {


        for (int i = 0 ; i <  Smeny.size(); i++){
            for (int j = 0 ; j <  Smeny[i].users.size(); j++){
                if ( users[index].email ==  Smeny[i].users[j].email){
                      Smeny[i].RemoveUser( users[index]);
                }
            }

        }
         users.removeAt(index);
        fillTable(table);
        fillTable2(table2);
        QMessageBox::about(this, "Info", "Uživatele byl úspěšně\nodstraněn");
    }else
    {
        QMessageBox::information(this, "Info", "Uživatele nelze odstranit\nklikněte prosím na číslo v\nlevém sloupci");
    }
}

void Evidence::deleteSmenaCon()
{
    int index = -1;

    QModelIndexList selection = table2->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex in = selection.at(i);
        {
            index = in.row();
            break;
        }
    }

    if(index != -1)     //platný index pole na které uživatel klikl
    {

         Smeny.removeAt(index);
        fillTable2(table2);

        QMessageBox::about(this, "Info", "Směna byla úspěšně\nodstraněna");
    }else
    {
        QMessageBox::information(this, "Info", "Směna nelze odstranit\nklikněte prosím na číslo v\nlevém sloupci");
    }
}
void Evidence::customerDetaitCon(){
    int index = -1;

    QModelIndexList selection = table->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex in = selection.at(i);
        {
            index = in.row();
            break;
        }
    }

    if(index != -1)     //platný index pole na které uživatel klikl
    {



        QMessageBox::about(this, "Info",  users[index].info());
    }else
    {
        QMessageBox::information(this, "Info", "Uživatele klikněte prosím na číslo v\nlevém sloupci");
    }
}


void Evidence::detailSmenaCon(){
    int index = -1;

    QModelIndexList selection = table2->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex in = selection.at(i);
        {
            index = in.row();
            break;
        }
    }

    if(index != -1)     //platný index pole na které uživatel klikl
    {



        QMessageBox::about(this, "Info",  Smeny[index].info());
    }else
    {
        QMessageBox::information(this, "Info", "Uživatele klikněte prosím na číslo v\nlevém sloupci");
    }
}
void Evidence::updateCon()
{
    int index = -1;

    QModelIndexList selection = table->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex in = selection.at(i);
        {
            index = in.row();
            break;
        }
    }

    if(index != -1)
    {
        /*
(QString name ,QString surname ,QString email ,QString password ,QString Ulice ,QString Mesto ,QString PSC ,
         QString C_P ,QString Poznamka ,QString DatumNarozeni )
*/
        users[index].name = name_edit->text();
        users[index].surname = sname_edit->text();
        users[index].email = email_edit->text();
        users[index].Ulice = ulice_edit->text();
        users[index].Mesto = mesto_edit->text();
        users[index].PSC = psc_edit->text();
        users[index].C_P = cp_edit->text();
        users[index].Poznamka = text->toPlainText();





        fillTable(table);

        QMessageBox::about(this, "Info", "Uživatele byl úspěšně\nupraven");
    }else
    {
        QMessageBox::information(this, "Info", "Uživatele nelze upravit\nklikněte prosím na číslo v\nlevém sloupci");
    }
}

void Evidence::updateSmenaCon()
{
    int index = -1;

    QModelIndexList selection = table2->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex in = selection.at(i);
        {
            index = in.row();
            break;
        }
    }

    if(index != -1 )
    {
        if (kapacita_edit->text().toInt() <  Smeny[index].soucastny_pocet || kapacita_edit->text().toInt() <= 0){
            QMessageBox::about(this, "Info", "Spatne zadane kapacita");
            return;
        }
        Smeny[index].kapacita = kapacita_edit->text().toInt();
        Smeny[index].datum = (datum_edit->text());
        Smeny[index].popisek = ( popisek->toPlainText());


        fillTable2(table2);

        QMessageBox::about(this, "Info", "Směna byla úspěšně\nupravena");
    }else
    {
        QMessageBox::information(this, "Info", "Směnu nelze upravit\nklikněte prosím na číslo v\nlevém sloupci");
    }
}



void Evidence::createMenu()
{
    filemenu = new QMenu("&Soubor");
    exit_act = new QAction("&Konec", this);
    log_out = new QAction("&Log out", this);
    filemenu->addAction(exit_act);
    filemenu->addAction(log_out);
    connect(exit_act, SIGNAL(triggered()), this, SLOT(close()));
    connect(log_out, SIGNAL(triggered()), this, SLOT(logOut()));

    menuBar()->addMenu(filemenu);
}
void Evidence::logOut (){
  /*  QMessageBox msgBox2;
    msgBox2.setText(QString::number(this->Smeny.size()));
    msgBox2.exec();*/

    Login *  l = new Login();
    for (int i = 0; i < users.size(); i++){
        l->users.push_back(users[i]);
    }
    for (int i = 0; i < Smeny.size(); i++){
       l->Smeny.push_back(Smeny[i]);
    }
    l->setMinimumSize(100,100);
    l->show();
    this->hide();
}
void Evidence::createMenuSmeny()
{
    SmenyMenu = new QMenu("&Neco");
    menuBar()->addMenu(SmenyMenu);
}
void Evidence::onTableClicked(const QModelIndex &index)
{

    if (index.isValid()) {
        name_edit->setText( users[index.row()].name);
        sname_edit->setText( users[index.row()].surname);
        age_edit->setText( users[index.row()].DatumNarozeni);
        email_edit->setText( users[index.row()].email);
        ulice_edit->setText( users[index.row()].Ulice);
        cp_edit ->setText( users[index.row()].C_P);
        mesto_edit->setText( users[index.row()].Mesto);
        psc_edit ->setText( users[index.row()].PSC);
        text->setText( users[index.row()].Poznamka);
    }
}

void Evidence::onTableClicked2(const QModelIndex &index)
{

    if (index.isValid()) {
        kapacita_edit->setText(QString::number( Smeny[index.row()].kapacita));
        datum_edit->setText( Smeny[index.row()].datum);
        popisek->setText( Smeny[index.row()].popisek);

    }
}

void Evidence::fillTable(QTableView* table)
{


    int nrow =  users.length();



    const char* cols[] = { "Jmeno", "Prijmeni", "Vek", "Email"};

    int ncol = 4;

    model = new QStandardItemModel( nrow, ncol, this );

    for (int r=0; r<ncol; r++){
        model->setHorizontalHeaderItem( r, new QStandardItem( QString(cols[r] )) );
    }
    for( int r=0; r<nrow; r++ )
    {
        QStandardItem *item_name = new QStandardItem(QString( users[r].name));
        QStandardItem *item_sname = new QStandardItem(QString( users[r].surname));
        QStandardItem *item_ages = new QStandardItem(QString( users[r].DatumNarozeni));
        QStandardItem *item_email = new QStandardItem(QString( users[r].email));
        model->setItem(r, 0, item_name);
        model->setItem(r, 1, item_sname);
        model->setItem(r, 2, item_ages);
        model->setItem(r, 3, item_email);
    }
    table->setModel(model);

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void Evidence::fillTable2(QTableView* table2)
{


    int nrow =  Smeny.length();





    const char* cols[] = { "Datum", "Kapacita", "Popisek", "Soucastny pocet"};

    int ncol = 4;

    model2 = new QStandardItemModel( nrow, ncol, this );

    for (int r=0; r<ncol; r++){
        model2->setHorizontalHeaderItem( r, new QStandardItem( QString(cols[r] )) );
    }
    for( int r=0; r<nrow; r++ )
    {

        QStandardItem *item_date = new QStandardItem(QString( Smeny[r].datum));
        QStandardItem *item_capa = new QStandardItem(QString::number( Smeny[r].kapacita));
        QStandardItem *item_desc = new QStandardItem(QString( Smeny[r].popisek));
        QStandardItem *item_current = new QStandardItem(QString::number( Smeny[r].soucastny_pocet));
        model2->setItem(r, 0, item_date);
        model2->setItem(r, 1, item_capa);
        model2->setItem(r, 2, item_desc);
        model2->setItem(r, 3, item_current);
    }
    table2->setModel(model2);

    table2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}


Evidence::~Evidence()
{

}

