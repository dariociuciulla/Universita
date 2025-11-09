//
//  main.cpp
//  Lezione 19
//
//  Created by Dario Ciuciulla on 23/10/25.
//
//Visita ARRAY
/*
#include <iostream>
using namespace std;

void do_something(int element){
    cout<<element<<" ";
}

void visit_array(int a[], int n){
    for(int i = 0; i < n; i++){
        do_something(a[i]);
    }
    cout<<endl;
}

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    visit_array(a, 10);
}
*/

//Ricerca Lineare array

#include <iostream>
using namespace std;
int ricerca_lineare(int a[], int n, int valore){
    for(int i = 0; i<n; i++){
        if(a[i]==valore)
            return i;
    }
    return -1;
}
int ricerca_binaria_non_ricorsiva(int a[], int n, int valore){
    int sx=0;
    int dx= n-1;
    int mx=(sx+dx)/2;
    while (sx!=dx){
        if(a[mx]==valore)
            return mx;
        if(a[mx]<valore)
            sx=mx+1;
        
        else
            dx=mx-1;
            mx=(sx+dx)/2;
    }
    return (a[mx]==valore)?mx:-1;
}

int main(){
    int a[11]={11,12,13,14,15,16,17,18,19,20,21};
    int n=11;
    int valore= 16;
    cout<<ricerca_binaria_non_ricorsiva(a,n,valore)<<endl;
}
