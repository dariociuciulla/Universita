//
//  LinkedList.h
//  Lezione 33 Liste Smart Pointer
//
//  Created by Dario Ciuciulla on 09/11/25.
//

#ifndef LINKED_LIST
#define LINKED_LIST

class LinkedList{
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
    
public:
    LinkedList();
    ~LinkedList();
    
    void InsertAtStart(int value);
    void InsertAtEnd(int value);
    void deleteFromStart();
    void deleteFromEnd();
    void deleteNode(int value);
    void printList();
};

#endif /* LinkedList_h */
