#ifndef _LSTPRIM_h
#define _LSTPRIM_h
#include "ELTPRIM.H"



LISTE listeCreer(void);
void listeDetruire(LISTE);
int estVide(LISTE);
int estSaturee(LISTE);
int listeTaille(LISTE);
ELEMENT recuperer(LISTE, int);
int inserer(LISTE, ELEMENT,int);
int supprimer(LISTE, int);
void listeAfficher(LISTE);
LISTE listeCopier(LISTE);
int listeComparer(LISTE, LISTE);




#endif


