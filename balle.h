#ifndef BALLE_H
#define BALLE_H
#include "forme.h"
#include "point.h"

class balle {
    int xcentre;
    int ycentre;
    int rayon;
    int angle;
    int couleur;
    bool sticky;
public:
    balle(point,int);
    balle(point,int,int);
    balle(int,int,int,int);
    balle(int,int,int);
    int getxCentre();
    int getyCentre();
    int getRayon();
    void collision();
    void affiche();
    void efface();
    void deplace(int, int, int);
    ~balle();
};

#endif
