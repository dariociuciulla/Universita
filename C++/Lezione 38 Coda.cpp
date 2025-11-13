//
//  main.cpp
//  Coda
//
//  Created by Dario Ciuciulla on 13/11/25.
//

#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
 Metodi classe queue:
 • void push(const T& x): Inserisce un elemento x in coda alla coda.
 • void pop(): Rimuove l'elemento in testa alla coda.
 • T& front(): Restituisce un riferimento all'elemento in testa alla coda.
 • const T& front() const: Restituisce un riferimento costante all'elemento in testa alla coda.
 • T& back(): Restituisce un riferimento all'elemento in coda alla coda.
 • const T& back() const: Restituisce un riferimento costante all'elemento in coda alla coda.
 • bool empty() const: Restituisce vero se la coda è vuota, falso altrimenti.
 • size_t size() const: Restituisce la dimensione della coda.
 */

int main(){
    queue<int>coda;//Creazione della coda
    
    coda.push(1);
    coda.push(2);
    coda.push(3);
    cout << "Gli elementi presenti nella coda sono: " << coda.size() << endl;
    
    while(!coda.empty()){
        int testa = coda.front();
        cout << testa << endl;
        coda.pop();//Da fare il pop per rimuovere l'elemento e poterlo vedere
        
    }
}
