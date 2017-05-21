#ifndef BALLE_C
#define BALLE_C
#include <iostream>
#include <allegro.h>
#include "balle.h"

balle::balle(int a,int b, int ray, int color): xcentre(a),ycentre(b),rayon(ray),couleur(color){}
balle::balle(point point, int ray):xcentre(point.getx()),ycentre(point.gety()),rayon(ray),couleur(makecol(128,128,128)){}
balle::balle(point point, int ray, int color):xcentre(point.getx()),ycentre(point.gety()),rayon(ray),couleur(color){}
balle::~balle(){}
void balle::collision()
{

}

#endif
