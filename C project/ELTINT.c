
#include <stdio.h>
#include <stdlib.h>

#include "ELTPRIM1.H"

ELEMENT1 elementCreer1(void) {
    ELEMENT1 e;
    e.d = 0;
    e.n = 0;
    return e;
}
void elementDetruire1 (ELEMENT1 elt) {
/* ne fait rien en stockage direct*/}
void elementAffecter1(ELEMENT1 * e1, ELEMENT1 e2) {
*e1 = e2 ;}
void elementCopier1(ELEMENT1 * e1, ELEMENT1 e2) {
(*e1).n = e2.n;
(*e1).d = e2.d;}
void elementLire1(ELEMENT1 * elt) {
printf(" \nun couple d' entier svp :") ;
scanf("%d",&(*elt).n);
scanf("%d",&(*elt).d);
}
void elementAfficher1(ELEMENT1 elt) {
printf("(%d.%d) ",elt.n,elt.d);
}
int elementComparer1(ELEMENT1 e1, ELEMENT1 e2){
return ((e1.n)-(e2.n)==0&&(e1.d)-(e2.d)==0);
}

