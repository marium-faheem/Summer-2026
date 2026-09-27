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
};

Node* MergeTwoLists(Node* List1, Node* List2){
    if(List1 == nullptr) return List2;
    if(List2 == nullptr) return List1;
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    while (List1 != nullptr && List2 != nullptr)
    {
        if (List1->data <= List2->data){
            tail->next = List1;
            List1 = List1->next;
        }
        else
        {
            tail->next = List2;
            List2 = List2->next;
        }
        tail = tail->next;
    }
    if (List1!=nullptr) tail->next = List1;
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
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeSort(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* mid = findMiddle(head);
    Node* right = mid->next;
    mid->next = nullptr;
    Node* left = head;
    left = mergeSort(left);
    right = mergeSort(right);

    return MergeTwoLists(left, right);
}

int main(){
    Node* list1= new Node(4);
    list1->next = new Node(2);
    list1->next->next = new Node(1);
    list1->next->next->next = new Node(3);
    cout<<"List before mergesort: "<<endl;
    printList(list1);
    Node* sorted = mergeSort(list1);
    cout<<"List after mergesort: "<<endl;
    printList(sorted);

    return 0;
}