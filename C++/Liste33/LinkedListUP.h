//
//  LinkedListUP.h
//  Lezione 33 Liste Smart Pointer
//
//  Created by Dario Ciuciulla on 09/11/25.
//

#ifndef LINKED_LIST_UP
#define LINKED_LIST_UP

#include <memory>

using namespace std;

class LinkedListUP{
private:
    struct Node{
        int data;
        shared_ptr < Node > next;
        Node(int data) : data(data), next(nullptr){}
        Node(int data, shared_ptr < Node > next):
        data(data), next(std :: move(next)){}
    };
    shared_ptr<Node> head;
    
public:
    LinkedListUP();
    
    void InsertAtStart(int value);
    void InsertAtEnd(int value);
    void deleteNode(int value);
    void printList();
};

#endif /* LinkedListUP_h */
