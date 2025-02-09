#ifndef _ELTPRIM_h
#define _ELTPRIM_h
#include "ELTSDD.h"

ELEMENT elementcreer(void);
void elementlire(ELEMENT *);
void elementdetruire(ELEMENT);
void elementafficher(ELEMENT);
void elementaffecter(ELEMENT *,ELEMENT);
void elementcopier(ELEMENT *,ELEMENT);
int elementcomparer(ELEMENT , ELEMENT);


#endif
