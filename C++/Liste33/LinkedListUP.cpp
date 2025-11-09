//
//  LinkedListUP.cpp
//  Lezione 33 Liste Smart Pointer
//
//  Created by Dario Ciuciulla on 09/11/25.
//

#include "LinkedListUP.h"


LinkedListUP :: LinkedListUP(){
    head = NULL;
}
void LinkedListUP :: insertAtStart(int value){
    auto new_node = make_shared < Node > (value);
    new_node -> next = move(head);
    head = std :: move(new_node);
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
