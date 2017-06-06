#ifndef BALLE_C
#define BALLE_C
#include <iostream>
#include <allegro.h>
#include <math.h>
#include "balle.h"
#include <ctime>
#include "point.h"

extern BITMAP* bmap;
using namespace std;
#define PI 3.14159265

balle::balle(point pt, int ray){
    tablPoint[0] = pt;
    rayon= ray;
    couleur = makecol(128,128,128);
    angle = PI/4;
    }
balle::balle(int x1,int y1, int ray, int col){
    point pt= point(x1,y1);
    tablPoint[0] = pt;
    rayon= ray;
    couleur = makecol(128,128,128);
    angle = PI/4;
    }
balle::balle(point ptCtr, int ray, int color){
    tablPoint[0] = ptCtr;
    cout<< ptCtr.getx()<< "    " << ptCtr.gety()<< endl;
    rayon = ray;
    tablPoint[1] = point(tablPoint[0].getx()+rayon,tablPoint[0].gety());
    tablPoint[2] = point(tablPoint[0].getx()-rayon,tablPoint[0].gety());
    tablPoint[3] = point(tablPoint[0].getx(),tablPoint[0].gety()+rayon);
    tablPoint[4] = point(tablPoint[0].getx(),tablPoint[0].gety()-rayon);
    couleur= color;
    angle = PI/3;
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

void balle::collision(){ //collision cadre exterieur, inutilisée car gérée par collision briques
     if(getPointNord().gety() <= 10){
        angle = -atan2(sin(angle),cos(angle));
        cout<<"col Nord"<<endl;
    }
    else if(getPointSud().gety()>= 470){
        angle = atan2(-sin(angle),cos(angle));
        cout<< "col sud"<<endl;
    }
    else if(getPointEst().getx() >= 500){
        angle = atan2(sin(angle),-cos(angle));
        cout<<"col est"<<endl;
    }
    else if(getPointOuest().getx() <= 10){
        angle = atan2(sin(angle),-cos(angle));
        cout<<"col  Ouest"<<endl;
    }
}

void balle::bounceNord(){
    cout<< "bounceNord"<< endl;
    angle = -atan2(sin(angle),cos(angle));
}

void balle::bounceSud(){
    cout<< "bounceSud"<< endl;
     angle = atan2(-sin(angle),cos(angle));
}

void balle::bounceEst(){
    cout<< "bounceEst"<< endl;
    angle = atan2(sin(angle),-cos(angle));
}

void balle::bounceOuest(){
    cout<< "bounceOuest"<< endl;
    angle = atan2(sin(angle),-cos(angle));
}

void balle::collision(murBrique* mur) //collision briques
{
    brique* temp = NULL;
    for(int i = 1; i<5; i++){
        temp = mur->collision(tablPoint[i].getx(), tablPoint[i].gety());
        if(temp){
            cout<< "OLABRIK "<<endl;
            if((tablPoint[1].getx() < temp->getP2().getx() && tablPoint[1].getx() > temp->getP1().getx())){
                if(tablPoint[2].gety() >= temp->getP1().gety()){
                    bounceSud();
                    if(tablPoint[2].gety() > SCREEN_H-40){
                        tablPoint[0].sety(424);
                        majPoints();
                        affiche();
                    }
                }
                else if(tablPoint[1].gety() <= temp->getP2().gety()){
                    bounceNord();
                }
            }
            else if(tablPoint[3].gety() > temp->getP1().gety() && tablPoint[3].gety() < temp->getP2().gety()){
                if(tablPoint[3].getx() >= temp->getP1().getx()){
                    bounceEst();
                }
                else if(tablPoint[4].getx() <= temp->getP2().getx()){
                    bounceOuest();
                }
            }


            return;
        }
    }
}

void balle::collision(raquette pad){  //collision raquette
    if(tablPoint[2].getx() > pad.getP1().getx() && tablPoint[2].getx()< pad.getP2().getx()){
        if(tablPoint[2].gety() > pad.getP1().gety()){
            cout<< "OLARAKET  "<<endl;
            //bounceSud(pad.getP2().getx - pad.getP1().getx())
            bounceSud();
            if(tablPoint[2].gety() > SCREEN_H-40){
                tablPoint[0].sety(424);
                majPoints();
                affiche();
            }
        }
    }
}

void balle::affiche(){
    circlefill(bmap,tablPoint[0].getx(),tablPoint[0].gety(),rayon,makecol(109,190,91));
}
void balle::efface(){
    circlefill(bmap,tablPoint[0].getx(),tablPoint[0].gety(),rayon,makecol(0,0,0));
}
void balle::deplace(int speed){
    double newX = cos(angle)*speed;
    double newY = sin(angle)*speed;
    //readkey();
    tablPoint[0].setx(tablPoint[0].getx()+ newX);
    tablPoint[0].sety(tablPoint[0].gety()+ newY);
    majPoints();
    affiche();
}

void balle::majPoints(){
    tablPoint[1].sety(tablPoint[0].gety()-rayon);
    tablPoint[1].setx(tablPoint[0].getx());

    tablPoint[2].sety(tablPoint[0].gety()+rayon);
    tablPoint[2].setx(tablPoint[0].getx());

    tablPoint[3].sety(tablPoint[0].gety());
    tablPoint[3].setx(tablPoint[0].getx()+rayon);

    tablPoint[4].sety(tablPoint[0].gety());
    tablPoint[4].setx(tablPoint[0].getx()-rayon);
}


#endif
