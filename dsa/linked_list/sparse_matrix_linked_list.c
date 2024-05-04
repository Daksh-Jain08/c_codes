#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int ele;
    int col;
    struct Node *next;
};

void Create(struct Node **A, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        A[i] = (struct Node *)malloc(sizeof(struct Node));
        struct Node *p = A[i];
        p = NULL;
    }
    for (int i = 0; i < m; i++)
    {
        struct Node *last = A[i];
        for (int j = 0; j < n; j++)
        {
            int ele;
            printf("Enter the element at row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &ele);
            if (ele != 0)
            {
                struct Node *t = (struct Node *)malloc(sizeof(struct Node));
                t->ele = ele;
                t->col = j;
                t->next = NULL;
                last->next = t;
                last = last->next;
            }
        }
    }
}

void Display(struct Node **A, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        struct Node *p = A[i]->next;
        for (int j = 0; j < n; j++)
        {
            if (p != NULL && p->col == j)
            {
                printf("%d ", p->ele);
                p = p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Insert(struct Node **A, int row, int col, int ele, bool *ok)
{
    struct Node *p = A[row - 1];
    while (p->next != NULL && p->next->col <= col - 1)
    {
        p = p->next;
    }
    if (p->col == col - 1)
    {
        p->ele = ele;
        *ok = true
    }
    else
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->ele = ele;
        t->next = p->next;
        p->next = t;
        *ok = true;
    }
}

int main()
{
    int m, n;
    scanf(" %d %d", &m, &n);
    struct Node **A = (struct Node **)malloc(sizeof(struct Node *) * m);
    Create(A, m, n);
    Display(A, m, n);
    return 0;
}