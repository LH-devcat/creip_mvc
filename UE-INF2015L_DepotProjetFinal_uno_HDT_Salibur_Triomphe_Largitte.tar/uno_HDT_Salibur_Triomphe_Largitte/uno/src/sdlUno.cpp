#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "sdlUno.h"

const int TAILLE_CARTES = 64;


SDL_Texture * loadImage(const char * filename, SDL_Renderer * renderer)
{
    SDL_Surface * surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;


    SDL_Texture * tex = SDL_CreateTextureFromSurface(renderer, surface);
    if (tex == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
    SDL_FreeSurface(surface);
    return tex;
}

void displaySDL(SDL_Renderer * renderer, SDL_Texture * tex, SDL_Rect* srcrect=NULL, SDL_Rect * dstrect=NULL)
{
    if (SDL_RenderCopy(renderer,tex,srcrect,dstrect) != 0)
    {
        cout<<"erreur copy"<<endl;
    }
}


int getTexID(const Carte * carteAffichee)
{
    char c=carteAffichee->getCouleur();
    int v=carteAffichee->getValeur();
    if (v==14) {return 53;}
    else if (v==13) {return 52;}
    else
    {
        switch (c)
        {
        case 'b':
            return v;
            break;
        case 'v':
            return 13+v;
            break;
        case 'r':
            return 26+v;
            break;
        case 'j':
            return 39+v;
            break;
        default:
            cout<<endl<<c<<endl<<v<<endl;
            return 54;
            break;
        }
    }
}



void init_cartes_SDL(SDL_Texture * listeTextures[], SDL_Renderer * renderer)
{
    for (int i=0;i<=12;++i)
    {
            listeTextures[i]=loadImage(("data/cards/blue_"+std::to_string(i)+".png").c_str(),renderer);
    }
    for (int i=13;i<=25;++i)
    {
            listeTextures[i]=loadImage(("data/cards/green_"+std::to_string(i-13)+".png").c_str(),renderer);
    }
    for (int i=26;i<=38;++i)
    {
            listeTextures[i]=loadImage(("data/cards/red_"+std::to_string(i-26)+".png").c_str(),renderer);
    }
    for (int i=39;i<=51;++i)
    {
            listeTextures[i]=loadImage(("data/cards/yellow_"+std::to_string(i-39)+".png").c_str(),renderer);
    }
    listeTextures[52]=loadImage(("data/cards/wild_color_changer.png"),renderer);
    listeTextures[53]=loadImage(("data/cards/wild_pick_four.png"),renderer);
    listeTextures[54]=loadImage(("data/cards/card_back.png"),renderer);

}

void afficherMain(int * tableau, int taille, SDL_Renderer * renderer, SDL_Texture * listeTexture[])
{
    int ligne=600-TAILLE_CARTES;
    SDL_Rect pos;
    pos.h=TAILLE_CARTES;
    pos.w=TAILLE_CARTES/1.4;
    for (int i=0;i<taille;++i)
    {
        pos.y=ligne;
        pos.x=(i%12)*(TAILLE_CARTES/1.4);
        displaySDL(renderer,listeTexture[tableau[i]],NULL,&pos);
        if (i%12==0 && i!=0) {ligne-=TAILLE_CARTES;} //si on a fini la ligne on monte
    }
}

int interpreterClic(int x, int y)
{
    float TAILLEW=TAILLE_CARTES/1.4;
    int posX=int(x/TAILLEW);
    int posY=(600-y)/TAILLE_CARTES;
    return (posX+12*posY);
}




void sdlBoucle (Partie p1)
{
    bool quit=false;
    SDL_Event events;
    int Xclic=0;
    int Yclic=0;

    // On init SDL ici
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }
    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
        if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }


    // On créé la fenêtre vide
    SDL_Window * window = SDL_CreateWindow("UNO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window == nullptr)  {std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;}
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr){SDL_DestroyWindow(window); std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;}


    // On charge une image de fond
    SDL_Texture * tex = NULL;
    tex = loadImage("./data/woodtexture.png", renderer);
    if (tex==NULL) {cout<<"null texture"<<SDL_GetError()<<endl;}


    //On charge les cartes
    SDL_Texture * listeTextures[55];
    init_cartes_SDL(listeTextures, renderer);

    SDL_RenderClear(renderer);

    //Afficher la texure de fond et la pioche.
    displaySDL(renderer,tex);
    SDL_Rect posRect;
    posRect.h=TAILLE_CARTES;
    posRect.w=TAILLE_CARTES/1.4;
    posRect.y=250;
    posRect.x=450;
    displaySDL(renderer,listeTextures[54],NULL,&posRect);

    //Afficher la carte active.
    posRect.y=250;
    posRect.x=350;
    int activeID=getTexID(p1.carteActive);
