

#include <stdio.h>

#include "ELTPRIM2.h"

ELEMENT2 elementcreer2(){
    ELEMENT2 e=(ELEMENT2) malloc (sizeof(crypt));
    return e;
}

void elementdetruire2 (ELEMENT2 e){
    free(e);
}

void elementlire2(ELEMENT2 * e){
    printf("donner un entier \n");
    scanf("%d",*e->crypt);
}

void elementafficher2(ELEMENT2 e){
    int i;
    for(i=0;i<e->crypt[i]!=0;i++)
        printf("%d.",e->crypt[i]);
    printf("\n");
}

void elementaffecter2(ELEMENT2 * e1, ELEMENT2 e2){
    *e1=e2;
}

void elementcopier2 (ELEMENT2 * e1, ELEMENT2 e2){
    (*e1)=e2;
}

int elementcomparer2 (ELEMENT2 e1, ELEMENT2 e2){
    return (e1-e2);
}

