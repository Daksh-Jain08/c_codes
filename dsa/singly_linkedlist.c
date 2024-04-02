#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first;

void create(int a[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    int i;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    struct Node *t = p;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int num_nodes(struct Node *p)
{
    struct Node *t = p;
    int i = 0;
    while (t)
    {
        i++;
        t = t->next;
    }
    return i;
}

int sum(struct Node *p)
{
    struct Node *t = p;
    int sum = 0;
    while (t)
    {
        sum += t->data;
        t = t->next;
    }
    return sum;
}

int max(struct Node *p)
{
    struct Node *t = p;
    int max = 0;
    while (t)
    {
        if (t->data > max)
            max = t->data;
        t = t->next;
    }
    return max;
}

int search(struct Node *p, int key)
{
    struct Node *t = p, *l = NULL;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    int ind = 1;
    while (t)
    {
        if (t->data == key)
        {
            l->next = t->next;
            t->next = first;
            first = t;
            free(temp);
            return ind;
        }
        else
        {
            ind++;
            l = t;
            t = t->next;
        }
    }
    return -1;
}

void insert(struct Node *p, int ele, int ind)
{
    struct Node *t = p, *l;
    l = (struct Node *)malloc(sizeof(struct Node));
    l->data = ele;
    if (ind == 1)
    {
        l->next = first;
        first = l;
    }
    else
    {
        for (int i = 1; i < ind - 1; i++)
        {
            t = t->next;
        }
        l->next = t->next;
        t->next = l;
    }
}

void insert_sorted(struct Node *p, int ele)
{
    struct Node *t, *q;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = ele;
    while (p && p->data < ele)
    {
        q = p;
        p = p->next;
    }
    if (p == first)
    {
        t->next = first;
        first = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}

void delete(struct Node *p, int ind)
{
    struct Node *q;
    if (ind == 1)
    {
        q = p;
        p = p->next;
        free(q);
        first = p;
    }
    else
    {
        for (int i = 1; i < ind; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }
}

void remove_dup(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse_elements(struct Node *p)
{
    int a[num_nodes(p)];
    int i = 0;
    while (p != NULL)
    {
        a[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        p->data = a[i--];
        p = p->next;
    }
}

void reverse_links(struct Node *p)
{
    struct Node *q=NULL, *r=NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{
    int a[] = {2, 4, 6, 8, 10};
    create(a, 5);
    //reverse_links(first);
    display(first);

    return 0;
}