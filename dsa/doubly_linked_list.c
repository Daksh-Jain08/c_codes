#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *Head;

void Create(int A[], int n)
{
    Head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t, *last;
    Head->data = A[0];
    Head->prev = NULL;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int Length(struct Node *h)
{
    struct Node *p = h;
    int count = 1;

    while (p != NULL)
    {
        p = p->next;
        count++;
    }

    return count;
}

void Display(struct Node *h)
{
    struct Node *p = h;

    while (p != NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Insert(int index, int data, bool *ok)
{
    struct Node *t, *p;
    p = Head;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;

    if (index < 0 || index > Length(Head))
    {
        printf("Enter a valid index(The range of valid indices is 0 to %d)\n", Length(Head));
        *ok = false;
        return;
    }
    else if (index == 0)
    {
        if (Head == NULL)
        {
            t->prev = t->next = NULL;
            Head = t;
        }
        else
        {
            Head->prev = t;
            t->next = Head;
            t->prev = NULL;
            Head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        t->prev = p;
        if (t->next != NULL)
            t->next->prev = t;
    }
    *ok = true;
}

void Delete(int index, int *deleted_ele, bool *ok)
{
    struct Node *p = Head, *t;
    if (index < 0 || index >= Length(Head))
    {
        printf("Please enter a valid index!\n");
        *ok = false;
        *deleted_ele = -1;
        return;
    }
    else if (index == 0)
    {
        if (Head == NULL)
        {
            printf("The list is already empty!\n");
            *ok = false;
            *deleted_ele = -1;
            return;
        }
        else
        {
            Head = Head->next;
            if (Head != NULL)
                Head->prev = NULL;
            *deleted_ele = p->data;
            free(p);
            *ok = true;
            return;
        }
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        t = p->prev;
        t->next = p->next;
        if (t->next != NULL)
            t->next->prev = t;
        *deleted_ele = p->data;
        free(p);
        *ok = true;
    }
}

void Reverse()
{
    struct Node *p = Head;
    struct Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            printf("Yes\n");
            Head = p;
        }
    }
}

int main()
{
    int A[5] = {2, 4, 6, 8, 10};
    Create(A, 5);
    Display(Head);
    int deleted_ele;
    bool ok;
    Delete(4, &deleted_ele, &ok);
    if (ok)
    {
        printf("The deleted element is %d\n", deleted_ele);
        Display(Head);
    }
    Insert(4, 54, &ok);
    if (ok)
        Display(Head);

    Reverse();
    Display(Head);
    return 0;
}