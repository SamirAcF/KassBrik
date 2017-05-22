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
        //bool selection(int,int){return false;}

};

#endif // MURBRIQUE_H_INCLUDED
