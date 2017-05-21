#ifndef RAQUETTE_H_INCLUDED
#define RAQUETTE_H_INCLUDED
#include "point.h"
#include "rectangle.h"
#include "forme.h"

using namespace std;
//Classe Raquette
class raquette : public rectangle{
protected :
    int m_longueur;
public :
    raquette(); //création par défaut
    raquette(point, point); //création via deux points
    raquette(point, int, int, int); //création via un point, une longueur, une largeur et une couleur.
    raquette(point, point, int); //création via deux points et une couleur
    raquette(int,int,int,int); //création à partir de quatre valeurs
    raquette(int,int,int,int,int); //création à partir de quatre valeurs et une couleur
    virtual void affiche();
    void deplace(int,int); //déplacement en rentrant le nouveau centre de la raquette ( pour suivre la souris )
    void deplace(int); //déplacement en translation simple sur l'axe X
    void efface(); //efface une brique de l'écran
    bool verifx(int,int); //verifie si x est dans une position extreme ou pas
    ~raquette();
};

#endif // RAQUETTE_H_INCLUDED
