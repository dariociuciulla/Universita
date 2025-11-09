//
//  main.cpp
//  Lezione 23 BubbleSort
//
//  Created by Dario Ciuciulla on 03/11/25.
//

#include <iostream>
using namespace std;

int main (){
    //Dichiarazione dell'array e della variabile che indica il numero di elementi dell'array
    int a[8]={41, 37, 10, 74, 98, 22, 83, 66};
    int n=8;
    bool scambio = true;
  
    
    while (scambio){
        scambio = false;
        for(int i=0; i<=n-2; i++){
            if(a[i] > a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1] = temp;
                scambio=true;
            }
        }
    }
    
    for(int i=0; i<n;i++)
        cout<<a[i]<<" ";
     
}
