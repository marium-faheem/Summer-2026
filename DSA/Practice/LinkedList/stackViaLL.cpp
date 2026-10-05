#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Stack{
    public:
    Node* top = nullptr;

    bool isEmpty(){
        return top == nullptr;
    }
    void push(int x){
        Node* n = new Node(x);
        n->next = top;
        top = n;
    }
    int pop(){
        if(isEmpty()) return -1;      // underflow
        int x = top->data;
        Node* t = top;
        top = top->next;
        delete t;
        return x;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return -1;
        }
        return top->data;
    }
    void display(){
        Node* curr = top;
        while(curr != nullptr){       // fix 1: check curr itself
            cout<<curr->data<<endl;
            curr = curr->next;        // fix 2: move to the next node
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();                      // 30 20 10
    cout<<"peek: "<<s.peek()<<endl;   // 30

    cout<<"pop: "<<s.pop()<<endl;     // 30
    cout<<"pop: "<<s.pop()<<endl;     // 20
    s.display();                      // 10

    s.pop();                          // removes 10, stack empty
    cout<<"pop on empty: "<<s.pop()<<endl;  // -1 (underflow)
    return 0;
}