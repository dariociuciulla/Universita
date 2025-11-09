//
//  LinkedListUP.cpp
//  Lezione 33 Liste Smart Pointer
//
//  Created by Dario Ciuciulla on 09/11/25.
//
#include <iostream>
#include "LinkedListUP.h"


LinkedListUP :: LinkedListUP(){
    head = NULL;
}

void LinkedListUP :: InsertAtStart(int value){
    auto new_node = make_shared < Node > (value);
    new_node -> next = std::move(head);
    head = std::move(new_node);
}
void LinkedListUP :: InsertAtEnd(int value){
    if(!head){
        head = make_shared < Node > (value);
    }else{
        auto current = head.get();
        while(current -> next){
            current = current -> next.get();
        }
        current -> next = make_shared < Node > (value);
    }
}

void LinkedListUP::deleteNode(int value){
    if (!head) {
        return;
    }
    
    if(head -> data == value){
        head = std::move(head -> next);
        return;
    }
    auto current = head.get();
    while(current -> next && current -> next -> data != value){
        current = current -> next.get();
    }
    if (current -> next){
        current -> next  = std::move(current -> next -> next);
    }
}

void LinkedListUP::printList(){
    if (!head) {
        cout << "Lista vuota" << endl;
        return;
    }
    auto curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

