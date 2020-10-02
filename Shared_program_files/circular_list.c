#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int x;
    struct node *next;
} node;

int isempty(node *start)
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

int isfull()
{

    node *ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
    {
        free(ptr);
        return 1;
    }
    else
    {
        return 0;
    }
}

node *create(node *start)
{
    if (!isfull())
    {
        int a, j, n;
        node *new, *p;
        printf("\n\nEnter number of nodes:");
        scanf("%d", &n);
        printf("enter datas:\n");
        for (j = 0; j < n; j++)
        {
            new = (node *)malloc(sizeof(node));
            scanf("%d", &a);
            new->x = a;
            if (j == 0)
            {
                start = new;
                p = new;
            }
            else
            {
                p->next = new;
                p = new;
            }
        }
        new->next = start;
        return start;
    }
    else
    {
        printf("\n\nOverflow.");
    }
    return start;
}

node * insert_beg( node *ptr, int val )
{
    if (isempty(ptr) && !(isfull()))
    {
        node *add = (node *)malloc(sizeof(node));
        add -> x = val;
        add -> next = add;

        ptr = add;
    }

    else if (!(isfull()))
    {
        node *add = (node *)malloc(sizeof(node));
        node *temp = ptr;

        while (temp->next != ptr)
        {
            temp = temp->next;
        }
        temp->next = add;
        add -> x = val;
        add -> next = ptr;

        return add;
    }

    else
    {
        printf("Overflow.");
    }
    return ptr;
}

node * insert_end( node *ptr, int val )
{
    if (isempty(ptr) && !(isfull()))
    {
        node *add = (node *)malloc(sizeof(node));
        add -> x = val;
        add -> next = add;

        ptr = add;
    }

    else if (!(isfull()))
    {
        node *add = (node *)malloc(sizeof(node));
        node *temp = ptr;

        while (temp->next != ptr)
        {
            temp = temp->next;
        }
        temp->next = add;
        add -> x = val;
        add -> next = ptr;
    }

    else
    {
        printf("Overflow.");
    }
    return ptr;
}

node *del_beg(node *start)
{
    if (isempty(start))
    {
        printf("\n\nNo list.");
    }
    else
    {
        node *ptr = start;
        node *temp = (node *)malloc(sizeof(node));
        temp = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = start->next;
        start = start->next;
        free(temp);
    }
    return start;
}

node *del_end(node *start)
{
    if (isempty(start))
    {
        printf("\n\nNo list.");
    }
    else
    {
        node *ptr = start;
        node *temp = (node *)malloc(sizeof(node));
        while (ptr->next->next != start)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = start;
        free(temp);
    }
    return start;
}

node * del_list( node * start )
{
    if (isempty(start))
    {
        printf("\n\nElement cannot be deleted.");
    }
    else
    {
        node *ptr = start->next;
        while(ptr->next != start )
        {
            node *temp = (node *)malloc(sizeof(node));
            temp = ptr;
            ptr=ptr->next;
            free(temp);
        }
        node *temp = (node *)malloc(sizeof(node));
        temp = ptr;
        free(temp);
        free(start);
        node *start = NULL;
        return start;
    }
}

void display(node *start)
{
    if (!isempty(start))
    {
        node *ptr = start->next;
        printf("*--->");
        printf("%d--->",start->x);

        while (ptr != start)
        {
            printf("%d--->", (ptr->x));
            ptr = ptr->next;
        }
        printf("*");
    }
    else
    {
        printf("No element is present.");
    }
}

int main()
{
    int input;
    node *start = NULL;
    do
    {
        printf("\n\nOptions:\n\n1.Create circular linked list.\n2.Insert node at the beginning.\n3.Insert node at the end.\n4.Delete node at the beginning.\n5.Delete node at the end.\n6.Delete circular list.\n7.Display list.\n8.Exit.\n\nEnter option:");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
        {
            start = create(start);
            break;
        }
        case 2:
        {
            int val;
            printf("\nEnter value:");
            scanf("%d",&val);
            start = insert_beg(start,val);
            break;
        }
        case 3:
        {
            int val;
            printf("\nEnter value:");
            scanf("%d",&val);
            start = insert_end(start,val);
            break;
        }
        case 4:
        {
            start = del_beg(start);
            break;
        }
        case 5:
        {
            start = del_end(start);
            break;
        }
        case 6:
        {
            start = del_list(start);
            break;
        }
        case 7:
        {
            display(start);
            break;
        }
        case 8:
        {
            printf("Good byee");
            break;
        }
        default:
        {
            printf("Wrong option");
        }
        }
    } while (input != 8);
    return 0;
}