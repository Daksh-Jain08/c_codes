#include"header.h"

void Stack::push(tnode *t){
    node* p = new node;
    if(!p){
        cout<<"Stack overflow!!"<<endl;
        return;
    }
    p->next = head;
    p->ele = t;
    head = p;
}

tnode* Stack::pop(){
    if(isEmpty()){
        cout<<"Stack Underflow!!"<<endl;
        return nullptr;
    }

    tnode* t;
    t = head->ele;
    node *p = head;
    head = p->next;
    free(p);
    return t;
}

bool Stack::isEmpty(){
    return(head==nullptr);
}
