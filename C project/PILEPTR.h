
#ifndef PILEPTR_H_INCLUDED
#define PILEPTR_H_INCLUDED

#include "ELTPRIM1.h"

typedef struct structNoeud1 {
ELEMENT1 info;
struct structNoeud1 * suivant;
} structNoeud1, * NOEUD1;

typedef struct {
NOEUD1 tete; /* Sommet de la pile */
} laStruct1,*Pile;

#endif // PILEPTR_H_INCLUDED
