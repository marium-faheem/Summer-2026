#include<iostream>
using namespace std;
class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    void Enqueue(int value){
        if (rear==capacity-1) {
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
        return rear==capacity-1;
    }
    ~Queue() {
    delete[] arr;
    }
};
int main() {
    Queue q(3);

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