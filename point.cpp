#ifndef POINT_C
#define POINT_C
#include <allegro.h>
#include <iostream>
#include "point.h"

point::point(int x, int y): x(x), y(y){}

point::~point(){}

int point::getx() const{
    return(x);
}

int point::gety() const{
    return(y);
}

void point::setx(int nouv){
    if(x<10){
        x = 10;
    }
    else if(x > 590){
        x = 590;
    }
    else{
        x = nouv;
    }
}

void point::setx(int nouv,int depl){
    if(x-depl<10){
        x = 10;
    }
    else if(x+depl > 590){
        x = 590;
    }
    else{
        x = nouv;
    }
}

void point::sety(int nouv){
    y = nouv;
}

void point::deplace(int dep_x, int dep_y){
    x += dep_x;
    y += dep_y;
}

#endif
