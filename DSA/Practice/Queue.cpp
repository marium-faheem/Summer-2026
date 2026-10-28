#include<iostream>
using namespace std;
class Queue {
private:
    int arr[5];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }
    void Enqueue(int value){
        if (rear==4) {
            cout<<"Queue at capacity."<<endl;
            return;
        }
        rear++;
        arr[rear] = value;
    }
    void Dequeue(){
        if (front>rear)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        front++;
    }
    int getFront(){
        if(front>rear){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(front>rear){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty(){
        return front>rear;
    }
    bool isFull(){
        return rear==4;
    }
};
int main() {
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.Dequeue();

    cout << "Front after dequeue: " << q.getFront() << endl;

    cout << "Is queue empty? " << q.isEmpty() << endl;
    cout << "Is queue full? " << q.isFull() << endl;

    return 0;
}