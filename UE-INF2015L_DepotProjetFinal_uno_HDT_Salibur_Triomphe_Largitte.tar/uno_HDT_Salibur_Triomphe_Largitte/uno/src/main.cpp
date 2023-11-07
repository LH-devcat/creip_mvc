#include "Partie.h"
#include "sdlUno.h"

//C'est une version de test, non jouable. Dans joueur.cpp cin>>num est changé en rand() pour aller plus vite. Il faut remettre cin>>num
/*
int main ()
{
    Partie p1;
    p1.bouclePartie();
    return 0;
}
*/

int main ()
{
    //On créée une partie
    Partie p1;
    //On lance le SDL
    sdlBoucle(p1);
    return 0;
}
