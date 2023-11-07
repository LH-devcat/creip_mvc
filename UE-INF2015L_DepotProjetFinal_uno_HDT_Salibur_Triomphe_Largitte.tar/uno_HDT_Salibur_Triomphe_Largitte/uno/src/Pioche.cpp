#include "Pioche.h"
#include<iostream>
#include <vector>
using namespace std;

Pioche::Pioche()
{
    estVide=true;
    cartesDePioche.clear();
}

Pioche::~Pioche()
{
    for (unsigned int i=0;i<cartesDePioche.size();++i)
    {
        delete cartesDePioche[i];
    }
}

void Pioche::copie (const Pioche & autrePioche)
{
        cartesDePioche=autrePioche.cartesDePioche;
        srand ( unsigned ( time(0) ) );
        random_shuffle ( cartesDePioche.begin(), cartesDePioche.end() );
        estVide=false;

}

void Pioche::reset()
{
    vector <Carte *>().swap(cartesDePioche);
    estVide=true;
}

void Pioche::init_pioche()
{
    if (estVide==true)
    {
    Carte * Card;
                                                        //Itération sur les char ne marche pas donc on fait 4 copier coller...

        char couleur='r';                               // on ajoute 1 carte pour 0
            int i=0;
            Card=new Carte(couleur,i);
            cartesDePioche.push_back (Card);
            for (i=1;i<=12;++i)
                {                                       // on ajoute 2 cartes pour 1-12
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                }
         couleur='b';                                   // on ajoute 1 carte pour 0
            i=0;
            Card=new Carte(couleur,i);
            cartesDePioche.push_back (Card);
            for (i=1;i<=12;++i)
                {                                       // on ajoute 2 cartes pour 1-12
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                }
         couleur='j';                                   // on ajoute 1 carte pour 0
            i=0;
            Card=new Carte(couleur,i);
            cartesDePioche.push_back (Card);
            for (i=1;i<=12;++i)
                {                                       // on ajoute 2 cartes pour 1-12
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                }
         couleur='v';                                   // on ajoute 1 carte pour 0
            i=0;
            Card=new Carte(couleur,i);
            cartesDePioche.push_back (Card);
            for (i=1;i<=12;++i)
                {                                       // on ajoute 2 cartes pour 1-12
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                    Card=new Carte(couleur,i);
                    cartesDePioche.push_back(Card);
                }

        for (int j=0;j<4;++j)
        {                                               // on ajoute 4 cartes noires, avec 2 effets
            Card=new Carte('n',13);
            cartesDePioche.push_back(Card);
            Card=new Carte('n',14);
            cartesDePioche.push_back(Card);
        }
    // on ajouté 108 cartes dans l'ordre, on shuffle
    srand ( unsigned ( time(0) ) );
    random_shuffle ( cartesDePioche.begin(), cartesDePioche.end() );
    estVide=false;
    }

}


//il faut faire le test estVide avant l'appel
Carte * Pioche::retirerCarte()
{
            Carte * c1 = cartesDePioche.back();
            cartesDePioche.pop_back();
            if (cartesDePioche.size()<=0)
            {
                estVide=true;
            }

            return c1;
}

void Pioche::ajouterCarte(Carte * carteAAjouter){
    cartesDePioche.push_back(carteAAjouter);
}

int Pioche::nbPioche()
{
    return cartesDePioche.size();
}

// Attention: on a des new donc quand on pioche des cartes il faut bien delete
