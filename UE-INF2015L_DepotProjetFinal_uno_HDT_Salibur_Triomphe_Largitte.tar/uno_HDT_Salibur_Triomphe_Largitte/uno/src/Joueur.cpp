#include "Joueur.h"
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
//utilisés pour sleep pour des tests




using namespace std;
Joueur::Joueur()
{
    won=false;
}

void Joueur::init_joueur(Pioche & p1)
{
    Carte * cardInit;
    for (int i=0;i<7;++i)
    {
        cardInit=p1.retirerCarte();
        mainJoueur.push_back(cardInit);
    }
}

void Joueur::piocheUneCarte(Pioche & p1)
{
    Carte * c1=p1.retirerCarte();
    mainJoueur.push_back(c1);
}

Joueur::~Joueur()
{
    for (unsigned int i=0;i<mainJoueur.size();++i)
    {
        delete mainJoueur[i];
    }
}



bool Joueur::peutJouer(Carte * carteAComparer, Carte * current, bool tourCommence) {
    char couleurAComparer=carteAComparer->getCouleur();
    int valeurAComparer=carteAComparer->getValeur();
    bool activeAComparer=carteAComparer->getActive();
    char couleurCurrent=current->getCouleur();
    int valeurCurrent=current->getValeur();
    if (!tourCommence)       //quand appelée au début d'un tour, on entre dans les tests complexes
    {

    if ((valeurAComparer==12) || (valeurAComparer==14)) // D'abord si on est en +2 ou +4: il faut une +2 ou +4.
    {

        if (activeAComparer)
        {
            if (valeurAComparer==valeurCurrent) {return true;}

            if (valeurCurrent==13) {return true;}
        }
        else if (!activeAComparer)
        {
            if (couleurAComparer==couleurCurrent)
            {

               return true;
            }
            if (valeurAComparer==valeurCurrent)
            {
                return true;
            }
            if (valeurCurrent==13 || valeurCurrent==14)
            {
                return true;
            }

        }
    }
    if (valeurAComparer==13)
    {
        if (valeurCurrent==13)
        {
            return true;
        }
        if (couleurAComparer==couleurCurrent)
        {
            return true;
        }
    }

    if (valeurAComparer==10)
    {
        if ((activeAComparer) && (valeurCurrent==10)) {return true;}
        if (valeurAComparer==13) {return true;}
        else if (!activeAComparer)
        {
            if (couleurAComparer==couleurCurrent) {return true;}
            if (valeurCurrent==10) {return true;}
        }

    }
    if ((valeurAComparer>=0 && valeurAComparer<=9) || valeurAComparer==11)
    {
        if (valeurCurrent==14 || valeurCurrent==13) {return true;}
        if ((valeurCurrent==12) && (couleurAComparer==couleurCurrent)) {return true;}
        if ((valeurAComparer==valeurCurrent) || (couleurAComparer==couleurCurrent)) {return true;}
    }
    } // fin if (tourCommence)

    else if (tourCommence) //quand appelé dans un tour commencé, test sur valeurs égales pour rejouer
    {
        return (valeurCurrent==valeurAComparer);
    }
    return false;
}

bool Joueur::peutJouerTour(Carte * carteAComparer,bool tourCommence) {
    for (unsigned int i=0;i<mainJoueur.size();++i)
        {
            if (peutJouer(carteAComparer,mainJoueur[i],tourCommence))
            {
                return true;
            }
        }
    return false;
}


Carte * Joueur::jouerUneCarte(Carte * carteAComparer)
{
    int num;
    Carte * current;
    cout<<"La carte active est: Valeur : "<<carteAComparer->getValeur()<<" Couleur : "<<carteAComparer->getCouleur()<<endl;
    cout<<"Les cartes de la main sont : "<<endl;
    for (unsigned int i=0;i<mainJoueur.size();++i)
        {
            current=mainJoueur[i];
            cout<<i<<" Valeur : "<<current->getValeur()<<" Couleur : "<<current->getCouleur()<<endl;
        }
    do
    {
        cout<<"Choisir une carte : "<<endl;
        cin>>num;
        //num=rand()%mainJoueur.size();  //pour faire des tests plus vite
    } while (!(peutJouer(carteAComparer,mainJoueur[num],false)));
    current=mainJoueur[num];
    mainJoueur.erase(mainJoueur.begin()+num);
    //std::this_thread::sleep_for (std::chrono::seconds(1));
    return current;
}



void Joueur::afficherMain() //sert à faire des tests/debug
{
    Carte * Card=NULL;
    for (unsigned int i=0;i<mainJoueur.size();++i){
        Card=mainJoueur[i];
        cout<<i<<" Couleur ? "<<Card->getCouleur()<<"       Valeur ? "<<Card->getValeur()<<endl;
    }
}

int Joueur::nbCartes()
{
    return mainJoueur.size();
}


const vector<Carte *> Joueur::getMainJoueur(void) const
{
    return mainJoueur;
}

void Joueur::retirerCarte(int pos)
{
    mainJoueur.erase(mainJoueur.begin()+pos);
}
