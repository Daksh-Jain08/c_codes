#include<stdio.h>
#include<stdlib.h>
#include"queue_ll.h"

void create_queue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue *q, int ele){
    node *t = (node *)malloc(sizeof(node));
    if(t==NULL){    //case for heap full, the space for t will not be allocated
        printf("Stack Overflow!!\n");
        return;
    }
    
    t->data = ele;
    t->next = NULL;

    if(q->front == NULL)
        q->front = q->rear = t;
    else{
        q->rear->next = t;
        q->rear = t;
    }
}

int dequeue(queue *q){
    int x = -1;
    if(q->front==NULL)
        printf("Stack Underflow!\n");
    else{
        node *t = q->front;
        q->front = q->front->next;
        x = t->data;
        free(t);
    }

    return x;
}

void display(queue q){
    node *t = q.front;
    while(t){
        printf("%d,", t->data);
        t = t->next;
    }
    printf("\n");
}