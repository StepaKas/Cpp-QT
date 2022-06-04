#pragma once
#ifndef MAIN_CPP
#define MAIN_CPP
#include "login.h"

#include "prihlasovani.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{

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
    smeny s4 (6 , "30/6/2020","Nejaka informace PH");

    QList<User> users ;
    QList<smeny> Smeny;
    users = {u1, u2 ,u3 ,u4, u5,u6,u7,u8,u9,u10,u11,u12};
    Smeny = {s1, s2, s3, s4};
    Smeny[0].AddUser(users[0]);
    Smeny[0].AddUser(users[1]);
    Smeny[0].AddUser(users[2]);
    Smeny[0].AddUser(users[3]);
    Smeny[0].AddUser(users[4]);

    Smeny[1].AddUser(users[11]);
    Smeny[1].AddUser(users[10]);

    Smeny[2].AddUser(users[6]);
    Smeny[2].AddUser(users[8]);
    Smeny[2].AddUser(users[7]);

    Smeny[3].AddUser(users[7]);
    Smeny[3].AddUser(users[7]);
    Smeny[3].AddUser(users[7]);
    Smeny[3].AddUser(users[7]);


        QApplication a(argc, argv);
    Login   l;
    l.Smeny.clear();
    l.users.clear();
    for (int i = 0; i < users.size(); i++){
        l.users.push_back(users[i]);
    }
    for (int i = 0; i < Smeny.size(); i++){
        l.Smeny.push_back(Smeny[i]);
    }


    l.setMinimumSize(100,100);
    l.show();

/*
    prihlasovani p(users, Smeny);
    p.setMinimumSize(300,400);
    p.show();
*/

    return a.exec();
}
#endif
