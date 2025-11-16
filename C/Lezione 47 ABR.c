//
//  main.c
//  Albero Binario di ricerca
//
//  Created by Dario Ciuciulla on 16/11/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

struct nodo{
    int dato;
    struct nodo *sinistra;
    struct nodo *destra;
    struct nodo *genitore;
};

struct nodo* crea_nodo(int dato, struct nodo *genitore){
    struct nodo *nuovo_nodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuovo_nodo -> dato = dato;
    nuovo_nodo -> sinistra = NULL;
    nuovo_nodo -> destra = NULL;
    nuovo_nodo -> genitore = genitore;
    return nuovo_nodo;
}

void inserisci(struct nodo **radice, int dato){
    if(*radice == NULL){
        *radice = crea_nodo(dato, NULL);
    }else{
        struct nodo *temp = *radice;
        if(dato <= temp -> dato){
            if(temp -> sinistra == NULL){
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

void inserisciSinistra(struct nodo *genitore, int valore){
    struct nodo *nuovoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuovoNodo -> dato = valore;
    nuovoNodo -> sinistra = NULL;
    nuovoNodo -> destra = NULL;
    genitore -> sinistra = nuovoNodo;
}

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
//Funzione is BST
bool is_bst(struct nodo* nodo, int limite_inf, int limite_sup){
    if (nodo == NULL) {
        return true;
    }
    if (nodo -> dato <= limite_inf || nodo -> dato >= limite_sup){
        return false;
    }
    return is_bst(nodo -> sinistra, limite_inf, nodo -> dato) &&
           is_bst(nodo -> destra, nodo -> dato, limite_sup);
}

void insert_bst(struct nodo **radice, int valore){
    if (*radice == NULL){
        *radice = (struct nodo*)malloc(sizeof(struct nodo));
        (*radice) -> dato = valore;
        (*radice) -> sinistra = NULL;
        (*radice) -> destra = NULL;
    }else {
        if (valore < (*radice) -> dato){
            insert_bst(&(*radice) -> sinistra, valore);
        }else{
            insert_bst(&(*radice) -> destra, valore);
        }
    }
}

struct nodo* search_bst(struct nodo *radice, int chiave){
    if (radice == NULL || radice -> dato == chiave) {
        return radice;
    }
    if (radice -> dato > chiave) {
        return search_bst(radice -> sinistra, chiave);
    }
        return search_bst(radice -> destra, chiave);
}

struct nodo *minValueNode(struct nodo *nodo){
    struct nodo *current = nodo;
    while (current && current -> sinistra != NULL) {
        current = current -> sinistra;
    }
    return current;
}


struct nodo *delete_bst(struct nodo *radice, int dato){
    if (radice == NULL) {
        return radice;
    }
    if (dato < radice -> dato) {
        radice -> sinistra = delete_bst(radice -> sinistra, dato);
    } else if (dato > radice -> dato) {
        radice -> destra = delete_bst(radice -> destra, dato);
    }else{
        if (radice -> sinistra == NULL) {
            struct nodo *temp = radice -> destra;
            free(radice);
            return temp;
        } else if (radice -> destra == NULL) {
            struct nodo *temp = radice -> sinistra;
            free(radice);
            return temp;
        }
    struct nodo *temp = minValueNode(radice -> destra);
        radice -> dato = temp -> dato;
        radice -> destra = delete_bst(radice -> destra, temp -> dato);
    }
    return radice;
}

int main(void){
    struct nodo *radice = NULL;
    struct nodo *trovato = search_bst(radice, 9);
    bool check = is_bst(radice, INT_MIN, INT_MAX);
    inserisci(&radice, 10);
    inserisciSinistra(radice, 8);
    inserisciDestra(radice, 11);
    inserisciSinistra(radice -> sinistra, 5);
    stampa_albero(radice, 0);
    
    if(check)
        printf("è un BST\n");
    else
        printf("Non è un BST\n");
    //Ricerca
    if(trovato != NULL){
        printf("Elemento trovato: %d\n", trovato -> dato);
    }else{
        printf("Elemento non trovato\n");
    }
    printf("++++++++++++++++++++++++++\n");
    insert_bst(&radice, 12);
    insert_bst(&radice, 9);
    stampa_albero(radice, 0);
    if(check)
        printf("è un BST\n");
    else
        printf("Non è un BST\n");
    //Ricerca
    if(trovato != NULL){
        printf("Elemento trovato: %d\n", trovato -> dato);
    }else{
        printf("Elemento non trovato\n");
    }
}
