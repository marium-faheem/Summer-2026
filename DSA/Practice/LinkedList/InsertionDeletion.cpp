#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
    void deleteFromHead(){
        Node* temp;
        if(head == nullptr) {
        return;
    }
    temp = head;
    head = head -> next;
    delete temp;
    }

    void display() {
    Node* temp = head;
    cout<<"HEAD -> ";
    while(temp != nullptr){
    cout<<temp->data; 
    temp = temp->next;
    cout<<" -> ";
    }
    cout<<" NULL";
}
};

int main() {
    LinkedList list;
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(40);
    list.display();   

    return 0;
}