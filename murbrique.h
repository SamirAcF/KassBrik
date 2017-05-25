#ifndef MURBRIQUE_H_INCLUDED
#define MURBRIQUE_H_INCLUDED
#include <list>
#include "brique.h"
using namespace std;
//class brique;
class murBrique : public forme{
    protected :
        list<brique*> m_listeBriques;
        list<brique*>::iterator m_it;
    public :
        murBrique(list<brique*>);
        ~murBrique();
        void affiche();
        void collision(int, int);
        void ajoutBrique(int,int,int,int);
        void construireMur(int,int);
        void casseBrique(point);
        void casseBrique(brique*);
        void faireCadre();
        void interaction(point) ;
        //bool selection(int,int){return false;}

};

#endif // MURBRIQUE_H_INCLUDED
