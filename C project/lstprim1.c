

#include "lstprim1.h"
#include <stdlib.h>
#include "malloc.h"
#include "ELTPRIM2.h"

NOEUD2 noeudCreer2(ELEMENT2 e){
NOEUD2 n;
n =(NOEUD2)malloc(sizeof(structNoeud2));
if(!n)
printf ("\nPlus d'espace");
else{
elementaffecter2(&n->info, e);
n->suivant = NULL;
}
return n;
}

void noeudDetruire2(NOEUD2 n){
elementdetruire2(n->info);
free(n);
}
LISTE1 listeCreer2(void) {
LISTE1 L;
L=(LISTE1)malloc(sizeof(laStruct2));
if (! L)
printf("\nProbleme de memoire");
else {
L->lg = 0;
L->tete = NULL;
}
return(L);
}

void listeDetruire2(LISTE1 L){
int i;
NOEUD2 p, q;
q= L->tete;
for(i = 1;i <= L->lg; i++)
{
p=q;
q=q->suivant;
noeudDetruire2(p);
}
free(L);
}


int inserer2 (LISTE1 L, ELEMENT2 e, int pos){
int succee=1;
int i;
NOEUD2 n, p, q;
if (estSaturee2(L)){
printf ("\nListe saturee");
succee=0;}
else {
if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;
}
else {
n=noeudCreer2(e);
if (pos == 1)
{
n->suivant=L->tete;
L->tete = n;
}
else
{
q= L->tete;
for (i=1; i<pos; i++) {
p = q;
q = q->suivant;
}
p->suivant=n;
n->suivant=q;
}
(L->lg)++;
}
}
return succee;
}
int supprimer2 (LISTE1 L, int pos ){

int i;
int succee=1;
NOEUD2 p, q;
if (estVide2(L)) {
printf ("\nListe vide");
succee=0;
}
else {
if ((pos < 1) || (pos > L->lg))
{
printf ("\nPosition invalide");
succee=0;
}
else
{
q = L->tete;
if (pos == 1)
L->tete=L->tete->suivant;
else {
for (i=1; i<pos; i++) {
p = q;
q = q->suivant;
}
p->suivant=q->suivant;
}
}
}
return succee;
}



ELEMENT2 recuperer2(LISTE1 L, int pos) {
ELEMENT2 elt= elementcreer2();
int i;
NOEUD2 p;
if (estVide2(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg))
printf ("\nPosition invalide");

else {

p= L->tete;
for (i=1; i<pos; i++)
p = p->suivant;

elementaffecter2(&elt,p->info);
}

}
return(elt);
}





LISTE1 listeCopier2(LISTE1 L){
LISTE1 LR = listeCreer2();
int i;
ELEMENT2 elt;
for(i = 1;i <= L->lg; i++) {
elt=elementcreer2();
elementcopier2(&elt, recuperer2(L,i));
inserer2(LR,elt, i);
}
return LR;
}



int listeComparer2 (LISTE1 L1,LISTE1 L2 )
{
int test= 1;
int i=1;
if (listeTaille2(L1) != listeTaille2(L2)) test= 0;
while ((i<=listeTaille2(L1)) && (test)) {
if
(elementcomparer2(recuperer2(L1,i),recuperer2(L2,i))!=0)
test=0;
i++;
}
return test;}



void listeAfficher2(LISTE1 L){
int i=1;
NOEUD2 p;
p= L->tete;
for(i = 1;i <= L->lg; i++) {
        printf("phrase %i :",i);
elementafficher2(p->info);
p= p->suivant;
}
}

int estVide2(LISTE1 L) {
return (L->lg == 0);
}

int estSaturee2(LISTE1 L) {
NOEUD2 temp;
int saturee = 1;
temp = (NOEUD2) malloc ( sizeof ( structNoeud2 ) );
if(temp != NULL) {
saturee = 0;
free(temp);
}
return saturee;}


int listeTaille2(LISTE1 L) {
return (L->lg);
}
