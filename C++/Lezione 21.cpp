//
//  main.cpp
//  Lezione 21
//
//  Created by Dario Ciuciulla on 27/10/25.
// Selection Sort
//Decrescente
/*
#include <iostream>
using namespace std;

int a[8]= {41, 37, 10, 74, 98, 22, 83, 66};
int n=8;
int main(){
    
    for(int i=(n-1); i>=0; i--){
        int max = i;
        for(int j=i-1; j>=0; j--){
            if(a[j]>a[max])
                max=j;
        }
        if(max!=i){
            int temp = a[i];
            a[i]=a[max];
            a[max]=temp;
        }
        cout<<a[i]<<" ";
    }
    
   
}
*/
//Crescente

#include <iostream>
using namespace std;

int a[8]= {41, 37, 10, 74, 98, 22, 83, 66};

int main(){
    
    for(int i=0; i<7; i++){
        int min = i;
        for(int j=i+1; j<7; j++){
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i){
            int temp = a[i];
            a[i]=a[min];
            a[min]=temp;
        }
        cout<<a[i]<<" ";
    }
    
   
}
