
#include "prihlasovani.h"
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>


prihlasovani::prihlasovani(QList<User> users,
                           QList<smeny> Smeny,User user,QWidget *parent) : QMainWindow(parent)
                            , users(users), Smeny(Smeny) ,user(user)
{
    createMenuSmeny();
    layout2 = new QVBoxLayout();

    table2 = new QTableView();
    table2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fillTable2(table2);






    fMainInfo2 = new QFrame();

    form_l2 = new QFormLayout();

    form_l2->setRowWrapPolicy(QFormLayout::DontWrapRows);
    form_l2->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    form_l2->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    form_l2->setLabelAlignment(Qt::AlignLeft);


    fMainInfo2->setLayout(form_l2);




    smenaButtons = new QFrame();
    but_smena = new QHBoxLayout();


    btn_smena_detail = new QPushButton("Detail");
    btn_odhlas= new QPushButton("Odhlásit");
    btn_prihlas= new QPushButton("Přihlásit");
    but_smena->addWidget(btn_smena_detail);
    but_smena->addWidget(btn_odhlas);
    but_smena->addWidget(btn_prihlas);

    connect(btn_smena_detail, SIGNAL (released()), this, SLOT (detailSmenaCon()));
    connect(btn_odhlas, SIGNAL (released()), this, SLOT (smenaLogOut()));
    connect(btn_prihlas, SIGNAL (released()), this, SLOT (smenaLogIn()));
    connect(table2, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked2(const QModelIndex &)));



    smenaButtons->setLayout(but_smena);

    layout2->addWidget(smenaButtons);

    layout2->addWidget(table2);
    layout2->addWidget(fMainInfo2);



    SmenyFrame = new QFrame();
    SmenyFrame->setLayout(layout2);


    setCentralWidget(SmenyFrame);
}



prihlasovani::~prihlasovani()
{

}

void prihlasovani::detailSmenaCon(){
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
void prihlasovani::smenaLogIn(){
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



          if (Smeny[index].AddUser(this->user)){
              QMessageBox::information(this, "Info", "Uživatel byl přidán\nna směnu.");
          }
          else{
              QMessageBox::information(this, "Info", "Uživatel nebyl přidán\nna směnu.");
          }
    }else
    {
        QMessageBox::information(this, "Info", "Uživatele klikněte prosím na číslo v\nlevém sloupci");
    }
    fillTable2(table2);
}

void prihlasovani::smenaLogOut(){
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



          if (Smeny[index].RemoveUser(this->user)){
              QMessageBox::information(this, "Info", "Uživatel byl odebrán\nna směnu.");
          }
          else{
              QMessageBox::warning(this, "Info", "Uživatel nebyl přidán\nna směnu.");
          }
    }else
    {
        QMessageBox::warning(this, "Info", "Uživatele klikněte prosím na číslo v\nlevém sloupci");
    }
    fillTable2(table2);
}
void prihlasovani::logOut (){
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
void prihlasovani::createMenuSmeny()
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

void prihlasovani::onTableClicked2(const QModelIndex &index)
{


}

void prihlasovani::fillTable2(QTableView* table2)
{


    int nrow =  Smeny.length();





    const char* cols[] = { "Datum", "Kapacita",  "Pocet" , "Prihlasen"};

    int ncol = 4;
    auto tick = "✓";
    auto cross = "✗";
    model2 = new QStandardItemModel( nrow, ncol, this );

    for (int r=0; r<ncol; r++){
        model2->setHorizontalHeaderItem( r, new QStandardItem( QString(cols[r] )) );
    }
    auto is_logged = "";
                   //     QMessageBox::information(this, "Info", this->user.info());
    for( int r=0; r<nrow; r++ )
    {

            for (int j = 0 ; j <Smeny[r].users.size(); j ++){
                    if(this->user.email == Smeny[r].users[j].email ){
                        is_logged = tick;
                        //QMessageBox::information(this,"Info" , Smeny[r].users[j].info() );

                        goto found;
                    }
            }


        is_logged = cross;
found:
        QStandardItem *item_date = new QStandardItem(QString( Smeny[r].datum));
        QStandardItem *item_capa = new QStandardItem(QString::number( Smeny[r].kapacita));

        QStandardItem *item_current = new QStandardItem(QString::number( Smeny[r].soucastny_pocet));
        QStandardItem *item_logged = new QStandardItem(is_logged);
        model2->setItem(r, 0, item_date);
        model2->setItem(r, 1, item_capa);

        model2->setItem(r, 2, item_current);
        model2->setItem(r, 3, item_logged);
    }
    table2->setModel(model2);

    table2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}
