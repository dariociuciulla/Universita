//
//  main.cpp
//  Lezione 27 HeapSort
//
//  Created by Dario Ciuciulla on 09/11/25.
//

#include <iostream>
using namespace std;

//Funzione Heapify
void heapify(int a[], int sx, int dx){
    
    int temp = a[sx];
    int i = sx;
    int j = 2 * i;
    
    while(j <= dx){
        if((j < dx) && (a[j + 1] > a[j]))
            j++;
        if(temp < a[j]){
            a[i] = a[j];
            i = j;
            j = 2 * i;
        } else
            j = dx + 1;
    }
    if (i != sx)
        a[i] = temp;
}

//Funzione HeapSort

void heapsort(int a[], int n){
    int tmp, sx, dx;
    
    //Fase 1: Trasformare l'array in un Heap
    for(sx = n / 2; sx >= 1; sx--){
        heapify(a, sx, n);
    }
    
    //Fase 2: Ordinare l'array mantendo l'organizzazione dell'heap
    for(dx = n; dx > 1; dx--){
        tmp = a[1];
        a[1] = a[dx];
        a[dx] = tmp;
        heapify(a, 1, dx - 1);
    }
}

int main(){
    int a[]={0, 42, 38, 11, 75, 99, 23, 84, 67};
    int n = 8;
    heapsort(a, n);
    for (int i = 1; i < n + 1; i++)
        cout<< a[i]<<" ";
}
