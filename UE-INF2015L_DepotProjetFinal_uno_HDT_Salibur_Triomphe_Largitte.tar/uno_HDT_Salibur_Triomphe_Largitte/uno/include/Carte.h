#ifndef CARTE_H
#define CARTE_H
#include <string>
using namespace std;

/** \file Carte.h
	* Ici on définit les cartes utilisées par les autres modules
*/

class Carte
{
    private:
        /** @brief La couleur peut être RGBY ou N si carte toujours valide (draw4 et change) */
        char couleur;
        /** @brief La valeur peut être
        0-9=normal
        10=skip
        11=sens inverse
        12=+2
        13=change couleur
        14=+4 et change couleur
        */
        int valeur;
        bool active;


    public:
        Carte();
        /**
        @brief Constructeur par copie.
        @param Les paramètres sont dans l'ordre couleur, valeur
        */
        Carte(char,int);
        ~Carte();

        const char getCouleur() const;
        const int getValeur() const;
        const bool getActive() const;
        void setCouleur(char);
        void setValeur(int);
        void setActive(bool);



};

#endif // CARTE_H
