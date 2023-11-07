#ifndef JOUEUR_H
#define JOUEUR_H
#include "Carte.h"
#include "Pioche.h"
#include <vector>       // std::vector
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand




class Joueur
{
    public:
        bool won;
        Joueur();
        /** @brief Quand un joueur commence il pioche 7 cartes. Il faut spécifier où il les pioche. Donc joueur initialisé après la pioche principale. */
        void init_joueur(Pioche & p1);
        /**
        @brief Lancé au début pour piocher 7 cartes. Ensuite lancé uniquement si peutJouer() était faux. De plus le tour se finit direct.
         */
        void piocheUneCarte(Pioche & p1);
        ~Joueur();
        /**
        @brief Teste si une carte est valable. Bool décrit si on fait un test au début du tour (on peut jouer une 3 rouge sur une 4 rouge) ou dans le tour (après un 3, on doit poser un 3 si on rejoue).
        @param bool tourCommencé: Si faux, on fait des tests complexes pour jouer une carte dans des conditions normales. Si vrai, tests sur valeurs pour poser une autre carte de même valeur.
        */
        bool peutJouer(Carte * carteAComparer, Carte * current,bool tourCommence);
        /**
        @brief Teste si le joueur peut jouer une carte (il en a forcément une ou plus). Si ca renvoie 0 alors jeu appelle jouerUneCarte().
        @details Fonctionnement: on itère sur la main du joueur avec peutJouer.
        @param carteAComparer: La carte du jeu active, il faut comparer la main à cette carte pour voire si on a une carte valide.
        */
        bool peutJouerTour(Carte * carteAComparer, bool tourCommence);
        /**
        @brief Lancé uniquement si peutJouer() était vrai donc on aura jamais de Carte attendue mais impossible à trouver.
        Attention cette fonction ne joue pas la carte, elle l'envoie à Jeu et l'enlève de la main du joueur.
        On itère sur la main du joueur et affiche ses cartes au joueur. Il en choisit une: si elle est valide fin, sinon recommence jusqu'à choix valide.
         */
        Carte * jouerUneCarte(Carte * carteAComparer);
        /**
        @brief Utilisée uniquement pour des tests où on veut regarder sans rien changer."
        */
        void afficherMain();
        /**
        @brief Un joueur peut joueur plusieurs cartes en 1 tour si elles ont la même valeur
        */
        //bool joueurPeutEncoreJouer(Carte * carteChoisie);
        /**
        @brief Si il a plusieurs fois la même carte (en valeur) ils les joue toutes
        */
        //Carte * joueurRejoue(Carte * carteChoisie);
        /**
        @brief Pour dire uno, si il reste 2 cartes et le joueur va jouer, il dit uno. Donc on a besoin de voir si il lui reste 2 cartes.
        */
        int nbCartes();
        /**
        @brief Il faut que le module SDL voie le contenu de la main du jouer
        */
        const vector<Carte *> getMainJoueur(void) const;
        /**
        @brief Pour enlever une carte de la main quand elle est choisie et valide
        */
        void retirerCarte (int pos);
    private:
        /**
        @brief La main du joueur, c'est un vecteur.
        */
        vector<Carte *> mainJoueur;

};

#endif // JOUEUR_H
