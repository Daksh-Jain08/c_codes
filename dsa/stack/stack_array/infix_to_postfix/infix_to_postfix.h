typedef struct Char_stack{
    char *arr;
    int size;
    int top;
} char_stack;

void create__char_stack(char_stack *st, int size);
void char_push(char_stack *st, char ele);
char char_pop(char_stack *st);
int char_isEmpty(char_stack st);
int is_operator(char c);
int precedence(char c);
int improved_precedence(char c, int inside_stack);
char* improved_postfix(char *infix);
char* postfix(char *infix);
int evaluate(char *postfix);