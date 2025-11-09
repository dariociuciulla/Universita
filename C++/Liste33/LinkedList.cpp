//
//  LinkedList.cpp
//  Lezione 33 Liste Smart Pointer
//
//  Created by Dario Ciuciulla on 09/11/25.
//
#include <iostream>
#include "LinkedList.h"

LinkedList :: LinkedList(){
    head = NULL;
    tail = NULL;
}

LinkedList :: ~LinkedList(){
    Node* current = head;
    while(current != NULL){
        Node* next = current -> next;
        delete current;
        current = next;
    }
}

void LinkedList :: InsertAtStart(int value){
    Node* newNode = new Node();
    newNode -> data = value;
    newNode -> next = head;
    head = newNode;
    
    if(tail == NULL){
        tail = head;
    }
}

void LinkedList :: InsertAtEnd(int value){
    Node* newNode = new Node();
    newNode -> data = value;
    newNode -> next = NULL;
    
    if(tail == NULL){
        head = tail = newNode;
        return;
    }
}

void LinkedList :: deleteFromStart(){
    if(head == NULL){
        return;;
    }
    Node* temp = head;
    head = head -> next;
    delete temp;
}

void LinkedList :: deleteFromEnd(){
    if(tail == NULL){
        return;;
    }
    if(head == tail){
        delete head;
        head = tail = NULL;
        return;
    }
    Node* current = head;
    while (current -> next != tail) {
        current = current -> next;
    }
    delete tail;
    tail = current;
    tail -> next = NULL;
}

void LinkedList :: deleteNode(int value){
    Node* current = head;
    Node* previous = NULL;
    
    if(current != NULL && current -> data == value){
        head = current -> next;
        delete current;
        return;
    }
    while(current != NULL && current -> data != value){
        previous = current;
        current = current -> next;
    }
    if(current == NULL){
        return;
    }
    previous -> next = current -> next;
    
    if(current == tail){
        tail = previous;
    }
    delete current;
}

void LinkedList :: printList(){
    Node* current = head;
    while(current != NULL){
        std :: cout << current -> data << " ";
        current = current ->next;
    }
}
