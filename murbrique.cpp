#ifndef MURBRIQUE_C_INCLUDED
#define MURBRIQUE_C_INCLUDED
#include <list>
#include "murBrique.h"
#include <allegro.h>
#include <iostream>

    murBrique::murBrique(list<brique*> listeBriques):m_listeBriques(listeBriques){}

    void murBrique::affiche(){
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){(*m_it)->affiche();}
    }
    murBrique::~murBrique(){
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){delete(*m_it);}
    }

    void murBrique::ajoutBrique(int i,int j,int col,int resistance){
        brique* briquette = new brique(i, i+70, j, j+30, col, resistance);
        m_listeBriques.push_front(briquette);
    }

    void murBrique::construireMur(int lignes, int colonnes){
    int flag = 0;
    for (int i = 0; i < lignes ; i++){
        for(int j = 0; j < colonnes; j++){
            if(flag){
                ajoutBrique(i*72,j*32,makecol(6*i,100+3*i,20),1);
                flag = 0;
            }
            else{
                ajoutBrique(i*72,j*32,makecol(0,100+3*j,5*j),1);
                flag = 1;
            }
            cout<<"yo";
            }
        }
    }

    void murBrique::casseBrique(point p){
        for (int i =0; i< m_listeBrique.size; i++){

        }
    }

    /*void murBrique::collision(int sx, int sy){
        bool res;
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){
            if((*m_it)->selection(sx,sy))
                if((*m_it)->action()){ m_listeBriques.remove(*m_it); return;}
        }
    }*/


#endif
