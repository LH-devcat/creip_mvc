#ifndef SDLUNO
#define SDLUNO


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Partie.h"
#include <stdio.h>

/**
@brief Donne une texture à partir d'un filename
*/
SDL_Texture * loadImage(const char * , SDL_Texture * , SDL_Renderer * );
/**
@brief On charge toutes les textures pour ne pas le refaire à chaque tour, on leur associe un ID, on utilise cet ID à chaque tour
*/
void init_cartes_SDL(SDL_Texture * listeTextures[]);
/**
@brief Donne l'ID de la texture d'une carte
*/
int getTexID (const Carte *);
/**
@brief C'est juste un rendercopy avec gestion des erreurs
*/
void displaySDL(SDL_Renderer * , SDL_Texture * , SDL_Rect *, SDL_Rect *);
/**
@brief Affiche la main du joueur
*/
void afficherMain(int *,int, SDL_Renderer *, SDL_Texture **);
/**
@brief A partir des coordonées XY d'un clic, on cherche quelle carte a été cliquée.
@return La position de la carte cliquée dans le vecteur mainJoueur
*/
int interpreterClic(int x, int y);
/**
@brief L'équivalent de joueurDoitJouer mais attend des entrées SLD et pas dans la console
*/
void joueurDoitJouerSDL(Joueur * joueurActuel, bool tourCommence);



void sdlBoucle (Partie );

#endif // SDLUNO
