

#ifndef _lstprim1_h
#define _lstprim1_h
#include "ELTPRIM2.H"



LISTE1 listeCreer2(void);
void listeDetruire2(LISTE1);
int estVide2(LISTE1);
int estSaturee2(LISTE1);
int listeTaille2(LISTE1);
ELEMENT2 recuperer2(LISTE1, int);
int inserer2(LISTE1, ELEMENT2,int);
int supprimer2(LISTE1, int);
void listeAfficher2(LISTE1);
LISTE1 listeCopier2(LISTE1);
int listeComparer2(LISTE1, LISTE1);




#endif


