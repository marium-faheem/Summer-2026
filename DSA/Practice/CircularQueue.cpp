#include<iostream>
using namespace std;

class CircularQueue{
    private:
    int* arr;
    int capacity;
    int front;
    int rear;

    public:
    CircularQueue(int cap){
        capacity = cap;
        arr = new int [capacity];
        front = -1;
        rear = -1;
    }
    void Enqueue(int value){
        if((rear+1) % capacity == front){
            cout<<"Queue is full."<<endl;
            return;
        }
        if (front == -1){
            front = 0;
        }
        rear = (rear+1)% capacity ;
        arr[rear] = value;
    }

    bool isEmpty(){
        return front == -1;
    }

    void Dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
        }
        else {
            front = (front+1)%capacity;
        }
    }

    bool isFull(){
        return (rear+1)% capacity == front;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        return arr[front];
    }
    int getRear(){
    if(isEmpty()){
        cout<<"Queue is empty."<<endl;
        return -1;
    }
    return arr[rear];
    }
    
    ~CircularQueue(){
        delete[] arr;
    }
};

int main(){
    CircularQueue q(3);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);   // full hona chahiye

    cout << "Front: " << q.peek() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Full? " << q.isFull() << endl;

    q.Dequeue();
    q.Enqueue(40);   // ab wrap hoke index 0 pe jayega

    cout << "Front: " << q.peek() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Full? " << q.isFull() << endl;

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    cout << "Empty? " << q.isEmpty() << endl;

    return 0;
}