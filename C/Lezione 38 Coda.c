//
//  main.c
//  Coda
//
//  Created by Dario Ciuciulla on 13/11/25.
//

#include <stdio.h>
#include <stdlib.h>
#define DIM_MAX 10

int StrutturaCoda[DIM_MAX];
int testa = 0;
int coda = -1;
int contatore = 0;

void enqueue(int dato){
    if(contatore == DIM_MAX){
        printf("Errore: Coda Piena");
    }else{
        coda = (coda + 1) % DIM_MAX; //Coda circolare
        StrutturaCoda[coda] = dato;
        contatore ++;
    }
}

int dequeue(void){
    if(contatore == 0){
        printf("Errore: Coda Vuota");
        return -1;
    }else{
        int dato = StrutturaCoda[testa];
        testa = (testa + 1) % DIM_MAX;
        contatore --;
        return dato;
    }
}

void stampa_coda(void){
    if(contatore == 0){
        printf("Errore: Coda vuota");
    }else{
        for(int i = 0; i < contatore; i++){
            int indice = (testa + i) % DIM_MAX;
            printf("%d\n", StrutturaCoda[indice]);
        }
    }
}

int main(void){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("La coda è: \n");
    stampa_coda();
    dequeue();
    printf("La coda è: \n");
    stampa_coda();
    dequeue();
    printf("La coda è: \n");
    stampa_coda();	
    
}
