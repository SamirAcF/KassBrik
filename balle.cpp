#ifndef BALLE_C
#define BALLE_C
#include <iostream>
#include <allegro.h>
#include "balle.h"
/*
balle::balle(int a,int b, int ray, int color): xcentre(a),ycentre(b),rayon(ray),couleur(color){}
balle::balle(int a,int b, int ray): xcentre(a),ycentre(b),rayon(ray){}
balle::balle(point point, int ray):xcentre(point.getx()),ycentre(point.gety()),rayon(ray),couleur(makecol(128,128,128)){}
balle::balle(point point, int ray, int color):xcentre(point.getx()),ycentre(point.gety()),rayon(ray),couleur(color){}
balle::~balle(){}


/*************************************GETTERS AND SETTERS********************************************************/
  /*
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

    void balle::setPointCentre(pnt){
        tablePoint[0] = pnt;
    }

    void balle::setPointNord(pnt){
        tablePoint[1] = pnt;
    }

    void balle::setPointSud(pnt){
        tablePoint[2] = pnt;
    }

    void balle::setPointEst(pnt){
        tablePoint[3] = pnt;
    }

    void balle::setPointOuest(pnt){
        tablePoint[4] = pnt;
    }

    void balle::setRayon(int ray){
        rayon = ray;
    }

/************************************METHODES GENERALES**********************************************************/
/*void balle::collision()
{

}
void balle::affiche(){
    circlefill(screen,xcentre,ycentre,rayon,makecol(109,190,91));
}
void balle::efface(){
    circlefill(screen,xcentre,ycentre,rayon,makecol(0,0,0));
}
void balle::deplace(int newX, int newY,int speed){
    efface();
    xcentre=newX;
    ycentre=newY;
    affiche();
}*/
#endif
