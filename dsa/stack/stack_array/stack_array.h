typedef struct Stack{
    int size;
    int top;
    int *arr;
} stack;

void create_stack(int size, stack *st);
int isEmpty(stack st);
void display(stack st);
void push(stack *st, int ele);
int pop(stack *st);
int peek(stack st, int pos);
int stackTop(stack st);
int isFull(stack st);