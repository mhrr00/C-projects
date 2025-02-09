
#ifndef PILEPRIM_H_INCLUDED
#define PILEPRIM_H_INCLUDED



#include "ELTPRIM1.h"

Pile PileCreer(void);
void PileDetruire(Pile);
int EstVide1(Pile);
int EstSaturee1(Pile);
int PileTaille(Pile);
ELEMENT1 Sommet(Pile);
int Empiler(Pile, ELEMENT1);
ELEMENT1 Depiler(Pile);
void PileAfficher(Pile);
Pile PileCopier(Pile);
int PileComparer(Pile, Pile);


#endif // PILEPRIM_H_INCLUDED
