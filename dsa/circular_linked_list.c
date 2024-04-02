#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d, ", h->data);
        h = h->next;
    } while (h != Head);
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
    flag = 0;
    if (h == Head)
        printf("\n");
}

int Length(struct Node *p)
{
    int i = 0;
    while (p->next != Head)
    {
        p = p->next;
        i++;
    }
    return i;
}

void Insert(int index, int element)
{
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = element;
    if (index < 0 || index > Length(Head))
    {
        printf("The index is not valid!\n");
        return;
    }
    if (index == 0)
    {
        if (Head == NULL)
        {
            Head = t;
            Head->next = t;
        }
        else
        {
            p = Head;
            while (p->next != Head)
            {
                p = p->next;
            }
            t->next = Head;
            p->next = t;
            Head = t;
        }
    }
    else
    {
        p = Head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void Delete(int index, int *deleted_ele, bool *ok)
{
    struct Node *p = Head, *t;
    if (index < 0 || index > Length(Head))
    {
        printf("Enter a valid index!\n");
        *ok = false;
    }
    else if (index == 0)
    {
        if (Head == NULL)
        {
            printf("The linked list is already empty.\n");
            *ok = false;
        }
        else
        {
            do
            {
                p = p->next;
            } while (p->next != Head);
            *deleted_ele = Head->data;
            t = p->next;
            p->next = Head->next;
            Head = Head->next;
            free(t);
            *ok = true;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        *deleted_ele = p->next->data;
        t = p->next;
        p->next = t->next;
        free(t);
        *ok = true;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Display(Head);
    return 0;
}