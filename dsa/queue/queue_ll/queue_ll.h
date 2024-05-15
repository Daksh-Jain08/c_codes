typedef struct Node{
    int data;
    struct Node *next;
} node;

typedef struct Array_queue{
    node *front;
    node *rear;
} queue;


void create_queue(queue *q);
void enqueue(queue *q, int ele);
int dequeue(queue *q);
void display(queue q);