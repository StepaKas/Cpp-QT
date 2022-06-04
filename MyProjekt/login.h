#ifndef LOGIN_H
#define LOGIN_H
#pragma once
#include <QMainWindow>
#include "evidence.h"
#include <QLabel>
#include <QApplication>
#include "globals.h"
#include "user.h"
#include "smeny.h"
#include <QMenuBar>

class Login : public QMainWindow
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();


    QLineEdit* email_edit;
    QLineEdit* password_edit;
    QPushButton* submit_but;
    QFormLayout* form_l ;

    QVBoxLayout* layout;
    QFrame* main_frame;

    QFrame * fButtons  ;
    QHBoxLayout * but_l ;

    QFrame * fMainInfo ;


    QList<User> users ;
    QList<smeny> Smeny;

private slots:

    void log_in();
private:

};

#endif // LOGIN_H
