#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
} node;

int empty(node *start)
{
    if (start == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full()
{
    node *ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        free(ptr);
        return 0;
    }
}

void del(node *start)
{
    if (empty(start))
    {
        return;
    }
    node *ptr = start->next;
    while (ptr->next != start)
    {
        node *n = (node *)malloc(sizeof(node));
        n = ptr;
        ptr = ptr->next;
        free(n);
    }
    free(start);
}

node *create()
{
    node *start = NULL;
    node *ptr = start;
    node *tkr = start;
    int c,j=0;

    do
    {
        printf("Options:\n\n1.Add a node.\n2.Exit.\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                int b;
                node *new = (node *)malloc(sizeof(node));
                printf("Enter data:");
                scanf("%d",&b);
                new->x = b;

                if (j == 0)
                {
                    new->next = new;
                    new->prev = new;
                    start = new;
                    tkr = start;
                    j++;
                }
                else
                {
                    new->next = start;
                    new->prev = tkr;
                    tkr->next = new;
                    start->prev = new;
                    tkr = new;
                }
                break;
            }
            case 2:
            {
                return start;
                break;
            }
            default:
            {
                printf("Wrong input.");
            }
        }
    } while (c != 2);
    
}

node *del_last(node *start)
{
    if (empty(start))
    {
        printf("The list is empty.");
    }
    else
    {
        node *p = NULL;
        if (start->prev == start)
        {
            p = start;
            start = NULL;
        }
        else
        {
            p = start->prev;
            start->prev = start->prev->prev;
            start->prev->next = start;
        }
        free(p);        
    }
    return start;    
}

node *del_beg(node *start)
{
    if (empty(start))
    {
        printf("The list is empty.");
    }
    else
    {
        node *p = NULL;
        if (start->next == start)
        {
            p = start;
            start = NULL;
        }
        else
        {
            p = start;
            start->next->prev = start->prev;
            start->prev->next = start->next;
            start = start->next;
        }
        free(p);        
    }
    return start;    
}

node *del_after(node *start)
{
    node *temp = NULL;
    if (empty(start))
    {
        printf("The list is empty.");
    }
    else
    {
        int s;
        printf("\nEnter the search element:");
        scanf("%d",&s);

        node *ptr = start;
            while (ptr->next != start && ptr->x != s)
            {
                ptr = ptr->next;
            }
            if (ptr->x == s)
            {
                if (ptr->next == start)
                {
                    start = del_beg(start);
                }
                else if (ptr->next->next == start)
                {
                    start = del_last(start);
                }
                else
                {
                    temp = ptr->next;
                    ptr->next = ptr->next->next;
                    ptr->next->prev = ptr;
                }
            }
            else
            {
                printf("no such element is there.");
            }
    }
    free(temp);
    return start;
}

void display(node *head)
{
    if(empty(head))
        {
            printf("\nLink is empty.\n");
            return;
        }
    node *ptr=head;
    printf("\nDoubly linked list:\n");
    printf("tail-->");
    while(ptr->next!=head)
        {
            printf("%d\t",ptr->x);
            ptr=ptr->next;
        }
    printf("%d",ptr->x);
    printf("-->head");
}

int main()
{
    node *start = NULL;
    int i, c;
    do
    {
        printf("\n\nOptions:\n1.Create a circular doubly linked list.\n2.Delete at the last.\n3.Delete at the beginning.\n4.Delete after a node.\n5.Exit.\n\nSelect option:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            printf("\nBefore:\n");
            display(start);
            del(start);
            start = create();
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 2:
        {
            printf("\nBefore:\n");
            display(start);
            start = del_last(start);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 3:
        {
            printf("\nBefore:\n");
            display(start);
            start = del_beg(start);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 4:
        {
            printf("\nBefore:\n");
            display(start);
            start = del_after(start);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 5:
        {
            printf("Goodbyee.");
            break;
        }
        default:
        {
            printf("Wrong option.");
        }
        }
    } while (c != 5);
    return 0;
}