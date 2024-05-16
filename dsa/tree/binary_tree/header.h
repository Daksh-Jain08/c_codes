typedef struct TreeNode{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
} tnode;

typedef struct QueueNode{
    tnode *ele;
    struct QueueNode *next;
} qnode;

typedef struct Queue{
    qnode *front;
    qnode *rear;
} queue;

void create_queue(queue *q);
void enqueue(queue *q, tnode *ele);
tnode * dequeue(queue *q);
void display(queue q);
int isEmpty(queue q);

tnode * declare_tree();
void create_tree(tnode *root);
void preorder(tnode *root);
void inorder(tnode *root);
void postorder(tnode *root);