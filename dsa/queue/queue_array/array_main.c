#include<stdio.h>
#include"queue_array.h"

int main(){
    queue q;
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    create_queue(&q, size);
    
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 1);
    enqueue(&q, 3);

    display(q);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}