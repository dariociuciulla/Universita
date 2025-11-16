//
//  main.c
//  Albero Binario
//
//  Created by Dario Ciuciulla on 16/11/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

//Creazione della struttura dell'albero binario
/*
            (root)
            /    \
         (L)      (R)
         / \      / \
      (LL) (LR)(RL) (RR)
 */

struct nodo{
    int dato;
    struct nodo *sinistra;
    struct nodo *destra;
    struct nodo *genitore;
};

//Funzione crea nodo
struct nodo* crea_nodo (int dato, struct nodo *genitore){
    struct nodo *nuovo_nodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuovo_nodo -> dato = dato;
    nuovo_nodo -> sinistra = NULL;
    nuovo_nodo -> destra = NULL;
    nuovo_nodo -> genitore = genitore;
    return nuovo_nodo;
}

//Funzione inserisci elementi
void inserisci(struct nodo **radice, int dato){
    if(*radice == NULL){
        *radice = crea_nodo(dato, NULL);
    }else {
        struct nodo *temp = *radice;
        if(dato <= temp -> dato){
            if(temp -> sinistra == NULL ){
                temp -> sinistra = crea_nodo(dato, temp);
            }else{
                inserisci(&temp -> sinistra, dato);
            }
        }else{
            if(temp -> destra == NULL){
                temp -> destra = crea_nodo(dato, temp);
            }else{
                inserisci(&temp -> destra, dato);
            }
        }
    }
}

//Fuonzione inserimento a sinistra
void inserisciSinistra(struct nodo *genitore, int valore){
    struct nodo *nuovoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuovoNodo -> dato = valore;
    nuovoNodo -> sinistra = NULL;
    nuovoNodo -> destra = NULL;
    genitore -> sinistra = nuovoNodo;
}

//Funzione inserisci a destra
void inserisciDestra(struct nodo *genitore, int valore){
    struct nodo *nuovoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuovoNodo -> dato = valore;
    nuovoNodo -> sinistra = NULL;
    nuovoNodo -> destra = NULL;
    genitore -> destra = nuovoNodo;
}

//Vista in Pre Order
void preOrder(struct nodo *radice){
    if(radice == NULL)
        return;
    printf("%d ", radice -> dato);
    preOrder(radice -> sinistra);
    preOrder(radice -> destra);
}

//Vista inOrder
void inOrder(struct nodo *radice){
    if(radice == NULL)
        return;
    inOrder(radice -> sinistra);
    printf("%d ", radice -> dato);
    inOrder(radice -> destra);
}

//Vista postOrder
void postOrder(struct nodo *radice){
    if(radice == NULL)
        return;
    postOrder(radice -> sinistra);
    postOrder(radice -> destra);
    printf("%d ", radice -> dato);
}

//Funzione conta nodi
int contaNodi(struct nodo * radice){
    if(radice == NULL)
        return 0;
    else{
        int C1 = contaNodi(radice -> sinistra);
        int C2 = contaNodi(radice -> destra);
        return C1 + C2 + 1;
    }
}
//Funzione stampa_albero
void stampa_albero(struct nodo *radice, int spazio) {
    if (radice == NULL)
        return;
    spazio += 10;
    stampa_albero(radice -> destra, spazio);
    for(int i=10; i<spazio; i++)
        printf(" ");
    printf("%d\n", radice->dato);
    stampa_albero(radice -> sinistra, spazio);
}
//Funzione stampa_albero_grafico
void stampa_albero_grafico(struct nodo *radice, int livello){
    if (radice == NULL)
        return;
    printf("%*s%d\n", livello * 2, "", radice->dato);
    if (radice->sinistra != NULL) {
        for (int j = 0; j <= livello * 2; j++) {
            printf(" ");
        }
        printf("|--"); stampa_albero_grafico(radice -> sinistra, livello + 1);
    }
    if (radice -> destra != NULL) {
        for (int j = 0; j <= livello * 2; j++) {
            printf(" ");
        }
        printf("|--"); stampa_albero_grafico(radice -> destra, livello + 1);
    }
}
//Funzione BFS
void BFS (struct nodo *radice){
    if(radice == NULL)
        return;
    
    struct nodo *coda[100];
    int front = 0;
    int rear = 0;
    coda[rear ++] = radice;
    
    while(front != rear){
        struct nodo *temp = coda[front ++];
        printf("%d ", temp -> dato);
        if(temp -> sinistra != NULL)
            coda[rear ++] = temp -> sinistra;
        if(temp -> destra != NULL)
            coda[rear ++] = temp -> destra;
    }
}

//main
int main(void){
    /*Stampa_albero
    struct nodo *radice = NULL;
    inserisci(&radice, 5);
    inserisci(&radice, 3);
    inserisci(&radice, 8);
    inserisci(&radice, 1);
    inserisci(&radice, 4);
    inserisci(&radice, 6);
    inserisci(&radice, 9);
    stampa_albero(radice, 0);
    printf("\n");
     */
    struct nodo *radice = NULL;
    inserisci(&radice, 1);
    inserisciSinistra(radice, 10);
    inserisciDestra(radice, 11);
    inserisciSinistra(radice -> sinistra, 100);
    inserisciDestra(radice -> sinistra, 101);
    inserisciSinistra(radice -> destra, 110);
    inserisciDestra(radice -> destra, 111);
    inserisciSinistra(radice -> sinistra -> sinistra, 1000);
    inserisciDestra(radice -> sinistra -> sinistra, 1001);
    inserisciSinistra(radice -> sinistra -> destra, 1001);
    inserisciDestra(radice -> destra -> sinistra, 1110);
    inserisciDestra(radice -> destra -> destra, 1111);
    printf("Stampa ALbero: \n");
    stampa_albero(radice, 0);
    printf("\n");
    printf("Stampa ALbero Grafico: \n");
    stampa_albero_grafico(radice, 0);
    printf("\n");
    printf("Stampa ALbero In order: \n");
    inOrder(radice);
    printf("\n");
    printf("Stampa ALbero Pre order: \n");
    preOrder(radice);
    printf("\n");
    printf("Stampa ALbero Post order: \n");
    postOrder(radice);
    printf("\n");
    printf("Stampa ALbero BFS: \n");
    BFS(radice);
    printf("\n");
    printf("Conta nodi: \n");
    printf("I nodi sono: %d  \n", contaNodi(radice));
}
