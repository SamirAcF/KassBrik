#ifndef BRIQUE_CPP_INCLUDED
#define BRIQUE_CPP_INCLUDED
#include "brique.h"
#include <allegro.h>
#include <iostream>

    extern BITMAP* bmap;

    brique::brique(int x1, int x2, int y1, int y2, int compteur): rectangle(x1, x2, y1, y2),m_compteur(compteur){}

    brique::brique(int x1, int x2, int y1, int y2, int couleur, int compteur): rectangle(x1, x2, y1, y2, couleur),m_compteur(compteur){}

    brique::brique(point p1, point p2, int couleur, int compteur): rectangle(p1,p2,couleur), m_compteur(compteur){}

    brique::brique():rectangle(), m_compteur(1){}

    brique* brique::genere_brique(int x1,int x2,int y1,int y2,int couleur,int compteur){
        brique* retour = (brique*)malloc (sizeof(brique));
        brique retoure = brique(x1, x2, y1, y2, couleur, compteur);
        retour = &retoure;
        return (retour);
    }

    brique::~brique(){}


#endif //brique.cpp included
