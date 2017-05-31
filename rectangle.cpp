#ifndef RECTANGLE_C
#define RECTANGLE_C
#include "rectangle.h"
#include <iostream>

#include <allegro.h>


extern BITMAP* bmap;

rectangle::rectangle(int x1, int x2, int y1, int y2):p1(x1,y1),p2(x2,y2),length(x2-x1),width(y2-y1), m_couleur(0){}

rectangle::rectangle(int x1, int x2, int y1, int y2, int couleur):p1(x1,y1),p2(x2,y2),length(x2-x1),width(y2-y1), m_couleur(couleur){}

//rectangle::rectangle(point* sup_gau, point *inf_dr): p1(*sup_gau), p2(*inf_dr){}

rectangle::rectangle(point sup_gau, point inf_dr): p1(sup_gau), p2(inf_dr),length(sup_gau.getx()-inf_dr.getx()),width(sup_gau.gety()-inf_dr.gety()), m_couleur(0){}

rectangle::rectangle(point sup_gau):p1(sup_gau),p2(sup_gau){
    p2.deplace(40,20);
    width = 40;
    length = 20;
}

void rectangle::affiche(){
        rectfill(bmap, getP1().getx(), getP1().gety(), getP2().getx(), getP2().gety(), m_couleur);
    }

rectangle::rectangle(point sup_gau, point inf_dr, int couleur): p1(sup_gau), p2(inf_dr), m_couleur(couleur){}


rectangle::~rectangle(){}

void rectangle::deplace_rect(int dep_x, int dep_y){
    p1.deplace(dep_x,dep_y);
    p2.deplace(dep_x,dep_y);
}

bool rectangle::dans_rect(int pos_x, int pos_y){
    return(pos_x >= p1.getx() && pos_x <= p2.getx() && pos_y >= p1.gety() && pos_y <= p2.gety());
}

bool rectangle::dans_rect(point p){
    int i = 1;
    if(p.getx() < p1.getx() || p.getx() > p2.getx()){
        --i;
    }
    if(i){
        if(p.gety() < p1.gety() || p.gety() > p2.gety()){
            --i;
        }
    }
    return(i);
}

point rectangle::getP1(){
    return p1;
}

point rectangle::getP2(){
    return p2;
}

int rectangle::getLength(){
    return length;
}

void rectangle::setColor(int color){
    m_couleur = color;
}

void rectangle::setP1(point pnt){
    p1=pnt;
}

void rectangle::setP2(point pnt){
    p2=pnt;
}
#endif


