#ifndef MURBRIQUE_H_INCLUDED
#define MURBRIQUE_H_INCLUDED
#include <list>
#include "brique.h"
#include "raquette.h"
#include "briquenormale.h"
using namespace std;


class murBrique : public forme{
    protected :
        list<brique*> m_listeBriques;
        list<brique*>::iterator m_it;
    public :
        murBrique(list<brique*>);
        ~murBrique();
        void affiche();
        brique* collision(int, int);
        void ajoutBrique(int,int,int,int);
        void construireMur(int,int);
        void casseBrique(point);
        void casseBrique(brique*);
        void faireCadre();
        void interaction(point) ;
        list<brique*> getList();
         list<brique*>::iterator getIt();
        //bool selection(int,int){return false;}
};

#endif // MURBRIQUE_H_INCLUDED
