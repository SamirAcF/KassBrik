#ifndef MURBRIQUE_C_INCLUDED
#define MURBRIQUE_C_INCLUDED
#include <list>
#include "murBrique.h"

    murBrique::murBrique(list<brique*> listeBriques):m_listeBriques(listeBriques){}

    void murBrique::affiche(){
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){(*m_it)->affiche();}
    }
    murBrique::~murBrique(){
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){delete(*m_it);}
    }

    /*void murBrique::collision(int sx, int sy){
        bool res;
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){
            if((*m_it)->selection(sx,sy))
                if((*m_it)->action()){ m_listeBriques.remove(*m_it); return;}
        }
    }*/


#endif
