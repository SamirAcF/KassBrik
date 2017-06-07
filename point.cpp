#ifndef POINT_C
#define POINT_C
#include <allegro.h>
#include <iostream>
#include "point.h"

point::point(float x, float y): x(x), y(y){}
point::~point(){}
point::point():x(0), y(0){}

float point::getx() const{
    return(x);
}

float point::gety() const{
    return(y);
}

void point::setx(float nouv){
    if(nouv<10){
        x = 10;
    }
    else if(nouv> 640){
        x = 640;
    }
    else{
        x = nouv;
    }
}

void point::sety(float nouv){
    if(nouv<10){
        y = 10;
    }
    else if(nouv> 470){
        y = 470;
    }
    else{
        y = nouv;
    }
}

void point::deplace(float dep_x, float dep_y){
    x += dep_x;
    y += dep_y;
}
point point::operator=(point p){
    setx(p.getx());
    sety(p.gety());
}
#endif
