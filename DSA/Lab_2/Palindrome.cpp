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
Node* ReverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr!=nullptr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;   
    }
    Node* mid = findMiddle(head);
    Node* secondHalf = ReverseList(mid->next);
    Node* p1 = head;
    Node* p2 = secondHalf;
    while (p2 != nullptr) {
        if (p1->data != p2->data) {
            return false;   
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;   
}
int main() {
    // Test 1: Palindrome list
    Node* List1 = new Node(1);
    List1->next = new Node(2);
    List1->next->next = new Node(2);
    List1->next->next->next = new Node(1);

    cout << "List1 is palindrome: " << (isPalindrome(List1) ? "true" : "false") << endl;

    // Test 2: Non-palindrome list
    Node* List2 = new Node(1);
    List2->next = new Node(2);
    List2->next->next = new Node(3);
    List2->next->next->next = new Node(4);

    cout << "List2 is palindrome: " << (isPalindrome(List2) ? "true" : "false") << endl;

    return 0;
}