//
//  main.cpp
//  Lezione 33 Liste Smart Pointer
//
//  Created by Dario Ciuciulla on 09/11/25.
//

#include <iostream>
#include <memory>
#include "LinkedList.h"
#include "LinkedListUP.h"

using namespace std;

int main (){
    
    //LinkedList* l = new LinkedList();
    /*
    cout << "Inserimento dalla fine" << endl;
    l -> InsertAtEnd(10);
    l -> InsertAtEnd(20);
    l -> InsertAtEnd(30);
    l -> printList();
    delete l;
    cout << endl;
     */
    /*
    cout << "Inserimento dall'inizio" << endl;
    l -> InsertAtStart(10);
    l -> InsertAtStart(20);
    l -> InsertAtStart(30);
    l -> printList();
    cout << endl;
    delete l;
     */
    
    shared_ptr<LinkedListUP> l = make_shared<LinkedListUP>();
    l -> InsertAtEnd(10);
    l -> InsertAtEnd(20);
    l -> InsertAtEnd(30);
    l -> printList();
    
    //Autogestione del delete
}


