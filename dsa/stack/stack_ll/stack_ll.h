typedef struct Node{
    int data;
    struct Node *next;
} node;

typedef struct Stack{
    node* top;
} stack;

void create(stack *st);
void display(stack st);
void push(stack *st, int data);
int pop(stack *st);
int isEmpty(stack st);
int isFull(stack st);
int peek(stack st, int index);
int top(stack st);