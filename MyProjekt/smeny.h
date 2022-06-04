#ifndef SMENY_H
#define SMENY_H
#pragma once
#include <QString>
#include <QList>
#include "user.h"

class smeny
{
public:
    smeny();
    smeny(int kapacita,QString datum, QString popisek) : kapacita(kapacita), datum(datum), popisek(popisek){};
    int kapacita;
    int soucastny_pocet  =0;
    QString datum;
    QString popisek;

    QList<User> users;
    bool AddUser(User u){
        //check if already there
        for (int i = 0; i < users.size(); i++){
            if (u.email == users[i].email){
                return false;
            }
        }
        if (soucastny_pocet < kapacita){
            users.push_back(u);
            soucastny_pocet++;
            return true;
        }
        return false;
    }
    bool RemoveUser(User u){
        for (int i =  0 ; i < users.size(); i++){
            if(users[i].email == u.email){
                users.removeAt(i);

                soucastny_pocet--;
                return true;
            }

        }
        return false;
    }
    QString info (){
        QString result = "Přihlášení pracovníci:\n";
        for (int i = 0; i < users.size(); i++){
            result += users[i].name + " " + users[i].surname + "\n";
        }
        result += "Soucastny_pocet: "+ QString::number(soucastny_pocet)+" "
"\nKapacita: "+ QString::number(kapacita) + "\nDatum: " +datum + "\nPopisek: " +popisek ;

        return result;
    }
};

#endif // SMENY_H
