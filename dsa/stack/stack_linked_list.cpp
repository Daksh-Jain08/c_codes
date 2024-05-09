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
        int peek();
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
        free(t);
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

int main(){
    Stack st = Stack();
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout<<st.pop()<<endl;

    st.display();
    return 0;
}