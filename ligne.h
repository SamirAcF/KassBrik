#ifndef LIGNE_H
#define LIGNE_H
#include "point.h"
#include "raquette.h"

class ligne{
    point p1,p2;
public:
    ligne(point, point);
    collision(raquette cible);
    ~ligne();
    //collision(balle cible);
};

#endif
