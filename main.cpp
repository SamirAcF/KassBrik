#include <iostream>
#include <allegro.h>
#include "point.h"
#include "rectangle.h"
#include "brique.h"
#include "murbrique.h"
#include "raquette.h"
#include <list>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;
/* bouton, menu, brique 1, mini exemple

class bouton : public forme{
    protected :
    public :
    //...
    void affiche();
};

class menu : public forme{
    protected :
    public :
    //...
    void affiche();
};

class brique1:public brique{
    protected :
    public:
    brique1(int,int);
    ~brique1(){}
    bool action();

    brique1::brique1(int px, int py):brique(px,py){
        couleur = makecol(100,100,100);
        compteur = 3; // 3 coups pour détruire la brique
    }
    bool brique1::action(){
        couleur = couleur--; //par exempl
        if(--compeur == 0){
            return(true);
        }
        return(false);

    }
};

/* UTILISATION :
    rectangle *r1 = new rectangle (1,1,40,30);
    rectangle *r2 = new rectangle (100,100,50,30);
    bouton *b1 = neww bouton(*r1, "bouton1");
    ...


    ttab[0] = r1;
    ttab[1] = r2;
    ttab[2] = b1;

    for(int i = à; i<4;i++)
    ttab[i]->affiche();
    */
/* menu2, du code sur les classes
vector <forme*> v;
v.push_back(r1);
v.push_back(r2);
v.push_back(b1);
v.push_back(b2);
for(int i=0; i<v.size();i++){v[i]->affiche();}
//suppression du dernier objet inséré et afichage :
v.pop_back();
for(int i = 0; i<v.size(); i++){
    v[i]->affiche();
}
//insertion générique par lot :
vector <forme*> v;
int drap = 1;
for (int i = 0;i<10;i++){
    if (drap){
        v.push_back(new rectangle(1,1,2,2));
        drap = 0;
    }
    else{
        v.push_back(new bouton(2,2,3,3,"bouton"));
        drap = 1;
    }
}
for(i = 0; i<10;i++){v[i]->affiche();}

class bouton{
protected:
rect r;
string ch;
public :
    bouton(int,int,int,int,char*);
    bouton(point,point,char*);
    bouton(point,string);
    bouton(rect,string);
    ~bouton();
    bouton::bouton():r(0,0,0,0),ch(){} //constructeur par défaut
    void affiche();
    bouton::bouton(int x1, int y1, int x2, int y2, char* pch):
        r(x1, y1, x2, y2),
        ch(pch)
    {}
    bouton::bouton(point pp1, point pp2, char* pch):
        r(pp1, pp2),
        ch(pch)
    {}
    bouton::bouton(rect pr, string ps):
    r(pr),
    ch(pch){}

void bouton::affiche(){
r.affiche();
cout<<"chaine = "<<ch<<endl;
}
void bouton::init(float px1, float py2, float px2, float py2, char *pch){
r.init(px1,py1,px2,py2,pch);

}
}

class menu{
    protected:
        bouton *tab;
        int nb;
    public:
    menu(char** int)
    ~menu()
    menu(const menu&);

    menu::~menu(){
        delete []tab;
    }
    menu::menu(const menu& src){
        nb = src.nb
        tab = new bouton[nb];
        for (int i = 0; i<nb;i++){
            tab[i].init(src.tab[i]); //il manque une fonction init qui joue le meme role que le constructeur de recopie.
            //ou tab[i].init(bouton tmp(tab[i]);
        }
    }
    menu::menu(const menu& src){
        nb = src.nb;
        tab = new bouton[nb];
        for (int i =0; i<nb;i++){
            tab[i] = src.tab[i];
        }
    }
    void menu::affiche(){
        for (int i = 0; i <nb;i++){
            tab[i].affiche(); //appel a la fonction affiche des boutons.
        }
    }
    menu& menu::operator=(const menu& src){
        if(this != &src){
        //ecrire code du destructeur
            delete []tab;
        //ecrire code du constructeur
        }
        return *this;
    }

}

//meilleur menu :

class menu2{
    protected:
        bouton **tab;
        int nb;
    public:
    menu2::menu2(char* t[], int pnb){
        tab = new bouton*[nb=pnb];
        for(int i =0; i <nb;i++){
            tab[i] = new bouton(i,2*i,i,2*i, t[i]);
        }
    }
    menu2::~menu2(){
        for(in i = 0; i<nb;i++){
            delete(tab[i]);
        }
        delete tab;
    }
    menu2::menu2(const menu2& src){
        nb = src.nb;
        tab = new bouton*[nb];
        for(int i =0; i<nb ; i++){
            tab[i]=new bouton(*(src.tab[i]));
        }
    }
        void menu2::affiche(){
        for (int i = 0; i <nb;i++){
            tab[i]->affiche(); //appel a la fonction affiche des boutons.
        }
    }
        menu2& menu2::operator=(const menu& src){
        if(this != &src){
        for(in i = 0; i<nb;i++){
            delete(tab[i]);
        }
        delete tab;
        for(int i =0; i<nb ; i++){
            tab[i]=new bouton(*(src.tab[i]));
        }
        }
        return *this;
    }
}
*/

int main()
{
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
    set_keyboard_rate(10,20);

    /*
    list<brique*> liste_briques;

    point x=point(20,20);
    point y=point(60,60);

    brique * p_brique;


    brique bite;

    for (int i = 0; i < 100; i=i+50){
        for(int j = 0; j < 60; j = j+30){
            p_brique = bite.genere_brique(i,j,i+30,j+50,makecol(100,100,100),1);
            liste_briques.push_front(p_brique);
            cout << liste_briques.get();
            //j = j+2;
        }
        //i=i+2;
    }

    murBrique test = murBrique(liste_briques);
    test.affiche();
*/
    raquetteColor = makecol(234,124,12);
    point a(10,10);
    point b(70,30);
    raquette raquette(a,b,raquetteColor);
    raquette.affiche();
while(!flagQuit){
    e = readkey();
    if(e==15131){
        flagQuit = 1;
        exit(EXIT_SUCCESS);
    }
    else{
        raquette.deplace(e,5);
    }
}
}END_OF_MAIN() ;
