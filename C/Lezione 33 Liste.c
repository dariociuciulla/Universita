//
//  main.c
//  Lezione 33 Liste
//
//  Created by Dario Ciuciulla on 09/11/25.
//
//Importazione librerie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Creazione alias per i tipi Char
typedef char element_type;
//Creazione alias della struct "Contenitore" per avere la lettera + posizione
typedef struct list_element {
    //Creazione della variabile value che se usata verrà salvata all'interno della struct list_element
    element_type value;
    //Creazione del puntatore all'interno della struct che chiamiamo next
    struct list_element *next;
    
    //Esempio [ value: 'A' | next ] → [ value: 'B' | next ] → [ value: 'C' | NULL ]  -> sto creando una catena
    
} item; //Chiusura della struct con creazione dell'alias item, cosi invece di scrivere struct list_element nodo, scrivo item nodo

//Creazione del puntatore al primo nodo praticamente dichiaro l'inizio della mia lista
typedef item *list;

bool ricerca_elemento(list l, char value){
    while (l != NULL) {
        if(l -> value == value)
            return true;
        l = l -> next;
        
    }
    return false;
}

//Print iterativa
void showlist(list l){
    printf("[");
    while (l != NULL) {
        putchar(l -> value);
        l = l -> next;
        if (l != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

//Print interna ricorsiva
void showr_list(list l){
    if(l != NULL){
        putchar(l -> value);
        if(l -> next != NULL){
            printf(", ");
            showr_list(l -> next);
        }
    }
}
//Print ricorsiva
void showr_l(list l){
    printf("[");
    showr_list(l);
    printf("]\n");
}

//Funzione Inserisce davanti
void inserisce_davanti(void) {
    printf("Funzione Inserisce davanti\n");
    list root = NULL;
    list aux;
    char n;
    while ((n = getchar()) != '\n') {
        aux = (list)malloc(sizeof(struct list_element));
        aux -> value = n;
        aux -> next = root;
        root = aux;
    }
    showlist(root);
    showr_l(root);
}

//Funzione inserisci che fa un return di list
list inserisce() {
    printf("Funzione Inserisce\n");
    list root = NULL;
    list aux;
    char n;
    while ((n = getchar()) != '\n') {
        aux = (list)malloc(sizeof(struct list_element));
        aux -> value = n;
        aux -> next = root;
        root = aux;
    }
    return root;
}


//Funzione inserice dietro
void inserisce_dietro(void){
    printf("Funzione Inserisce dietro\n");
    list root = NULL;
    list aux = NULL;
    char n;
    while ((n = getchar()) != '\n') {
        if(root == NULL){
            root = (list)malloc(sizeof(struct list_element));
            aux = root;
        } else{
            aux -> next = (list)malloc(sizeof(struct list_element));
            aux = aux -> next;
        }
        aux -> value = n;
        aux -> next = NULL;
    }
    showlist(root);
    showr_l(root);
    
}
int main () {
    list l = inserisce();
    bool ret = ricerca_elemento(l, 'a');
    printf("%s", ret ? "trovato\n" : "Non presente\n");
    
}
