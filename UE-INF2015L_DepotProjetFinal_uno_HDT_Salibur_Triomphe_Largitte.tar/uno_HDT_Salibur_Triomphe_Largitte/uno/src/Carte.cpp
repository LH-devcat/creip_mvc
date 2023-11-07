#include "Carte.h"
#include <iostream>
#include <string>
using namespace std;


/** \file Carte.cpp
	* Ici on définit les cartes utilisées par tous les autres modules.
*/

Carte::Carte()
{
    couleur='n';
    valeur=0;
    active=true;

}

Carte::Carte(char c, int v)
{
    if ((c=='r' || c=='b' || c=='j' || c=='v'|| c=='n')&&(v>=0 && v<=14))
    {
       couleur=c;
       valeur=v;
       active=true;

    }
    else
    {
        cout<<"Une carte n'est pas valide: "<<c<<" "<<v<<endl;
    }

}

Carte::~Carte()
{
    //  cout<<"La carte a été supprimée"<<endl;
}


const char Carte::getCouleur(void) const
{
    return couleur;
}

const int Carte::getValeur(void) const
{
    return valeur;
}
const bool Carte::getActive(void) const
{
    return active;
}

void Carte::setCouleur(char c)
{
    if ((c=='r') || (c=='b') || (c=='j') || (c=='v') || (c=='n'))
    {
        couleur=c;
    }
}
void Carte::setValeur(int v)
{
    if (v>=0 && v<=14)
    {
        valeur=v;
    }
}
void Carte::setActive(bool b)
{
    active=b;
}
