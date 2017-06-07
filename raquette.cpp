#ifndef RAQUETTE_CPP_INCLUDED
#define RAQUETTE_CPP_INCLUDED
#include "raquette.h"
#include <allegro.h>
#include <iostream>

extern BITMAP* bmap;
using namespace std;

    raquette::raquette(): rectangle(){}
    raquette::raquette(point x, point y) : rectangle(x,y){}
    raquette::raquette(point x, int length, int width,int color):rectangle(x.getx(),x.gety(),color){}
    raquette::raquette(point x, point y, int color) : rectangle(x,y,color){}
    raquette::raquette(int x1, int x2, int y1, int y2) : rectangle(x1,x2,y1,y2){}
    raquette::raquette(int x1, int x2, int y1, int y2, int color) : rectangle(x1,x2,y1,y2,color){}

    void raquette::affiche(){
        rectfill(bmap, getP1().getx(), getP1().gety(), getP2().getx(), getP2().gety(), m_couleur);
    }


    void raquette::deplace(int depl){

        if(key[KEY_LEFT]){
            if(p1.getx()> 12){
                p1.setx(p1.getx()-depl);
                p2.setx(p1.getx()+70);
            }
            affiche();
        }
        else if(key[KEY_RIGHT]){
            if(p2.getx()<502){
                p2.setx(p2.getx()+depl);
                p1.setx(p2.getx()-70);

                /*cout<<"p1 : "<<p1.getx()<<endl<<"p2 : "<<p2.getx()<<endl<<"longueur : "<<p2.getx()-p1.getx()<<endl;
                cout<<"p1 y: "<<p1.gety()<<endl<<"p2 y: "<<p2.gety()<<endl<<"largeur : "<<p2.gety()-p1.gety()<<endl;*/
            }
            affiche();
        }
        else{
            affiche();
        }
    }
    raquette::~raquette(){}


#endif
