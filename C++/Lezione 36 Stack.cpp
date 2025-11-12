//
//  main.cpp
//  Stack Raw Pointer
//
//  Created by Dario Ciuciulla on 11/11/25.
//
# include <iostream>
#include <stack>
#include <memory>
using namespace std;

/* Versione con raw pointer
 
class Stack{
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* top;
    
public:
    Stack(){top = nullptr;}
    
    void push(int value){
        Node* new_node = new Node;
        new_node -> data = value;
        new_node -> next = top;
        top = new_node;
    }
    
    int pop(){
        if (top == nullptr) {
            cout << "Pila vuota, impossibile rimuovere elementi.\n";
            return -1;
        }
        int value = top ->data;
        Node* temp = top;
        top = top -> next;
        delete temp;
        return value;
    }
    
    int peek(){
        if (top == nullptr) {
            cout << "Pila vuota, impossibile rimuovere elementi.\n";
            return -1;
        }
        return top -> data;
    }
};

int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    cout << "Il Peek è: "<< stack.peek() << endl;
    cout << "La stack è: " << endl;
    cout << stack.pop() << ", ";
    cout << stack.pop() << ", ";
    cout << stack.pop() << endl;
    
    return 0;
}
*/

//Versione con Smart Pointer

template <typename T>

class StackWithVisit {
public:
    StackWithVisit(){}
    
    void push(const T & value){
        stack_.push(make_shared <T> (value));
    }
    void pop(){
        if(stack_.empty()){
            return;
        }
        stack_.pop();
    }
    
    bool empty() const{
        return stack_.empty();
    }
    void visit(void(*visitor)(const T &))const{
        stack<shared_ptr<T>> temp_stack = stack_;
        while(!temp_stack.empty()){
            visitor(*temp_stack.top());
            temp_stack.pop();
        }
    }
private:
    stack <shared_ptr<T>> stack_;
};

void print(const int &value){
    cout << value << endl;
}

int main(){
    StackWithVisit<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.visit(print);
    stack.pop();
    stack.pop();
    stack.visit(print);
    stack.pop();
    stack.visit(print);
    return 0;
}

