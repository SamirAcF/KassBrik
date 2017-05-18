#ifndef POINT_C
#define POINT_C

#include "point.h"

point::point(int x, int y): x(x), y(y){}

point::~point(){}

int point::getx() const{
    return(x);
}

int point::gety() const{
    return(y);
}

void point::deplace(int dep_x, int dep_y){
    x += dep_x;
    y += dep_y;
}

#endif
