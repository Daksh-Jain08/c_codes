typedef struct Array_queue{
    int size;
    int front;
    int rear;
    int *arr;
} queue;


void create_queue(queue *q, int size);
void enqueue(queue *q, int ele);
int dequeue(queue *q);
void display(queue q);