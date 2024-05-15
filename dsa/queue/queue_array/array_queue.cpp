#include<iostream>

using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *arr;
    public:
        Queue(){front=rear=-1; size=10; arr = new int[size];}
        Queue(int size){front=rear=-1; this->size=10; arr = new int[this->size];}
        void enqueue(int ele);
        int dequeue();
        void Display();
};

void Queue::enqueue(int ele){
    if(rear==size-1)
        cout<<"Queue Overflow\n";
    else
        arr[++rear] = ele;
}

int Queue::dequeue(){
    int ele = -1;

    if(front==rear)
        cout<<"Stack Underflow: ";
    else
        ele = arr[++front];
    
    return ele;
}

void Queue::Display(){
    for(int i = front+1; i<=rear; i++)
        cout<< arr[i] << ",";
    cout<<endl;
}

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.Display();

    cout<<q.dequeue();

    return 0;
}