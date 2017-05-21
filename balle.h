#ifndef BALLE_H
#define BALLE_H
#include "forme.h"
#include "point.h"

class balle : public forme {
    int xcentre;
    int ycentre;
    int rayon;
    int angle;
    int couleur;
    bool sticky;
public:
    balle(point,int);
    balle(point,int,int);
    balle(int,int,int,int);
    void collision();
    ~balle();
};

#endif
