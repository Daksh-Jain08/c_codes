#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void create_queue(queue *q){
    q->front = q->rear = NULL;
}

void enqueue(queue *q, tnode *ele){
    qnode *t = (qnode *)malloc(sizeof(qnode));
    if(!t){
        printf("Queue Overflow!\n");
        return;
    }
    
    t->ele = ele;
    t->next = NULL;

    if(q->front == NULL)
        q->front = q->rear = t;
    
    else{
        q->rear->next = t;
        q->rear = t;
    }
}

tnode * dequeue(queue *q){
    tnode *x = NULL;
    if(q->front == NULL){
        printf("Queue Underflow!\n");
        return x;
    }

    qnode *t = q->front;
    q->front = t->next;
    x = t->ele;
    free(t);
    
    return x;
}

void display(queue q){
    qnode *t = q.front;
    while(t){
        printf("%p", t->ele);
        t = t->next;
    }
    printf("\n");
}

int isEmpty(queue q){
    if(q.front == NULL)
        return 1;
    else
        return 0;
}