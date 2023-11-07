#include "Partie.h"





Partie::Partie()
{
    sens=true;
    piocheActive.init_pioche(); //piocheActive est créée mais vide; on ajoute 108 cartes.
    cartesUtilisees.reset(); //pour être sur que c'est vide.
    carteActive=piocheActive.retirerCarte(); // première carte=celle sur laquelle on va jouer
    carteActive->setActive(false); //si la 1ère était spéciale on la désactive.
    if (carteActive->getCouleur()=='n') {carteActive->setCouleur('r');}
    nbcartes=0; //si un joueur ne peut pas jouer il doit piocher un certain nb de cartes, suivant les cartes précédentes jouées 1,2,4,6,8,etc.
    Joueur * ptrJ=NULL;
    for (int i=0;i<4;++i)
    {
        ptrJ=new Joueur;
        tableauJoueurs.push_back(ptrJ);
        tableauJoueurs[i]->init_joueur(piocheActive);
    }
//    joueurCourant=tableauJoueurs[0];
//    joueurSuivant=tableauJoueurs[1];

}

Partie::~Partie()
{
    for (unsigned int i=0;i<tableauJoueurs.size();++i)
    {
        delete tableauJoueurs[i];
    }
}

//ancienne version
void Partie::echangerPioches()
{
    piocheActive.copie(cartesUtilisees);
    cartesUtilisees.reset();
}


//tests à faire si piocheActive est vide->swap les 2 pioches.

void Partie::joueurDoitJouer(Joueur * joueurActuel, bool tourCommence)
{
    Carte * carteChoisie=NULL;
    char cc;
    if (joueurActuel->peutJouerTour(carteActive,tourCommence))
    {
        carteChoisie = joueurActuel->jouerUneCarte(carteActive);

        if (carteActive->getValeur()==13 || carteActive->getValeur()==14)
        {
            carteActive->setCouleur('n');

        }
        cartesUtilisees.ajouterCarte(carteActive); //on jette la carte du tour précédent
        cartesUtilisees.estVide=false;
        carteActive=carteChoisie; //on remplace la carte du jeu par celle jouée.
        int v=carteChoisie->getValeur();

        if (v==11) {sens=!sens;}
        if (v==12)
        {
            nbcartes+=2;
        }
        if (v==14)
        {
            nbcartes+=4;
            cout<<"Vous avez joué une +4. Choisir une couleur ? "<<endl;
            cin>>cc;

        }
        if (v==13)
        {
            cout<<"Vous avez joué un changement de couleur. Choisir une couleur ? "<<endl;
            cin>>cc;

        }
        if ((v==14) || (v==13))
        {
            carteActive->setCouleur(cc);
        }

    //tous les trucs sur 1ère carte

        if (joueurActuel->peutJouerTour(carteChoisie,true))
        {
            joueurDoitJouer(joueurActuel,true);
        }
        if (joueurActuel->nbCartes()==1)
        {
            cout<<"UNO"<<endl;
        }
        cout<<"le joueur a joué"<<endl;


    }
    else
    {
        if (nbcartes==0)
        {
            nbcartes=1;
        }
        for (int i=0;i<nbcartes;++i)
        {
            if (piocheActive.estVide)
            {
                if (!cartesUtilisees.estVide)
                {
                    echangerPioches();

                }
                else
                {
                    cout<<"Impossible d'échanger, les 2 sont vides"<<endl;
                }


            }
            else
            {
                joueurActuel->piocheUneCarte(piocheActive);
            }


        }
        carteActive->setActive(false); //si il y avait un effet +2 ou +4 on le désactive car il a pioché.
        nbcartes=0;
        cout<<"il a pioché"<<endl;
    }

}

bool Partie::effetsCarte (Joueur * joueurActuel, bool tourCommence, Carte * carteChoisie, char cc='r')
{
        if (carteActive->getValeur()==13 || carteActive->getValeur()==14)
        {
            carteActive->setCouleur('n');

        }
        cartesUtilisees.ajouterCarte(carteActive); //on jette la carte du tour précédent
        cartesUtilisees.estVide=false;
        carteActive=carteChoisie; //on remplace la carte du jeu par celle jouée.
        int v=carteChoisie->getValeur();

        if (v==11) {sens=!sens;}
        if (v==12)
        {
            nbcartes+=2;
        }
        if (v==14)
        {
            nbcartes+=4;
            cout<<"Vous avez joué une +4. Choisir une couleur ? "<<endl;
            cin>>cc;
            carteActive->setCouleur(cc);

        }
        if (v==13)
        {
            cout<<"Vous avez joué un changement de couleur. Choisir une couleur ? "<<endl;
            cin>>cc;
            carteActive->setCouleur(cc);

        }
    //tous les trucs sur 1ère carte
        if (joueurActuel->nbCartes()==1)
        {
            cout<<"UNO"<<endl;
        }
        cout<<"le joueur a joué"<<endl;
        return (joueurActuel->peutJouerTour(carteChoisie,true));


}


void Partie::bouclePartie()
{
    bool quit=false;
    int compteur=0;
    while (!quit)
    {

        if (!tableauJoueurs[compteur]->won)
        {
            cout<<"C'est le tour du joueur "<<compteur<<" et il a gagné ? "<<tableauJoueurs[compteur]->won<<endl;
            cout<<"     il lui reste "<<tableauJoueurs[compteur]->nbCartes()<<endl;
            cout<<"     il reste "<<piocheActive.nbPioche()<<" dans la pioche active et elle est vide ??"<<piocheActive.estVide<<endl;
            cout<<"     il reste "<<cartesUtilisees.nbPioche()<<" dans la pioche inactive"<<endl;
            joueurDoitJouer(tableauJoueurs[compteur],false);
            if (tableauJoueurs[compteur]->nbCartes()==0)
            {
                tableauJoueurs[compteur]->won=true;
                cout<<"Le joueur "<<compteur<<" a gagné"<<endl;
                quit=true;
            }
        }
        else //si un joueur a gagné, condition ?
        {
            cout<<"Le joueur "<<compteur<<" a gagné"<<endl;
            quit=true;
        }
        // soit il a joué, soit la carte n'a pas changé. donc : carteactive, sens, joueursuivant
        if (sens)
        {
            compteur=(compteur+1)%tableauJoueurs.size();
        }
        if (!sens)
        {
            compteur=(compteur-1)%tableauJoueurs.size();
        }


    }
}



