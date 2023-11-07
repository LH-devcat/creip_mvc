#ifndef PARTIE_H
#define PARTIE_H
#include "Joueur.h"


class Partie
{
    public:
        Pioche piocheActive;
        Pioche cartesUtilisees;
//        Joueur * joueurCourant;
//        Joueur * joueurSuivant;
        Carte * carteActive;
        vector <Joueur *> tableauJoueurs;
        bool sens;
        /**
        @brief Si j1 joue +2, j2 joue +2, j3 voit une +2 mais doit piocher 4 cartes. Il faut garder en mémoire le nb de cartes à piocher, la dernière carte n'apporte pas toutes les infos.
        */
        int nbcartes;



        Partie();
        ~Partie();
        /**
        @brief Si la pioche est vide on swap avec les cartes utilisées.
        */
        void echangerPioches();

        /**
        @brief C'est la fonction qui fait tout, en mode txt
        */
        void joueurDoitJouer(Joueur * joueurActuel, bool tourCommence);
        /**
        @brief Si le joueur a joué une carte, cette fonction gère ses effets
        */
        bool effetsCarte (Joueur * joueurActuel, bool tourCommence, Carte * carteChoisie, char cc);


        void bouclePartie();




};

#endif // PARTIE_H
