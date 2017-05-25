#ifndef BRIQUE_H_INCLUDED
#define BRIQUE_H_INCLUDED
#include "point.h"
#include "rectangle.h"
#include "forme.h"


class brique : public rectangle{
    protected :
        int m_compteur;
    public :
        brique();
        brique(int,int,int,int,int);
        brique(int,int,int,int,int,int);
        brique(point,point,int,int);
        brique* genere_brique(int,int,int,int,int,int);
        ~brique();
        //virtual bool action()=0;
        //bool selection(int,int){return false;}
};

#endif // BRIQUE_H_INCLUDED
