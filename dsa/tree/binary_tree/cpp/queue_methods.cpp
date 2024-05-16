#include<iostream>
#include"header.h"

void Queue::enqueue(tnode *ele){
    node *t = new node;
    if(t==nullptr){
        cout<<"Queue Overflow!!"<<endl;
        return;
    }

    t->ele = ele;
    t->next = nullptr;
    
    if(isEmpty())
        front = rear = t;

    else{
        rear->next = t;
        rear = t;
    }
}

tnode * Queue::dequeue(){
    tnode *x = nullptr;
    if(isEmpty()){
        cout<<"Queue Underflow!!"<<endl;
        return x;
    }
    
    node *t = front;
    front = t->next;
    x = t->ele;
    delete(t);

    return x;
}

bool Queue::isEmpty(){
    if(front==nullptr)
        return true;
    else
        return false;
}