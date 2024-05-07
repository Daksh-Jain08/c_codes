#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

typedef struct Stack{
    node* top;
} stack;

void create(stack *st){
    node *t = NULL;
    st->top = t;
}

void display(stack st){
    node *t = st.top;
    while(t){
        printf("%d, ", t->data);
        t = t->next;
    }
    printf("\n");
}

void push(stack *st, int data){
    node* t = (node *)malloc(sizeof(node));
    if(t==NULL){                                     //no more space available in heap
        printf("Stack Overflow!!\n");
        return;
    }
    t->data = data;
    t->next = st->top;
    st->top = t;
}

int pop(stack *st){
    int x = -1;
    if(st->top==NULL){
        printf("Stack Underflow!!\n");
        return x;
    }

    node* t = st->top;
    st->top = st->top->next;
    x = t->data;
    free(t);
    return x;
}

int isEmpty(stack st){
    if(st.top==NULL)
        return 1;
    
    return 0;
}

int isFull(stack st){
    node* t = (node *)malloc(sizeof(node));
    if(t==NULL){
        free(t);
        return 1;
    }

    free(t);
    return 0;
}

int peek(stack st, int index){
    node *t = st.top;
    int x = -1;
    if(index<1){
        printf("The index is not valid!!\n");
        return x;
    }
    for(int i = 1; i < index; i++){
        if(t)
            t = t->next;
        else{
            printf("The index is not valid!!\n");
            return x;
        }
    }
    x = t->data;
    return x;
}

int top(stack st){
    if(st.top==NULL)
        return -1;
    
    return st.top->data;
}

int main(){
    stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);

    display(st);

    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
}