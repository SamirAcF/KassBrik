#include "briquenormale.h"
#include "murbrique.h"

void briqueNormale::action(){
    m_compteur--;
    if(m_compteur < 1){
        murBrique::casseBrique(this);
    }
}
