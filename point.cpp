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
    if(nouv<0){
        x = 0;
    }
    else if(nouv> 600){
        x = 600;
    }
    else{
        x = nouv;
    }
}

void point::sety(int nouv){
    if(nouv<0){
        y = 0;
    }
    else if(nouv> 480){
        y = 480;
    }
    else{
        y = nouv;
    }
}

void point::deplace(int dep_x, int dep_y){
    x += dep_x;
    y += dep_y;
}

#endif
