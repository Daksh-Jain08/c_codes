#include<stdio.h>
#include"queue_ll.h"

int main(){
    queue q;
    create_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d\n", dequeue(&q));
    enqueue(&q, 40);

    display(q);

    printf("%d\n", dequeue(&q));

    return 0;
}