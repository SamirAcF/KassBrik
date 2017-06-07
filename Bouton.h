#ifndef BOUTON_H
#define BOUTON_H

#include "rectangle.h"
#include "point.h"
#include <iostream>
#include <string>

class Bouton : public rectangle{
    private:
        char* txt;
    public:
        Bouton();
        Bouton(char*);
        Bouton(int,int,int,int,char*);
        Bouton(point, point, char*);
        Bouton(point, point, int, char*);
        ~Bouton();
        Bouton(const Bouton& other);

        void affiche();
        void ecrire();

        void Setxt(char* val) { txt = val; }
        char* GetTxt() { return txt; }
};

#endif // BOUTON_H
