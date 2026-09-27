//merging two sorted lists
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        head = nullptr;
    }
    void insert(int data){
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
        }
        else{
            Node* temp = head;
            while (temp->next != nullptr)
            {
               temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display(){
        Node* temp = head;
        while(temp != nullptr) {
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<" NULL" <<endl;
    }
};

Node* MergeTwoLists(Node* List1, Node* List2){
    if(List1 == nullptr) return List2;
    if(List2 == nullptr) return List1;
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    while(List1 != nullptr && List2 != nullptr){
       if(List1->data <= List2->data){
        tail->next = List1;
        List1 = List1->next;
        }
        else{
            tail->next = List2;
            List2 = List2->next;
        }
        tail = tail->next;
    }
    if (List1 != nullptr) tail->next = List1;
    else tail->next = List2;
    return dummy->next;
}
void printList(Node* head){
    Node* temp = head;
    cout<<"HEAD -> ";
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
        cout<<" -> ";
    }
    cout<<"NULL";
}

int main(){
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(4);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);
    list2->next->next->next = new Node(5);

    Node* merged = MergeTwoLists(list1, list2);
    printList(merged);

    return 0;
}