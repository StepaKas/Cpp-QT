#include "login.h"
#include "prihlasovani.h"

#include <QMessageBox>




Login::Login(QWidget *parent) : QMainWindow(parent)
{



    email_edit = new QLineEdit();
    email_edit->setMinimumWidth(100);

    password_edit = new QLineEdit();
    password_edit->setMinimumWidth(100);
    password_edit->setEchoMode(QLineEdit::Password);
    form_l = new QFormLayout();

    form_l->setRowWrapPolicy(QFormLayout::DontWrapRows);
    form_l->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    form_l->setFormAlignment(Qt::AlignHCenter | Qt::AlignTop);
    form_l->setLabelAlignment(Qt::AlignLeft);

    form_l->addRow(new QLabel(QString("Email:")), email_edit);
    form_l->addRow(new QLabel(QString("Heslo:")), password_edit);

    but_l = new QHBoxLayout();
    submit_but = new QPushButton("Log In");
    but_l->addWidget(submit_but);

    fMainInfo = new QFrame();
    fMainInfo->setLayout(form_l);

    connect(submit_but, SIGNAL (released()), this, SLOT (log_in()));

    fButtons = new QFrame();



    layout = new QVBoxLayout();
    layout->addWidget(fMainInfo);
    fButtons->setLayout(but_l);
    layout->addWidget(fButtons);
    main_frame = new QFrame();
    main_frame->setLayout(layout);
    setCentralWidget(main_frame);
    email_edit->setText("ter.mal@seznam.cz");
    password_edit->setText("abc123");
}




void Login::log_in (){

    auto email = email_edit->text();
    auto heslo =  password_edit->text();
    for (int i = 0; i < users.size(); i++){
        if (email == users[i].email && heslo == users[i].password){
            if (users[i].isAdmin){
                Evidence* w = new Evidence(this->users, this->Smeny);
                w->setMinimumSize(400,500);
                w->isActiveWindow();
                w->show();
                this->hide();
                return;
            }
            else {
                prihlasovani* w = new prihlasovani(this->users, this->Smeny ,  users[i]);
                w->setMinimumSize(400,500);
                w->isActiveWindow();
                w->show();

                this->hide();
                return;
            }
        }
    }
    QMessageBox::information(this, "Info", "Špatně přidané přihlašovací údaje");



}

Login::~Login(){
   /* Evidence w;



    w.setMinimumSize(400,500);
    w.show();*/
}


