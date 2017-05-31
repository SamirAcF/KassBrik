#ifndef BALLE_C
#define BALLE_C
#include <iostream>
#include <allegro.h>
#include "balle.h"
extern BITMAP* bmap;

balle::balle(point point, int ray){
    tablPoint[0] = point;
    rayon= ray;
    couleur = makecol(128,128,128);
    }
balle::balle(point point, int ray, int color){
    tablPoint[0] = point;
    rayon = ray;
    couleur= color;
    }
balle::~balle(){}


/*************************************GETTERS AND SETTERS********************************************************/
    point balle::getPointCentre(){
        return(tablPoint[0]);
    }

    point balle::getPointNord(){
        return(tablPoint[1]);
    }

    point balle::getPointSud(){
        return(tablPoint[2]);
    }

    point balle::getPointEst(){
        return(tablPoint[3]);
    }

    point balle::getPointOuest(){
        return(tablPoint[4]);
    }

    int balle::getRayon(){
        return(rayon);
    }

    void balle::setPointCentre(point pnt){
        tablPoint[0] = pnt;
    }

    void balle::setPointNord(point pnt){
        tablPoint[1] = pnt;
    }

    void balle::setPointSud(point pnt){
        tablPoint[2] = pnt;
    }

    void balle::setPointEst(point pnt){
        tablPoint[3] = pnt;
    }

    void balle::setPointOuest(point pnt){
        tablPoint[4] = pnt;
    }

    void balle::setRayon(int ray){
        rayon = ray;
    }

/************************************METHODES GENERALES**********************************************************/
void balle::collision()
{

}
void balle::affiche(){
    circlefill(bmap,tablPoint[0].getx(),tablPoint[0].gety(),rayon,makecol(109,190,91));
}
void balle::efface(){
    circlefill(bmap,tablPoint[0].getx(),tablPoint[0].gety(),rayon,makecol(0,0,0));
}
void balle::deplace(int newX, int newY,int speed){
    //efface();
    tablPoint[0].setx(newX);
    tablPoint[0].sety(newY);
    affiche();
}
#endif
