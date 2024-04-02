#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *Head;

void Create(int A[], int n)
{
    Head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t, *last;
    Head->data = A[0];
    Head->prev = Head;
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = Head;
        last->next = t;
        Head->prev = t;
        last = t;
    }
}

int Length(struct Node *h)
{
    int length = 0;
    struct Node *p = h;
    do
    {
        p = p->next;
        length++;
    } while (p != Head);

    return length;
}

void Display(struct Node *h)
{
    int flag = 0;
    struct Node *p = h;
    while (p != Head || flag == 0)
    {
        printf("%d ", p->data);
        p = p->next;
        if (p->next == Head)
            flag = 1;
    }
    printf("\n");
}

void Rdisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        if (h->next != Head)
            Rdisplay(h->next);
    }
    if (h == Head)
        printf("\n");
    flag = 0;
}

void Insert(int index, int ele, bool *ok)
{
    struct Node *p = Head;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = ele;
    if (index < 0 || index > Length(Head))
    {
        printf("Please give an index between 0 and %d\n", Length(Head));
        *ok = false;
    }
    else if (index == 0)
    {
        t->next = Head;
        t->prev = Head->prev;
        Head->prev->next = t;
        Head->prev = t;
        Head = t;
        *ok = true;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
        *ok = true;
    }
}

void Delete(int index, int *deleted_ele, bool *ok)
{
    struct Node *p = Head;
    if (index < 0 || index > Length(Head)-1 )
    {
        printf("Please give an index between 0 and %d\n", Length(Head)-1 );
        *ok = false;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        if(p==Head)
            Head = p->next;
        *deleted_ele = p->data;
        free(p);
        *ok = true;
    }
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    Create(A, 5);
    Rdisplay(Head);
    bool ok;
    Insert(1, 5, &ok);
    if (ok)
        Display(Head);
    int deleted_ele;
    Delete(-1, &deleted_ele, &ok);
    if(ok){
        printf("The deleted element is %d\n", deleted_ele);
        Display(Head);
    }
    return 0;
}