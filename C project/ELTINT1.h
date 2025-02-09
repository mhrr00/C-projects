

#ifndef _ELTINT1_h
#define _ELTINT1_h
#include "ELTPRIM2.h"
typedef struct {
    int crypt[10000];
}crypt,*ELEMENT2;
typedef struct structNoeud2 {

ELEMENT2 info;
struct structNoeud2 *suivant;
} structNoeud2, * NOEUD2;

typedef struct {
NOEUD2 tete;
int lg;
} laStruct2,*LISTE1;
#endif
