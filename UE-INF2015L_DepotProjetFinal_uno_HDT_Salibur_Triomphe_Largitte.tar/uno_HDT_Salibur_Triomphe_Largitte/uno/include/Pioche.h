#ifndef PIOCHE_H
#define PIOCHE_H
#include "Carte.h"
#include <vector>       // std::vector
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

class Pioche
{
    private:
        /** @brief On utilise un vecteur: le nb de cartes dans la pioche change, des méthodes existent déjà */
        vector<Carte *> cartesDePioche;

    public:
        /**
        @brief Appellée par jeu.cpp juste après un constructeur: alloue les 108 cartes et mélange avec random_shuffle. On ne met pas ca dans le constructeur car on va créer
        une pioche vide des cartes déjà jouées.
        */
        void init_pioche();
        /** @brief La pioche est vide */
        Pioche();
        /** @brief Sert à rien pour l'instant. Supprimer les cartes à la fin d'une partie ???*/
        ~Pioche();
        /** @brief Quand la pioche active est vide, on copie le contenu de la "pioche" cartes déjà jouées dans la pioche active et shuffle (et on vide la pioche cartes jouées) */
        void copie(const Pioche &);
        /** @brief Sert à faire des vérifications, par ex. on n'initialise pas une pioche non vide */
        bool estVide;
        /**
        Après avoir mis les cartes utilisées dans la pioche active (elle était vide), on doit remettre les cartes utilisées à 0.
        */
        void reset();

        /** @brief Quand un joueur pioche 1 carte, supprime la première carte  avec pop_back() et la return. Vérifie si le vecteur est vide, si oui bool estVide=true */
        Carte * retirerCarte();
        /** @brief Les cartes piochées sont mises dans une "pioche", qui deviendra active si la première est vide*/
        void ajouterCarte(Carte *);
        /** @brief Utilisée pour les tests */
        int nbPioche();
};

#endif // PIOCHE_H
