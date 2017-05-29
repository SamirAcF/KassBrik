#ifndef MURBRIQUE_C_INCLUDED
#define MURBRIQUE_C_INCLUDED
#include <list>
#include "murBrique.h"
#include <allegro.h>
#include <iostream>
#include "briquenormale.h"
#include "brique.h"
extern BITMAP* bmap;

    murBrique::murBrique(list<brique*> listeBriques):m_listeBriques(listeBriques){}

    void murBrique::affiche(){
        clear_bitmap(bmap);
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){
            (*m_it)->affiche();
        }
    }
    murBrique::~murBrique(){
         for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){delete(*m_it);}
    }

    void murBrique::ajoutBrique(int i,int j,int col,int resistance){
        briqueNormale* briquette = new briqueNormale(i, i+70, j, j+30, col, resistance);
        m_listeBriques.push_front(briquette);
    }

    void murBrique::construireMur(int lignes, int colonnes){
    int flag = 0;
    for (int i = 0; i < lignes ; i++){
        for(int j = 0; j < colonnes; j++){
            if(flag){
                ajoutBrique(i*71,j*31,makecol(40,255,100),1);
                flag = 0;
            }
            else{
                ajoutBrique(i*71,j*31   ,makecol(255,100,40),1);
                flag = 1;
            }
            }
        }
    }

    void murBrique::casseBrique(point p){
       for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){
            if((*m_it)->dans_rect(p)){
                m_listeBriques.remove(*m_it);
                return;
            }
        }
    }

    void murBrique::interaction(point p){
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){
            if((*m_it)->dans_rect(p)){
                (*m_it)->action();
                return;
            }
        }
    }

    /*void murBrique::casseBrique(brique* b){    //neccessite une surcharge de l'op ==
       for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){
            if((*m_it) == *b){
                m_listeBriques.remove(*m_it);
                return;
            }
        }
    }
*/

    void murBrique::faireCadre(){
        briqueNormale* briquette = new briqueNormale(0, 10, 0, 480, makecol(130,130,130), -1);
        m_listeBriques.push_front(briquette);
        briquette = new briqueNormale(0, 640, 0, 10, makecol(130,130,130), -1);
        m_listeBriques.push_front(briquette);
        briquette = new briqueNormale(630, 640, 0, 480, makecol(130,130,130), -1);
        m_listeBriques.push_front(briquette);
        briquette = new briqueNormale(0, 640, 470, 480, makecol(130,130,130), -1);
        m_listeBriques.push_front(briquette);

    }
    /*void murBrique::collision(int sx, int sy){
        bool res;
        for(m_it = m_listeBriques.begin(); m_it!=m_listeBriques.end(); m_it++){
            if((*m_it)->selection(sx,sy))
                if((*m_it)->action()){ m_listeBriques.remove(*m_it); return;}
        }
    }*/


#endif
