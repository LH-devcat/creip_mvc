#include "Carte.h"
#include "Pioche.h"
#include "Joueur.h"
#include "Partie.h"
#include <iostream>
using namespace std;

int main (void)
{
    int i;
    cout<<"1 : carte\n2: pioche\n3: joueur\n le reste à faire"<<endl;
    cin>>i;
switch (i){
    case 1:
    {


    //Tests sur le module Carte

    cout<<"Tests sur le module Carte : On crée une carte, constructeur par défaut donc noire et valeur 0"<<endl;
    Carte * Card=new Carte;
    cout<<"Couleur ? "<<Card->getCouleur()<<endl;
    cout<<"Valeur ? "<<Card->getValeur()<<endl;
    Card->setValeur(5);
    Card->setCouleur('r');
    cout<<"On a changé en rouge, valeur 5 : "<<endl;
    cout<<"Couleur ? "<<Card->getCouleur()<<endl;
    cout<<"Valeur ? "<<Card->getValeur()<<endl;
    cout<<"On créée une Card2 par copie : "<<endl;
    Carte * Card2=new Carte('r',5);
    cout<<"Couleur Card2 ? "<<Card->getCouleur()<<endl;
    cout<<"Valeur Card2 ? "<<Card->getValeur()<<endl;
    delete Card;
    delete Card2;
    break;
    }

    case 2:
    {


    //Tests sur le module Pioche

    Pioche piocheTests;
    Carte * CardP;
    cout<<"Pioche créée. Vide ? "<<piocheTests.estVide<<endl;
    piocheTests.init_pioche();
    cout<<"On initialise la pioche. Vide ? "<<piocheTests.estVide<<endl;
    cout<<"On retire 3 cartes en haut de la pioche. Ce ne sont pas les mêmes ? "<<endl;
    CardP=piocheTests.retirerCarte();
    cout<<"Couleur ? "<<CardP->getCouleur()<<endl;
    cout<<"Valeur ? "<<CardP->getValeur()<<endl;
    CardP=piocheTests.retirerCarte();
    cout<<"Couleur ? "<<CardP->getCouleur()<<endl;
    cout<<"Valeur ? "<<CardP->getValeur()<<endl;
    CardP=piocheTests.retirerCarte();
    cout<<"Couleur ? "<<CardP->getCouleur()<<endl;
    cout<<"Valeur ? "<<CardP->getValeur()<<endl;
    cout<<"Ici on créé une nouvelle carte: rouge 11"<<endl;
    Carte * CardAjoutee=new Carte('r',11);
    cout<<"Puis on l'ajoute à la pioche"<<endl;
    piocheTests.ajouterCarte(CardAjoutee);
    cout<<"Carte en haut de la pioche ?"<<endl;
    CardP=piocheTests.retirerCarte();
    cout<<"Couleur ? "<<CardP->getCouleur()<<endl;
    cout<<"Valeur ? "<<CardP->getValeur()<<endl;

    cout<<"Ensuite on fait les tests sur copies de pioches.\nOn créée une 2nde pioche et copie le contenu de la 1st dedans"<<endl;
    Pioche piocheTests2;
    cout<<"Pioche 2 créée. Vide ? "<<piocheTests2.estVide<<endl;
    piocheTests2.copie(piocheTests);
    cout<<"Copie effectuée. Vide ? "<<piocheTests2.estVide<<endl;
    cout<<"Finalement on teste reset. Reset puis est vide ? "<<endl;
    piocheTests.reset();
    cout<<"Vide après reset ? "<<piocheTests.estVide<<endl;
    delete CardAjoutee;
    break;
    }

    //Tests sur Joueur
    case 3:
    {
    cout<<"On créé une pioche (où le joueur pioche) puis un joueur, et on initialise avec 7 cartes piochées. Pas les mêmes ? "<<endl;
    Pioche piocheJ;
    piocheJ.init_pioche();
    Joueur j1;
    j1.init_joueur(piocheJ);
    j1.afficherMain();
    cout<<"On lui fait piocher une carte (la fonction utilisée si il ne peut pas jouer), puis on regarde si elle est bien présente."<<endl;
    j1.piocheUneCarte(piocheJ);
    j1.afficherMain();
    Carte * carteJeu=new Carte('r',14);
    Carte * carteTest=new Carte('r',5);
    Carte * carteTest2=new Carte('v',1);
    Carte * carteTest3=new Carte('j',4);
    Carte * carteTest4=new Carte('b',14);
    cout<<"On test la fonction peutJouer: la carte rouge 5 peut elle être jouée sur rouge 1 ? "<<j1.peutJouer(carteJeu,carteTest,false)<<endl;
    cout<<"On test la fonction peutJouer: la carte vert 1 peut elle être jouée sur rouge 1 ? "<<j1.peutJouer(carteJeu,carteTest2,false)<<endl;
    cout<<"On test la fonction peutJouer: la carte jaune 4 peut elle être jouée sur rouge 1 ? "<<j1.peutJouer(carteJeu,carteTest3,false)<<endl;
    cout<<"On test la fonction peutJouer: une carte noire +4 (valeur 14 dans le code) peut elle être jouée sur rouge 1 ? "<<j1.peutJouer(carteJeu,carteTest4,false)<<endl;
    char a,b;
    int c,d;

    cout<<"Entrez couleur valeur d'une carte à comparer et d'une carte à jouer"<<endl;
    cin>>a>>c>>b>>d;
    carteJeu->setCouleur(a);
    carteJeu->setValeur(c);
    carteTest->setCouleur(b);
    carteTest->setValeur(d);
    cout<<"On teste si la 2nde peut être jouée sur la 1ère."<<endl<<j1.peutJouer(carteJeu,carteTest,false)<<endl;

    delete carteJeu;
    delete carteTest;
    delete carteTest2;
    delete carteTest3;
    delete carteTest4;
    break;
    }

    return 0;
    //cout<<"On suppose que le joueur doit jouer sur la carte couleur rouge, valeur 1. Il peut jouer ? "<<j1.peutJouer()
}
}
