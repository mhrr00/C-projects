#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "ELTPRIM.h"
#include "ELTPRIM1.h"
#include "ELTPRIM2.h"
#include "ELTINT.h"
#include "ELTINT1.h"

void filetolist(LISTE L,int N);
int isprime(int num);
void AsciiTophrase(ELEMENT phrase, ELEMENT2 result);
int modulo(int x, int p, int n);
int* chiffrement_dechiff(ELEMENT1 e1, int tableau_achiffrer[], int taille_tab);
void tab_prim(int tableau[100]);
void pile_p_p(Pile pilePublic, Pile pilePrivee, ELEMENT1 e1, int N, int n, int phi);
void piles(int tableau[100], int N, Pile pilePublic, Pile pilePrivee) ;
void crypt_dcrypt(LISTE L,LISTE L2, LISTE1 LL, LISTE1 LL1, Pile pilePublic, Pile pilePrivee, int N);
int taille_file();
int main(){
    int N,x=0;
    int tableau[100];
    Pile pilePrivee=PileCreer();
    Pile pilePublic=PileCreer();
    int size = taille_file();
    printf("\n");
    printf("donner le nombre de phrase a chiffrer N =");
    scanf("%d",&N);
       HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Enregistrez la couleur actuelle
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD savedAttributes = consoleInfo.wAttributes;
    while(N<1 || N>size){
        printf("N compris entre  1 et %d svp:",size);
        scanf("%d",&N);
    }
    srand(time(NULL));
    tab_prim(tableau);
    LISTE L,L2;
    LISTE1 LL,LL1;
    L=listeCreer();L2=listeCreer();LL=listeCreer2();LL1=listeCreer2();
    filetolist(L,N);
    piles(tableau,N,pilePublic,pilePrivee);
    //PileAfficher(pilePrivee);
    crypt_dcrypt(L, L2,LL, LL1, pilePublic, pilePrivee, N);
    //asc_to_phrase(L1,LL1,N);
    //affichage
    system("cls");
    printf("\nles %i phrases a envoyer sont:\n\n\n",N);
    listeAfficher(L);


    system("pause");
        system("cls");
    printf("les phrases apres leur ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("chiffrement :\n\n\n");
    SetConsoleTextAttribute(hConsole, savedAttributes);
    listeAfficher2(LL);


    system("pause");
    system("cls");
    printf("les phrases apres  ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf(" le dechiffrement :\n\n\n");
    SetConsoleTextAttribute(hConsole, savedAttributes);

    listeAfficher2(LL1);

    system("pause");
    system("cls");
     printf("\nles phrases arrivees :\n\n\n");
    listeAfficher(L2);
    printf("\n");
    return 0;
}


void filetolist(LISTE L, int N) {
    FILE *file;
    char phrase[40];

    file=fopen("ftext.txt","r");
    if(file==NULL)
        printf("error!!");
    int i;
    for(i=1;i<=N;i++) {
        fgets(phrase,40,file);
        ELEMENT e=elementcreer();
        strcpy(e, phrase);
        inserer(L,e,i);
    }
    fclose(file);
}
void phraseToAscii(char *phrase, int *result) {
    for (int i = 0; i < strlen(phrase); i++) {
        result[i] = (int)phrase[i];
    }
}
void AsciiTophrase(ELEMENT phrase, ELEMENT2 result) {
    for(int i=0;result->crypt[i]!=0;i++) {
       phrase[i]=result->crypt[i];
    }
}
int modulo(int x, int p, int n) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result = (result * x) % n;
    }
    return result;
}



int isprime(int num) {
    int test=1;
    if (num <= 1) test=0;
    else if (num <= 3) test=1;
    else if (num % 2 == 0 || num % 3 == 0) test=0;
    else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) test=0;
        }
    }
    return test;
}

