#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int x;
    struct node *next;
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

node *insert()
{
    int a, i = 0;
    node *start = NULL;
    node *ptr = start;
    do
    {
        int c;
        printf("\nOptions:\n1.Add node.\n2.No new node to add.\n\nSelect option:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            node *new = (node *)malloc(sizeof(node));
            printf("\nEnter data:");
            scanf("%d", &a);
            new->x = a;
            if (i == 0)
            {
                start = new;
                new->next = start;
                ptr = start;
                i++;
            }
            else
            {
                new->next = start;
                ptr->next = new;
                ptr = new;
            }
            break;
        }

        case 2:
        {
            return start;
        }

        default:
            printf("\nWrong choice.");
            break;
        }
    } while (1);
    return start;
}

void display(node *start)
{
    if (empty(start))
    {
        printf("\nNo node present.\n");
    }
    else if (!empty(start))
    {
        node *ptr = start->next;
        printf("*--->");
        printf("%d--->", start->x);

        while (ptr != start)
        {
            printf("%d--->", (ptr->x));
            ptr = ptr->next;
        }
        printf("*");
    }
    else
    {
        printf("\nNo element is present.");
    }
}

node *insert_after(node *start)
{
    if (empty(start))
    {
        printf("\nThere is no node.");
    }
    else if (full())
    {
        printf("\nOverflow.");
    }
    else
    {
        int a, f = 0;
        printf("\nEnter the node to search:");
        scanf("%d", &a);
        node *ptr = start;

        do
        {
            if (ptr->x == a)
            {
                node *new = (node *)malloc(sizeof(node));
                int b;
                printf("\nEnter data:");
                scanf("%d", &b);
                new->x = b;
                new->next = ptr->next;
                ptr->next = new;
                f = 1;
                break;
            }
            ptr = ptr->next;
        } while (ptr != start);

        if (!f)
        {
            printf("\nNo node with value %d is present.", a);
        }
    }
    return start;
}

node *insert_before(node *start)
{
    if (empty(start))
    {
        printf("\nThere is no node.");
    }
    else if (full())
    {
        printf("\nOverflow.");
    }
    else
    {
        int a, f = 0;
        printf("\nEnter the node to search:");
        scanf("%d", &a);
        node *ptr = start;
        node *prev = start;

        while (prev->next != start)
        {
            prev = prev->next;
        }

        do
        {
            if (ptr->x == a)
            {
                node *new = (node *)malloc(sizeof(node));
                int b;
                printf("\nEnter data:");
                scanf("%d", &b);
                new->x = b;
                new->next = ptr;
                prev->next = new;

                if (ptr == start)
                {
                    start = new;
                }
                f = 1;
                break;
            }
            prev = prev->next;
            ptr = ptr->next;
        } while (ptr != start);

        if (!f)
        {
            printf("\nNo node with value %d is present.", a);
        }
    }
    return start;
}

node *del_after(node *start)
{
    if (empty(start))
    {
        printf("\nThere is no node.");
    }
    else
    {
        int a, f = 0;
        printf("\nEnter the node to search:");
        scanf("%d", &a);
        node *ptr = start;

        do
        {
            if (ptr->x == a)
            {
                node *temp = (node *)malloc(sizeof(node));

                if (ptr->next == start)
                {
                    start = start->next;
                }
                temp = ptr->next;
                ptr->next = ptr->next->next;
                free(temp);
                f = 1;
                break;
            }
            ptr = ptr->next;
        } while (ptr != start);

        if (!f)
        {
            printf("\nNo node with value %d is present.", a);
        }
    }
    return start;
}

node *del_before(node *start)
{
    if (empty(start))
    {
        printf("\nThere is no node.");
    }
    else
    {
        int a, f = 0;
        printf("\nEnter the node to search:");
        scanf("%d", &a);
        node *ptr = start;
        node *prev = start;

        while (prev->next->next != start)
        {
            prev = prev->next;
        }

        do
        {
            if (ptr->x == a)
            {
                node *temp = (node *)malloc(sizeof(node));
                temp = prev->next;
                prev->next = ptr;
                free(temp);
                f = 1;
                break;
            }
            prev = prev->next;
            ptr = ptr->next;
        } while (ptr != start);

        if (!f)
        {
            printf("\nNo node with value %d is present.", a);
        }
    }
    return start;
}

int main()
{
    node *start = NULL;
    int i, c;
    do
    {
        printf("\n\nOptions:\n1.Create a circular linked list.\n2.Insert after a node.\n3.Insert before a node.\n4.Delete after a node.\n5.Delete before a node.\n6.Exit.\n\nSelect option:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            printf("\nBefore:\n");
            display(start);
            del(start);
            start = insert();
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 2:
        {
            printf("\nBefore:\n");
            display(start);
            start = insert_after(start);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 3:
        {
            printf("\nBefore:\n");
            display(start);
            start = insert_before(start);
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
            printf("\nBefore:\n");
            display(start);
            start = del_before(start);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 6:
        {
            printf("\nGoodbyee.");
            break;
        }
        default:
        {
            printf("\nWrong option.");
        }
        }
    } while (c != 6);

    return 0;
}