#include "briquenormale.h"
#include "murbrique.h"

int briqueNormale::action(){
    m_compteur--;
    return(m_compteur);
}

briqueNormale* briqueNormale::genere_brique(int x1,int x2,int y1,int y2,int couleur,int compteur){
    briqueNormale* retour = new briqueNormale(x1, x2, y1, y2, couleur, compteur);
    return (retour);
}

briqueNormale::briqueNormale(int x1, int x2, int y1, int y2, int couleur, int compteur): brique(x1, x2, y1, y2, couleur, compteur){}
