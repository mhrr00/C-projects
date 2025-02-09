#ifndef _ELTCHAR_h
#define _ELTCHAR_h
#include "ELTPRIM.h"
typedef char *ELEMENT;
typedef struct structNoeud {

ELEMENT info;
struct structNoeud *suivant;
} structNoeud, * NOEUD;

typedef struct {
NOEUD tete;
int lg;
} laStruct,*LISTE;
#endif
