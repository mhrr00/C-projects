#include <stdio.h>

#include "ELTPRIM.h"

ELEMENT elementcreer(){
    ELEMENT e=(ELEMENT) malloc (sizeof(char));
    return e;
}

void elementdetruire (ELEMENT e){
    free(e);
}

void elementlire(ELEMENT * e){
    printf("donner un phrase \n");
    scanf("%s",*e);
}

void elementafficher(ELEMENT e){
    printf("%s  \n", e);
}

void elementaffecter(ELEMENT * e1, ELEMENT e2){
    *e1=e2;
}

void elementcopier (ELEMENT * e1, ELEMENT e2){
    (*e1)=e2;
}

int elementcomparer (ELEMENT e1, ELEMENT e2){
    return strcmp(e1,e2);
}

