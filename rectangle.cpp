#ifndef RECTANGLE_C
#define RECTANGLE_C
#include "rectangle.h"

rectangle::rectangle(int x1, int x2, int y1, int y2):p1(x1,y1),p2(x2,y2), m_couleur(0){}

rectangle::rectangle(int x1, int x2, int y1, int y2, int couleur):p1(x1,y1),p2(x2,y2), m_couleur(couleur){}

//rectangle::rectangle(point* sup_gau, point *inf_dr): p1(*sup_gau), p2(*inf_dr){}

rectangle::rectangle(point sup_gau, point inf_dr): p1(sup_gau), p2(inf_dr), m_couleur(0){}

rectangle::rectangle(point sup_gau):p1(sup_gau),p2(sup_gau){
    p2.deplace(40,20);
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
    return(p.getx() >= p1.getx() && p.getx() <= p2.getx() && p.gety() >= p1.gety() && p.gety() <= p2.gety());
}

point rectangle::getP1(){
    return p1;
}

point rectangle::getP2(){
    return p2;
}

void rectangle::affiche(){
    //rien faire
}

#endif


