#include <iostream>
#include <allegro.h>
#include "point.h"
#include "rectangle.h"
#include "brique.h"
#include "murbrique.h"
#include "raquette.h"
#include "balle.h"
#include "bouton.h"
#include <list>
#include <chrono>
#include <thread>
BITMAP* bmap;

using namespace std;

int main()
{
    srand((unsigned) time(NULL));
    int e,raquetteColor;
    int flagQuit = 0;
    allegro_init();
    install_keyboard();   //installe le clavier
    install_mouse();

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0)!=0){   // sélectionner un driver graphique approprié +initialisation de la résolution de l'écran (tailles 640-480)
      		allegro_message(allegro_error);
      		allegro_exit();
      		return 1;
   	}

    set_mouse_sprite(NULL);
    show_mouse(screen);
    set_keyboard_rate(10,2);
    bmap = create_bitmap(640,480);


/**********************************************INITIALISATION MUR DE BRIQUE*********************************************/

/*
    list<brique*> liste_briques;

    point x=point(20,20);
    point y=point(60,60);


    murBrique mur = murBrique(liste_briques);

    mur.faireCadre();
    mur.construireMur(7,7);
*/

/*****************************************************INITIALISATION RAQUETTE****************************************************/

/*
    raquetteColor = makecol(234,124,12);
    raquette pad = raquette();
    point a(SCREEN_W/2-35,SCREEN_H-40);
    point c(SCREEN_W/2+35,SCREEN_H-20);
    pad.setP1(a);
    pad.setP2(c);
    pad.setColor(makecol(127,125,255));
*/

/*****************************************************INITIALISATION BALLE********************************************************/

/*
    point b = point(SCREEN_W/2,pad.getP1().gety() - SCREEN_H/40);
    balle ball(b,SCREEN_H/40,makecol(12,123,123));

    e = readkey();
    if(e==15131){
        flagQuit = 1;
        exit(EXIT_SUCCESS);
    }
    cout << "RAYON : "<<ball.getRayon()<<endl;
*/

/************************************************************JEU***************************************************************/

/*
    while(!key[KEY_ESC]){
        clear_bitmap(bmap);
        flagQuit = 1;
        pad.deplace(1);
        mur.affiche();
        ball.collision(&mur);
        ball.collision(pad);
        cout<< " x ;  y : " << ball.getPointCentre().getx()<< " ; " << ball.getPointCentre().gety() << endl;
        //ball.collision();
        ball.deplace(1);
        blit(bmap, screen,0,0,0,0,640,480);
    }

    exit(EXIT_SUCCESS);
    destroy_bitmap(bmap);
*/
/*******************************************************TEST BOUTONS**********************************************************/

point p1(100,100);
point p2(300,200);
char* text = "salut";
Bouton newGame(p1,p2,makecol(125,122,122), text);
//rectfill(bmap, p1.getx(), p1.gety(), p2.getx(), p2.gety(), makecol(125,122,122));
cout<<"text :"<<newGame.getTxt()<<endl<<"x puis y :"<<endl<<newGame.getP1().getx()<<endl<<newGame.getP2().gety()<<endl;
newGame.affiche();
blit(bmap,screen,0,0,0,0,640,480);
readkey();
exit(EXIT_SUCCESS);
}END_OF_MAIN() ;
