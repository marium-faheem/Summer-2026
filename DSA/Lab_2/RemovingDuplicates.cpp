//Removing duplicates from a sorted LinkedList
#include<iostream>
using namespace std;

class Node {
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

    void removeDuplicates(){
        if(head == nullptr || head->next == nullptr){
            return;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr) {
                if(temp->data == temp->next->data){
                    Node* duplicate = temp->next;
                    temp->next = temp->next->next;
                    delete duplicate;
                }
                else{
                    temp = temp->next;
                }
            }
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
int main(){
    LinkedList list;
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(3);
    cout<<"List before: "<<endl;
    list.display();          // before
    list.removeDuplicates();
    cout<<"List after: "<<endl;
    list.display();          // after
    return 0;
}