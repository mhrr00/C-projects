
#include <stdlib.h>
#include <stdio.h>
#include "ELTPRIM1.H"
#include "PILEPRIM.H"

NOEUD1 NoeudCreer1(ELEMENT1 e) {
    NOEUD1 n;
    n = (NOEUD1) malloc(sizeof(structNoeud1));
    if (!n)
        printf("\n Plus d'espace");
    else {
        elementAffecter1(&n->info, e);
        n->suivant = NULL;
    }
    return n;
}

void NoeudDetruire1(NOEUD1 n) {
    elementDetruire1(n->info);
    free(n);
}

Pile PileCreer(void) {
    Pile P;
    P = (Pile) malloc(sizeof(laStruct1));
    if (!P)
        printf(" \nProblème de mémoire");
    else
        P->tete = NULL;
    return (P);
}

void PileDetruire(Pile P) {
    NOEUD1 n = P->tete;
    while (n != NULL) {
        P->tete = n->suivant;
        NoeudDetruire1(n);
        n = P->tete;
    }
    free(P);
}

int EstVide1(Pile P) {
    return (P->tete == NULL);
}

int EstSaturee1(Pile P) {
    NOEUD1 temp;
    int saturee = 1; /* on suppose mémoire saturée */
    temp = (NOEUD1) malloc(sizeof(structNoeud1));
    if (temp != NULL) {
        saturee = 0; /* mémoire non saturée */
        free(temp);
    }
    return saturee;
}

void PileAfficher(Pile P) {
    NOEUD1 n;
    n = P->tete;
    while (n != NULL) {
        elementAfficher1(n->info);
        n = n->suivant;
    }
}

int PileTaille(Pile P) {
    int taille = 0;
    NOEUD1 n;
    n = P->tete;
    while (n != NULL) {
        taille++;
        n = n->suivant;
    }
    return (taille);
}

int Empiler(Pile P, ELEMENT1 e) {
    int succes = 1;
    NOEUD1 n;

    if (EstSaturee1(P)) {
        printf("\n Pile saturée");
        succes = 0;
    } else {
        n = NoeudCreer1(e);
        n->suivant = P->tete;
        P->tete = n;
    }

    return (succes);
}

ELEMENT1 Depiler(Pile P) {
    ELEMENT1 elt;
    NOEUD1 n;
    if (EstVide1(P)) {
        printf("\n Pile vide");
        elt = elementCreer1();
    } else {
        n = P->tete;
        elementCopier1(&elt, n->info);
        P->tete = n->suivant;
        NoeudDetruire1(n);
    }
    return (elt);
}

ELEMENT1 Sommet(Pile P) {
    ELEMENT1 elt = elementCreer1();
    if (EstVide1(P))
        printf(" \n Pile vide");
    else
        elt = (P->tete)->info;
    return (elt);
}

Pile PileCopier(Pile P) {
    Pile PR = PileCreer();
    ELEMENT1 elt;
    NOEUD1 n1, n2, n3;
    n1 = P->tete;
    while (n1 != NULL) {
        elt = elementCreer1();
        elementCopier1(&elt, n1->info);
        n2 = NoeudCreer1(elt);
        if (n1 == P->tete) {
            PR->tete = n2;
            n3 = n2;
        } else {
            n3->suivant = n2;
            n3 = n2;
        }
        n1 = n1->suivant;
    }
    return PR;
}

int PileComparer(Pile P1, Pile P2) {
    int test = 1;
    NOEUD1 n1 = P1->tete;
    NOEUD1 n2 = P2->tete;
    if (PileTaille(P1) != PileTaille(P2))
        test = 0;
    while ((n1 != NULL) && (test)) {
        if (elementComparer1(n1->info, n2->info) != 0)
            test = 0;
        else {
            n1 = n1->suivant;
            n2 = n2->suivant;
        }
    }
    return test;
}
