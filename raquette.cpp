#ifndef RAQUETTE_CPP_INCLUDED
#define RAQUETTE_CPP_INCLUDED
#include "raquette.h"
#include <allegro.h>
#include <iostream>

using namespace std;

    raquette::raquette(): rectangle(){}
    raquette::raquette(point x, point y) : rectangle(x,y){}
    raquette::raquette(point x, int length, int width,int color):rectangle(x.getx(),x.gety(),color){}
    raquette::raquette(point x, point y, int color) : rectangle(x,y,color){}
    raquette::raquette(int x1, int x2, int y1, int y2) : rectangle(x1,x2,y1,y2){}
    raquette::raquette(int x1, int x2, int y1, int y2, int color) : rectangle(x1,x2,y1,y2,color){}

    void raquette::affiche(){
        rectfill(screen, getP1().getx(), getP1().gety(), getP2().getx(), getP2().gety(), m_couleur);
    }

    void raquette::efface(){
        int temp;
        temp=m_couleur;
        setColor(makecol(0,0,0));
        affiche();
        setColor(temp);
    }


    void raquette::deplace(int e, int depl){

        switch(e){
        case 20992 :
            if(p1.getx()> 0){
                efface();
                p1.setx(p1.getx()-depl);
                p2.setx(p2.getx()-depl);
                setColor(m_couleur);
                cout<<"p1 : "<<p1.getx()<<endl<<"p2 : "<<p2.getx()<<endl<<"longueur : "<<p2.getx()-p1.getx()<<endl;
                affiche();
            }
            else{
            cout<<"rien"<<endl;
            }
        break;
        case 21248 :
            if(p2.getx()<600){
                efface();
                p2.setx(p2.getx()+depl);
                p1.setx(p1.getx()+depl);
                setColor(m_couleur);
                cout<<"p1 : "<<p1.getx()<<endl<<"p2 : "<<p2.getx()<<endl<<"longueur : "<<p2.getx()-p1.getx()<<endl;
                affiche();
            }

        break;
        }
    }
    raquette::~raquette(){}


#endif
