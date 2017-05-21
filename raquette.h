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
    raquette(); //cr�ation par d�faut
    raquette(point, point); //cr�ation via deux points
    raquette(point, int, int, int); //cr�ation via un point, une longueur, une largeur et une couleur.
    raquette(point, point, int); //cr�ation via deux points et une couleur
    raquette(int,int,int,int); //cr�ation � partir de quatre valeurs
    raquette(int,int,int,int,int); //cr�ation � partir de quatre valeurs et une couleur
    virtual void affiche();
    void deplace(int,int); //d�placement en rentrant le nouveau centre de la raquette ( pour suivre la souris )
    void deplace(int); //d�placement en translation simple sur l'axe X
    void efface(); //efface une brique de l'�cran
    bool verifx(int,int); //verifie si x est dans une position extreme ou pas
    ~raquette();
};

#endif // RAQUETTE_H_INCLUDED
