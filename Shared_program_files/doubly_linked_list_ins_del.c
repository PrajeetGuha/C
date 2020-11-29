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
    while (ptr->next != NULL)
    {
        node *n = (node *)malloc(sizeof(node));
        n = ptr;
        ptr = ptr->next;
        free(n);
    }
    free(start);
}

node *del_node(node *start, int opt)
{
    if (!empty(start))
    {
        node *temp = NULL;
        if (opt == 1)
        {
            temp = start;
            start = start->next;
            if (start != NULL)
            {
                start->prev = NULL;
            }
        }
        else if (opt == 2)
        {
            node *ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            temp = ptr;
            ptr = ptr->prev;
            if (ptr != NULL)
            {
                ptr->next = NULL;
            }
        }
        else if (opt == 3)
        {
            int s;
            printf("\nSearch data:");
            scanf("%d", &s);
            node *ptr = start;
            while (ptr->next != NULL && ptr->x != s)
            {
                ptr = ptr->next;
            }
            if (ptr->x == s)
            {
                if (ptr->next == NULL)
                {
                    printf("No node after this.");
                }
                else if (ptr->next->next == NULL)
                {
                    start = del_node(start, 2);
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
        else if (opt == 4)
        {
            int s;
            printf("\nSearch data:");
            scanf("%d", &s);
            node *ptr = start;
            while (ptr->next != NULL && ptr->x != s)
            {
                ptr = ptr->next;
            }
            if (ptr->x == s)
            {
                if (ptr->prev == start)
                {
                    start = del_node(start, 1);
                }
                else if (ptr->prev == NULL)
                {
                    printf("No node before this.");
                }
                else
                {
                    temp = ptr->prev;
                    ptr->prev->prev->next = ptr;
                    ptr->prev = ptr->prev->prev;
                }
            }
            else
            {
                printf("No such element is present.");
            }
        }
        free(temp);
    }
    else
    {
        printf("The list is empty.");
    }
    return start;
}

node *insert_after(node *start)
{
    if (!full())
    {
        if (empty(start))
        {
            printf("The list is empty.");
        }
        else
        {
            int val, s;
            printf("\nSearch data:");
            scanf("%d", &s);
            node *ptr = start;
            while (ptr->next != NULL && ptr->x != s)
            {
                ptr = ptr->next;
            }
            if (ptr->x == s)
            {
                printf("Enter data:");
                scanf("%d", &val);
                node *add = (node *)malloc(sizeof(node));
                add->x = val;
                add->next = ptr->next;
                add->prev = ptr;
                if (ptr->next != NULL)
                {
                    ptr->next->prev = add;
                }
                ptr->next = add;
            }
            else
            {
                printf("No such element is found.");
            }
        }
    }
    else
    {
        printf("\nOverflow.");
    }
    return start;
}

node *insert_before(node *start)
{
    if (!full())
    {
        int s, val;
        if (empty(start))
        {
            printf("The list is empty.");
        }
        else
        {
            printf("\nSearch data:");
            scanf("%d", &s);
            node *ptr = start;
            while (ptr->next != NULL && ptr->x != s)
            {
                ptr = ptr->next;
            }
            if (ptr->x == s)
            {
                printf("Enter data:");
                scanf("%d", &val);
                node *add = (node *)malloc(sizeof(node));
                add->x = val;
                add->next = ptr;
                add->prev = ptr->prev;
                ptr->prev = add;
                if (add->prev != NULL)
                {
                    add->prev->next = add;
                }
                else
                {
                    return add;
                }
            }
            else
            {
                printf("No such element is found.");
            }
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
        printf("\n\nOptions:\n1.Create a circular linked list.\n2.Insert after a node.\n3.Insert before a node.\n4.Delete at the beginning.\n5.Delete at the end.\n6.Delete after a node.\n7.Delete before a node.\n8.Exit.\n\nSelect option:");
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
            start = del_node(start, 1);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 5:
        {
            printf("\nBefore:\n");
            display(start);
            start = del_node(start, 2);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 6:
        {
            printf("\nBefore:\n");
            display(start);
            start = del_node(start, 3);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 7:
        {
            printf("\nBefore:\n");
            display(start);
            start = del_node(start, 4);
            printf("\nAfter:\n");
            display(start);
            break;
        }
        case 8:
        {
            printf("Goodbyee.");
            break;
        }
        default:
        {
            printf("Wrong option.");
        }
        }
    } while (c != 8);
    return 0;
}