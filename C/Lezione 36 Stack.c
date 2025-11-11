//
//  main.c
//  Stack
//
//  Created by Dario Ciuciulla on 11/11/25.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/* Imolementazione Stack con Array
 
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

bool isEmpty(void) {
    return top == -1;
}

bool isFull(void){
    return top == MAX_SIZE - 1;
}
int peek(void){
    if(isEmpty()){
        printf("La Stack è vuota\n");
        return - 1;
    }
    return stack[top];
}
void push(int value){
    if(isFull()){
        printf("Stack Pieno\n");
        return;
    }
    top ++;
    stack[top] = value;
}

int pop(void){
    if(isEmpty()){
        printf("La Stack è vuota\n");
        return - 1;
    }
    int value = stack[top];
    top --;
    return value;
}

int main(void){
    push(1);
    push(2);
    push(3);
    printf("%d\n", peek());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}
*/

//Implementazione Stack con Puntatori

struct StackNode{//Creazione di una struttura per l'implementazione di un nodo della pila
    int data;
    struct StackNode* next;
};
struct Stack{//Struttura per la rappresentazione della pila
    struct StackNode* top;
};
//Funzione per la creazione di un nuovo nodo della pila
struct StackNode* newNode(int data){
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node ->	data = data;
    node -> next = NULL;
    return node;
}
//Funzione per la creazione di una nuova pila vuota
struct Stack* creaStack(void){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack -> top = NULL;
    return stack;
}
//Funzione che controlla se la pila è vuota
int isEmpty(struct Stack* stack){
    return !stack -> top;
}
//Funzione per inserire un elemento nella pila
void push(struct Stack* stack, int data){
    struct StackNode* node = newNode(data);
    node -> next = stack -> top;
    stack -> top = node;
    printf("%d Inserito nella pila\n", data);
}
//Funzione per ri muovere il primo elemento dalla pila
int pop(struct Stack* stack){
    if(isEmpty(stack))
        return -1;
    struct StackNode* temp = stack ->top;
    int popped = temp -> data;
    stack -> top = stack -> top -> next;
    free(temp);
    return popped;
}
//Funzione per recuperare il peek
int peek(struct Stack* stack){
    if (isEmpty(stack))
        return - 1;
    return stack -> top -> data;
}

int main(void){
    struct Stack* stack = creaStack();
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("%d è l'elemento in cima alla pila\n", peek(stack));
    printf("%d è stato rimosso dalla pila\n", pop(stack));
    printf("%d è l'elemento in cima alla pila\n", peek(stack));
    
    return 0;
    
}
