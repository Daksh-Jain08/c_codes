#include<iostream>

using namespace std;


class Node {
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void display();
        int peek(int pos);
};

void Stack::push(int x){
    Node *t = new Node;
    if(!t){
        cout<<"Stack Overflow!!\n";
        return;
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop(){
    int x = -1;
    Node *t = top;
    if(t){
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;        
}

void Stack::display(){
    Node *t = top;
    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

int Stack::peek(int pos){
    Node *t = new Node;
    int x = -1;
    t = top;
    for(int i = 1; t && i < pos; i++)
        t = t->next;
    if(t)
        x = t->data;
    
    return x;
}
