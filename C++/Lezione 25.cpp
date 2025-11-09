//
//  main.cpp
//  Lezione 25 QuikSort
//
//  Created by Dario Ciuciulla on 04/11/25.
//

#include <iostream>
using namespace std;

void quicksort(int a[], int sx, int dx){
    int i = sx;
    int j = dx;
    int pivot = a[(sx + dx) / 2];
    
    //Inizio della funzione che mi ordina l'array
    
    while (i<=j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j){
            if (i<j){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            i++;
            j--;
        }
    }
    if (sx < j)
        quicksort(a, sx, j);
    if (i < dx)
        quicksort(a, i, dx);
}

int main(){
    int a[8] = {22, 56, 87, 12, 89, 76, 90, 32};
    int i = 0;
    int j = 7;
    
    quicksort(a, i, j);
    
    for (int i = 0; i<=7; i++)
        cout<<a[i]<<" ";
}
