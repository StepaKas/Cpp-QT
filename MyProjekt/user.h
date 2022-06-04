#ifndef USER_H
#define USER_H
#pragma once


#include <QString>

class User
{
public:
    User();
    User(QString name ,QString surname ,QString email ,QString password ,QString Ulice ,QString Mesto ,QString PSC ,
         QString C_P ,QString Poznamka ,QString DatumNarozeni ): name(name),surname(surname), email(email),password(password),
    Ulice(Ulice),Mesto(Mesto),PSC(PSC),C_P(C_P),Poznamka(Poznamka),DatumNarozeni(DatumNarozeni)   {};

    QString name;
    QString surname;
    QString email;
    QString password;
    QString Ulice;
    QString Mesto;
    QString PSC;
    QString C_P;
    QString Poznamka;
    QString DatumNarozeni;
    bool isAdmin = false;


    QString info(){
        return "Jméno: " +name + "\nPříjmení: "+ surname+"\nEmail: "+ email+"\nHeslo: "+password
                + "\nUlice: "+Ulice +"\nMesto: " +Mesto + "\nPSC: " + PSC + "\nC_P: "+ C_P + "\nPoznamka: "+ Poznamka + "\nDatumNarozeni: "+DatumNarozeni
                +"\nAdmin: "+ (isAdmin ? "Ano" : "Ne") ;
    }
};

#endif // USER_H