//    cout<<activeID<<endl;
    displaySDL(renderer,listeTextures[activeID],NULL,&posRect);

    //Le jeu commence avec joueur 0
    int compteur=0;

    //On veut afficher "C'est le tour de.." avec sdl ttf
    TTF_Font* sansText = TTF_OpenFont("data/AbyssinicaSIL-R.ttf", 24);
    if (sansText==NULL) {cout<<"Font introuvable"<<endl;}
    SDL_Color blackText = {10,10,10};
    SDL_Surface* surfaceMessage;
    SDL_Texture* textureMessage;
    SDL_Rect rectMessage;
    rectMessage.y=0;
    rectMessage.x=350;
    rectMessage.h=50;
    rectMessage.w=50;
    string message;
    const char * messageChar;


    SDL_RenderPresent(renderer);

    //Début de la boucle de jeu
    while (!quit)
    {

        SDL_RenderClear(renderer);
        message="C'est le tour du joueur "+compteur;
        messageChar=message.c_str();
        surfaceMessage = TTF_RenderText_Solid(sansText,messageChar, blackText);
        textureMessage  = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        displaySDL(renderer,textureMessage,NULL,&rectMessage);
        //texte non affiché...revoir doc sdl_ttf

        //Afficher la texure de fond et la pioche
        displaySDL(renderer,tex);
        SDL_Rect posRect;
        posRect.h=TAILLE_CARTES;
        posRect.w=TAILLE_CARTES/1.4;
        posRect.y=250;
        posRect.x=450;
        displaySDL(renderer,listeTextures[54],NULL,&posRect);


        //Afficher la carte active. posRect déjà déclaré pour la pioche plus haut.
        posRect.y=250;
        posRect.x=350;
        int activeID=getTexID(p1.carteActive);
        cout<<activeID<<endl;
        displaySDL(renderer,listeTextures[activeID],NULL,&posRect);

        //Copies des mains des joueurs, pour affichage
        vector <Carte *> mainCourante;


        if (!p1.tableauJoueurs[compteur]->won)
        {
            cout<<"C'est le tour du joueur "<<compteur<<" et il a gagné ? "<<p1.tableauJoueurs[compteur]->won<<endl;


            //Afficher la carte active.
            posRect.y=250;
            posRect.x=350;
            activeID=getTexID(p1.carteActive);
            displaySDL(renderer,listeTextures[activeID],NULL,&posRect);
            if (p1.tableauJoueurs[compteur]->nbCartes()==0)
            {
                p1.tableauJoueurs[compteur]->won=true;
                cout<<"Le joueur "<<compteur<<" a gagné"<<endl;
                quit=true;
            }

            //On associe les cartes à leurs textures et on affiche la main
            mainCourante=p1.tableauJoueurs[compteur]->getMainJoueur();
            int tableauID[mainCourante.size()];
            for (unsigned int i=0;i<mainCourante.size();++i) {tableauID[i]=getTexID(mainCourante[i]);}
            afficherMain(tableauID,mainCourante.size(),renderer,listeTextures);

            //On a tout affiché, il va pouvoir jouer
            SDL_RenderPresent(renderer);

            //Si il peut jouer
            Carte * carteChoisie=NULL;
            int carteClic;
            bool tourcommence=false;
            bool continuer=true;

            while (continuer)
            {
                if (p1.tableauJoueurs[compteur]->peutJouerTour(p1.carteActive,tourcommence))
                {

                //On associe les cartes à leurs textures et on affiche la main
                mainCourante=p1.tableauJoueurs[compteur]->getMainJoueur();
                int tableauID[mainCourante.size()];
                for (unsigned int i=0;i<mainCourante.size();++i) {tableauID[i]=getTexID(mainCourante[i]);}
                afficherMain(tableauID,mainCourante.size(),renderer,listeTextures);

                //On a tout affiché, il va pouvoir jouer
                SDL_RenderPresent(renderer);

                    //Ensuite on attend un clic, avec do while
                    do
                    {
                    while (SDL_WaitEvent(&events))
                    {
                        if (events.type == SDL_QUIT) {quit = true;}
                        else if (events.type == SDL_KEYDOWN)
                        {
                            switch (events.key.keysym.scancode)
                            {
                            case SDL_SCANCODE_Q:
                                quit = true;
                                break;
                            default:
                                break;

                            }
                        }
                        else if (events.type==SDL_MOUSEBUTTONDOWN)
                        {
                            Xclic=events.button.x;
                            Yclic=events.button.y;
                            cout<<"Le jouer a clic sur "<<endl<<Xclic<<endl<<Yclic<<endl;
                            break;
                        }
                    }

                    //Maintenant qu'il a joué et qu'on sait où il a clic, on trouve la position avec xy
                    carteClic=interpreterClic(Xclic,Yclic);
                    cout<<"C'est la carte n° "<<carteClic<<endl;
                    } while (!((unsigned int)carteClic<=mainCourante.size())  || !(p1.tableauJoueurs[compteur]->peutJouer(p1.carteActive,mainCourante[carteClic],tourcommence)));
                    carteChoisie=mainCourante[carteClic];
                    p1.tableauJoueurs[compteur]->retirerCarte(carteClic);



                    //Donc on peut jouer cette carte
//                    SDL_RenderPresent(renderer);
                    continuer=p1.effetsCarte(p1.tableauJoueurs[compteur], tourcommence, carteChoisie, 'r');
                    tourcommence=true;

                }//fin du if si il peut jouer

                else
                {
                    if (p1.nbcartes==0)
                    {
                    p1.nbcartes=1;
                    }
                    for (int i=0;i<p1.nbcartes;++i)
                    {
                    if (p1.piocheActive.estVide)
                    {
                        if (!p1.cartesUtilisees.estVide)
                        {
                            p1.echangerPioches();

                        }
                        else
                        {
                            cout<<"Impossible d'échanger, les 2 sont vides"<<endl;
                        }


                    }
                    else
                    {
                        p1.tableauJoueurs[compteur]->piocheUneCarte(p1.piocheActive);
                    }


                }
                p1.carteActive->setActive(false); //si il y avait un effet +2 ou +4 on le désactive car il a pioché.
                p1.nbcartes=0;
                cout<<"il a pioché"<<endl;
                mainCourante=p1.tableauJoueurs[compteur]->getMainJoueur();
                continuer=false;

                }//fin du else




        } //fin du while (continuer)

        } //fin du tour (if !won)






        if (p1.tableauJoueurs[compteur]->nbCartes()==0)   //si un joueur a gagné, condition ?
        {
            cout<<endl<<"Le joueur "<<compteur<<" a gagné"<<endl;
            quit=true;
        }


        // soit il a joué, soit la carte n'a pas changé. donc : carteactive, sens, joueursuivant
        if (p1.sens)
        {
            compteur=(compteur+1)%p1.tableauJoueurs.size();
        }
        if (!p1.sens)
        {
            compteur=(compteur-1)%p1.tableauJoueurs.size();
        }
        mainCourante=p1.tableauJoueurs[compteur]->getMainJoueur();


    }






    cout<<"Quit";
    for (int i=0;i<=54;++i)
    {
        SDL_DestroyTexture(listeTextures[i]);
    }

    SDL_DestroyTexture(tex);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(textureMessage);
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();


}



