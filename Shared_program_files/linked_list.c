#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

int isempty( struct node *start )
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
    struct node *ptr = (struct node *)malloc( sizeof(struct node));

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

void display( struct node *start )
{
    if (!isempty(start))
    {
        struct node *ptr = start;

        while ( ptr != NULL )
        {
            printf("%d\t",(ptr -> value ));
            ptr = ptr -> next;
        }
    }
    else
    {
        printf("No element is present.");
    }
    
}

int count (struct node * start)
{
    int i = 0;
    if (!(isempty(start)))
    {
        struct node *ptr = start;

        while ( ptr != NULL )
        {
            i++;
            ptr = ptr -> next;
        }
    }
    return i;
}

struct node * append( struct node *ptr, int val )
{
    if (isempty(ptr) && !(isfull()))
    {
        struct node *add = (struct node *)malloc(sizeof(struct node));
        add -> value = val;
        add -> next = NULL;

        ptr = add;
    }

    else if (!(isfull()))
    {
        struct node *add = (struct node *)malloc(sizeof(struct node));
        add -> value = val;
        add -> next = NULL;

        struct node *point = ptr;

        while ( (point -> next) !=NULL )
        {
            point = (point -> next);
        }
        (point -> next) = add;
    }

    else
    {
        printf("Overflow.");
    }
    
    return ptr;
}

struct node * begin_insert( struct node *ptr, int val )
{
    if (isempty(ptr) && !(isfull()))
    {
        struct node *add = (struct node *)malloc(sizeof(struct node));
        add -> value = val;
        add -> next = NULL;

        ptr = add;
    }

    else if (!(isfull()))
    {
        struct node *add = (struct node *)malloc(sizeof(struct node));
        add -> value = val;
        add -> next = ptr;
        return add;
    }

    else
    {
        printf("Overflow.");
    }
    return ptr;
}

struct node * insert( struct node * start, int val, int position )
{
    int counter = count(start);

    if ( position > counter)
    {
        printf("Insertion cannot be done.");
    }
    else if ( isfull() )
    {
        printf("Overflow.");
    }
    else if (position == counter)
    {
        return append(start,val);
    }
    else if (position == 0)
    {
        return begin_insert(start,val);
    }
    else
    {
        struct node *add = (struct node *)malloc(sizeof(struct node));
        add -> value = val;
        int i=1;
        struct node *front = start -> next;
        struct node *back = start;

        while(i != position)
        {
            front = front -> next;
            back = back -> next;
            i++;
        }
        back -> next = add;
        add -> next = front;
    }
    return start;
}

int main()
{
    int input;
    struct node *start = NULL;
    do
    {
        printf("\n\nOptions:\n\n1.Add element at the end.\n2.Number of nodes present.\n3.Add element at the beginning.\n4.Add element after some elements.\n5.Display content.\n6.Exit.\n\nEnter option:");
        scanf("%d",&input);

        switch(input)
        {
            case 1:
            {
                int val;
                printf("\nEnter element:");
                scanf("%d",&val);

                start = append( start, val );
                break;
            }
            case 2:
            {
                int counter = count(start);
                printf("There are %d nodes.",counter);
                break;
            }
            case 3:
            {
                int val;
                printf("\nEnter element:");
                scanf("%d",&val);

                start = begin_insert( start, val );
                break;
            }
            case 4:
            {
                int val,p;
                printf("\nEnter element:");
                scanf("%d",&val);
                printf("Insertion position after which:");
                scanf("%d",&p);

                start = insert( start, val, p );
                break;
            }
            case 5:
            {
                display( start );
                break;
            }
            case 6:
            {
                printf("Good Byee.");
                break;
            }
            default:
            {
                printf("Wrong Choice.");
            }
        }

    } while ( input != 6 );
    return 0;
}