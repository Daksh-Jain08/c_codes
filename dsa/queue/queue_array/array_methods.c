#include<stdio.h>
#include<stdlib.h>
#include"queue_array.h"

void create_queue(queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(sizeof(int)*size);
}

void enqueue(queue *q, int ele){
    if(q->rear == q->size-1){
        printf("Queue Overflow: ");
        return;
    }

    q->arr[++q->rear] = ele;
}

int dequeue(queue *q){
    if(q->front == q->rear){
        printf("Queue Underflow: ");
        return -1;
    }

    int x = q->arr[++q->front];
    return x;
}

void display(queue q){
    for(int i = q.front+1; i <= q.rear; i++){
        printf("%d,", q.arr[i]);
    }
    printf("\n");
}