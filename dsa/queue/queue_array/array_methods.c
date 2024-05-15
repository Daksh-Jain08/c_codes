#include<stdio.h>
#include<stdlib.h>
#include"queue_array.h"

void create_queue(queue *q, int size){
    q->size = size;
    //q->front = q->rear = -1;  inefficient implementation of queue using array
    q->front = q->rear = 0;
    q->arr = (int *)malloc(sizeof(int)*size);
}

void enqueue(queue *q, int ele){
    if((q->rear+1)%q->size == q->front){    //checking the condition in a circular fashion, is the next position of rear equal to front
        printf("Queue Overflow!!\n");
        return;
    }

    q->rear = (q->rear+1)%q->size;
    q->arr[q->rear] = ele;
}

int dequeue(queue *q){
    if(q->rear == q->front){    //checking the condition in a circular fashion, are front and rear on the same position
        printf("Queue Underflow: ");
        return -1;
    }

    q->front = (q->front+1)%q->size;
    int x = q->arr[q->front];
    return x;
}

void display(queue q){

    // this was for the inefficient case where the rear and front pointers are not moving circularly
    // for(int i = q.front+1; i <= q.rear; i++){
    //     printf("%d,", q.arr[i]);
    // }

    int i = (q.front+1)%q.size;
    do{
        printf("%d,", q.arr[i]);
        i = (i+1)%q.size;
    }while(i != (q.rear+1)%q.size);
    printf("\n");
}