
#ifndef ELTPRIM1_H_INCLUDED
#define ELTPRIM1_H_INCLUDED


#include "ELTSDD1.H"
void elementLire1(ELEMENT1 *);
void elementAfficher1(ELEMENT1);
void elementAffecter1(ELEMENT1*, ELEMENT1);
void elementCopier1(ELEMENT1 *, ELEMENT1) ;
int elementComparer1(ELEMENT1, ELEMENT1);
ELEMENT1 elementCreer1(void) ;
void elementDetruire1 (ELEMENT1);


#endif // ELTPRIM_H_INCLUDED
