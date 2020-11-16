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

node *create()
{
    int c, b, i = 0;
    node *start = NULL;
    node *ptr = NULL;
    node *trk = NULL;
    do
    {
        printf("Options:\n1.Add a node.\n2.Exit.");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            if (!full())
            {
                int b;
                printf("\nEnter data:");
                scanf("%d", &b);
                node *new = (node *)malloc(sizeof(node));
                new->x = b;
                new->next = NULL;
                new->prev = trk;
                trk = new;

                if (i == 0)
                {
                    start = new;
                    ptr = start;
                    i++;
                }
                else
                {
                    ptr->next = new;
                    ptr = new;
                }
            }
            else
            {
                printf("Overflow.");
            }

            break;
        }
        case 2:
        {
            return start;
        }
        default:
        {
            printf("\nWrong choice.");
        }
        }
    } while (1);
}

void display(node *start)
{
    if (empty(start))
    {
        printf("\nNo node present.\n");
    }
    else if (!empty(start))
    {
        node *ptr = start;
        printf("NULL <-----> ");

        do
        {
            printf("%d <-----> ", ptr->x);
            ptr = ptr->next;
        } while (ptr->next != NULL);
        printf("%d <-----> NULL", ptr->x);

        // printf("\n\n");
        // while(ptr != NULL)
        // {
        //     printf("%d\t",ptr->x);
        //     ptr = ptr->prev;
        // }
    }
    else
    {
        printf("\nNo element is present.");
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

node *begin_insert(node *start)
{
    if (!full())
    {
        int val;
        printf("\nEnter data:");
        scanf("%d", &val);
        node *add = (node *)malloc(sizeof(node));
        add->x = val;
        add->prev = NULL;

        if (empty(start))
        {
            add->next = NULL;
            start = add;
        }

        else
        {
            add->next = start;
            return add;
        }
    }
    else
    {
        printf("\nOverflow.");
    }
    return start;
}

node *insert_end(node *start)
{
    if (!full())
    {
        int val;
        printf("\nEnter data:");
        scanf("%d", &val);
        node *add = (node *)malloc(sizeof(node));
        add->x = val;
        add->next = NULL;

        if (empty(start))
        {
            add->next = NULL;
            start = add;
        }

        else
        {
            node *ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr -> next = add;
            add -> prev = ptr;
        }
    }
    else
    {
        printf("\nOverflow.");
    }
    return start;
}

int main()
{
    node *start = NULL;
    int i, c;
    do
    {
        printf("\n\nOptions:\n1.Create a circular linked list.\n2.Insert at beginning.\n3.Insert at end.\n4.Exit.\n\nSelect option:");
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
            start = begin_insert(start);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 3:
        {
            printf("\nBefore:\n");
            display(start);
            start = insert_end(start);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 4:
        {
            printf("Goodbyee.");
            break;
        }
        default:
        {
            printf("Wrong option.");
        }
        }
    } while (c != 4);
    return 0;
}