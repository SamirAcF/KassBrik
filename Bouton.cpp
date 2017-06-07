#include "Bouton.h"
#include <allegro.h>
#include <iostream>

extern BITMAP* bmap;
using namespace std;

Bouton::Bouton()
{
    rectangle(0,0,200,100);
}

Bouton::Bouton(char* str)
{
    rectangle(0,0,200,100);
    txt = str;
}

Bouton::Bouton(int x1, int y1, int x2, int y2, char* str)
{
    rectangle(x1,y1,x2,y2);
    txt = str;
}

Bouton::Bouton(point p1, point p2, char* str)
{
    rectangle(p1,p2);
    txt = str;
}

Bouton::Bouton(point p1, point p2, int color, char* str)
{
    rectangle(p1,p2,color);
    txt = str;
}

Bouton::~Bouton()
{
    //dtor
}

Bouton::Bouton(const Bouton& other)
{
    //copy ctor
}

void Bouton::affiche(){
    rectangle::affiche();
    int longueurTxt = text_length(font, txt);
    int largeurTxt = text_height(font);
    int xText = (p1.getx()+(p2.getx()-p1.getx())/2)-(longueurTxt/2);
    int yText = (p1.gety()+(p2.gety()-p1.gety())/2)-(largeurTxt/2);
    textout_ex(bmap, font, "Click Me", xText, yText, makecol(0, 0, 255), -1);
}
