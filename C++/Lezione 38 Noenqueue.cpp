//
//  main.cpp
//  CodaSenzaLibreriaQueue
//
//  Created by Dario Ciuciulla on 13/11/25.
//

#include <iostream>

using namespace std;

const int DIM_MAX = 10;

class CodaCircolare{
private:
    int* buffer;
    int testa;
    int coda;
    
public:
    CodaCircolare(){
        testa = coda = -1;
        buffer = new int [DIM_MAX];
    }
    ~CodaCircolare(){
        delete[] buffer;
    }
    int elementoIniziale(){
        if(testa == -1){
            cout << "Coda vuota, impossibile rimuovere elementi!" << endl;
            return -1;
        }
        return buffer[testa];
    }
    
    int elementoFinale(){
        if((coda + 1) % DIM_MAX == testa){
            cout << "Coda piena, impossibile inserire elementi!" << endl;
            return +1;
        }
        return buffer[coda];
    }
    
    void enqueue(int valore){
        if((coda + 1) % DIM_MAX == testa){
            cout << "Coda piena, impossibile inserire elementi!" << endl;
            return;
        }
        coda = (coda +1) % DIM_MAX;
        buffer[coda] = valore;
        
        if(testa == -1){
            testa = coda;
        }
    }
    
    int dequeue (){
        if(testa == -1){
            cout << "Coda vuota, impossibile rimuovere elementi!" << endl;
            return -1;
        }
        int valore = buffer[testa];
        if(testa == coda){
            testa = coda = -1;
        }else{
            testa = (testa + 1) % DIM_MAX;
        }
        return valore;
    }
};

int main(){
    CodaCircolare coda;
    
    coda.enqueue(10);
    coda.enqueue(20);
    coda.enqueue(30);
    
    cout << "Elemento rimosso: " << coda.dequeue() << endl;
    cout << "Elemento in testa: " << coda.elementoIniziale() << endl;
    cout << "Elemento in coda: " << coda.elementoFinale() << endl;
    cout << "Elemento rimosso: " << coda.dequeue() << endl;
    cout << "Elemento rimosso: " << coda.dequeue() << endl;
    
    
}
    
    

