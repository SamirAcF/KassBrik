#ifndef BRIQUE_NORMALE_H_INCLUDED
#define BRIQUE_NORMALE_H_INCLUDED
#include "brique.h"

class briqueNormale : public brique{
    protected :
    public :
    void action();

    briqueNormale* genere_brique(int,int,int,int,int,int);
    briqueNormale(int,int,int,int,int,int);
};

#endif // BRIQUE_NORMALE_H_INCLUDED
