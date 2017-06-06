#ifndef BALLE_H
#define BALLE_H
#include "forme.h"
#include "point.h"
#include "murbrique.h"
class balle : public forme{
    point tablPoint[5];
    int rayon;
    double angle;
    int couleur;
    bool sticky;
public:
/**********************************************CONSTRUCTEURS*********************************************/
    balle(point,int);
    balle(point,int,int);
    balle(int,int,int,int);
    balle(int,int,int);
/*******************************************GETTERS AND SETTERS*******************************************/
    point getPointCentre();
    point getPointNord();
    point getPointSud();
    point getPointEst();
    point getPointOuest();
    int getRayon();
    void setPointCentre(point);
    void setPointNord(point);
    void setPointSud(point);
    void setPointEst(point);
    void setPointOuest(point);
    void setRayon(int);
/*******************************************AUTRES METHODES***********************************************/
    void collision(murBrique*);
    void collision(raquette);
    void collision();
    void affiche();
    void efface();
    void majPoints();
    void deplace(int);
    void bounceNord();
    void bounceSud();
    void bounceOuest();
    void bounceEst();
/**********************************************DESTRUCTEUR*********************************************/
    ~balle();
};

#endif