void tab_prim(int tableau[100]) {
    int nombres_generer=0;
    int i=0;
    int taille_tableau=10,isdistinct,randomNumber;
    while (nombres_generer<taille_tableau) {
        do {
            randomNumber = rand() % 200;
        } while (randomNumber  < 19);

        if (isprime(randomNumber)) {
            isdistinct=1;
            for(i=0;i<nombres_generer;i++) {
                if(tableau[i]==randomNumber)
                    isdistinct=0;
            }
            if(isdistinct==1)
                tableau[nombres_generer++]=randomNumber;
        }
    }
}

int* chiffrement_dechiff(ELEMENT1 e1, int tableau_achiffrer[], int taille_tab) {
    int* tableau_chiffrer = (int*)malloc(taille_tab * sizeof(int));
    if (tableau_chiffrer == NULL) {
        return NULL;
    }
    for (int i = 0; i < taille_tab; i++)
        tableau_chiffrer[i] = modulo(tableau_achiffrer[i], e1.d, e1.n);

    return tableau_chiffrer;
}

void pile_p_p(Pile pilePublic, Pile pilePrivee, ELEMENT1 e1, int N, int n, int phi) {
    int i,e0,d;
    e0=0;
    i=2;
    while (i<phi && e0==0) {
        if (isprime(i)&&phi%i!=0) {
            e0=i;
        }
        i++;
    }

    i=1;
    d=0;
    while (i<phi && d==0) {
        if ((i*e0)%phi==1)
            d=i;
        i++;
    }
    e1.n=n;
    e1.d=d;
    Empiler(pilePrivee,e1);
    e1.d=e0;
    Empiler(pilePublic,e1);
}

void piles(int tableau[100], int N, Pile pilePublic, Pile pilePrivee) {
    int randomNumber1,randomNumber2,phi,n,j;
    j=0;
    while(j<N) {
        ELEMENT1 e1=elementCreer1();
        do {
            randomNumber1=rand()%10;
            randomNumber2=rand()%10;
        } while(randomNumber1==randomNumber2);
        n=tableau[randomNumber1]*tableau[randomNumber2];
        phi=(tableau[randomNumber1]-1)*(tableau[randomNumber2]-1);
        pile_p_p(pilePublic,pilePrivee,e1,N,n,phi);
        j++;
    }
}
void crypt_dcrypt(LISTE L,LISTE L2, LISTE1 LL, LISTE1 LL1, Pile pilePublic, Pile pilePrivee, int N) {
    int j = 0,taille;
    while (j < N) {
        ELEMENT e = elementcreer();
        ELEMENT e3 = elementcreer();
        e = recuperer(L, j + 1);
        ELEMENT2 e2 = elementcreer2();
        ELEMENT2 e21 = elementcreer2();
        ELEMENT1 e11 = elementCreer1();
        ELEMENT1 e12 = elementCreer1();
        int t;
        int res[100];
        phraseToAscii(e, res);
        e11 = ((pilePublic->tete)->info);
        int *ress = chiffrement_dechiff(e11, res, strlen(e));
        Depiler(pilePublic);
        for (t = 0; t < strlen(e)-1; t++) {
            (e2->crypt)[t] = ress[t];
        }
        inserer2(LL, e2, j + 1);
        e12 = ((pilePrivee->tete)->info);
        ress = chiffrement_dechiff(e12, e2->crypt, strlen(e));
        Depiler(pilePrivee);
        for (t = 0; t < strlen(e)-1; t++) {
            e21->crypt[t] = ress[t];
        }
        inserer2(LL1, e21, j + 1);
        AsciiTophrase(e3,e21 );
        inserer(L2, e3, j + 1);
        j++;
    }
}
int taille_file() {
    FILE *file;
    int x = 0;
    char phrase[500];
    file = fopen("ftext.txt", "r");
    if(file == NULL) {
        printf("Error \n");
        return -1;
    }
    while(fgets(phrase, 500, file) != NULL) {
        x++;
    }
    fclose(file);
    return x;
}
