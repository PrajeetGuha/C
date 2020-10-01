/*
Name: Prajeet Guha
Computer Science and Engineering Second Year
Roll No: 28
Assignment No.: 6
Date of assignment:24/09/2020

Question_Number: 1
Question_description: Write a menu driven program for 1.creating 2.deleting first node 3.deleting last node 4.searching a node 5. deleting after a node 6.deleting before a node 7.displaying a node
*/



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
        new->next = NULL;
        return start;
    }
    else
    {
        printf("\n\nOverflow.");
    }
    return start;
}

node *del_begin(node *start)
{
    if (isempty(start))
    {
        printf("\n\nElement cannot be deleted.");
    }
    else
    {
        start = start->next;
    }
    return start;
}

node *del_end(node *start)
{
    if (isempty(start))
    {
        printf("\n\nElement cannot be deleted.");
    }
    else
    {
        node *ptr = start;
        while ((ptr->next)->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
    }
    return start;
}

int search(node *start,int s)
{
    int count=0;
    if (!isempty(start))
    {
        int f = 0;
        node *ptr = start;

        while (ptr != NULL)
        {
            ++count;
            if (ptr->x == s)
            {
                printf("Element found at node %d\n", count);
                f = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (!f)
        {
            printf("No such element is present.");
            count=-1;
        }
    }
    else
    {
        printf("There is no node.");
        count=0;
    }
    return count;
}

node *del_before(node *start)
{
    if(isempty(start))
    {
        printf("Deletion cannot be possible.");
    }
    else
    {
        int s;
        printf("Enter search value:");
        scanf("%d",&s);

        if (start->x==s)
        {
            printf("Deletion cannot be possible.");
        }
        else
        {
            node *ptr,*ptr2;
            ptr = start;
            ptr2 = start;
            int n = search(start,s);
            int i=2;
            if (n>2)
            {
                while(i<=n)
                {
                    ptr=ptr->next;
                    i++;
                }
                i=1;
                while(i<(n-2))
                {
                    ptr2=ptr2->next;
                    i++;
                }
                ptr2->next = ptr;
            }
            else if (n==2)
            {
                start = del_begin(start);
            }
            else
            {
                printf("No element as such present.");
            }            
        }        
    }
    return start;
}

node *del_after(node *start)
{
    node *t;
	t=start;
    int s,f=0;
    printf("Enter keyvalue:");
    scanf("%d",&s);
	if(isempty(start))
	{
		printf("there is no element:\n");
	}
	else
	{
		while(t->next!=NULL)
		{
			if(t->x==s)
			{
                f=1;
				t->next=(t->next)->next;
				break;
		    }
		    t=t->next;
		}
        if(f)
        {
            printf("Element found.");
        }
        else
        {
            printf("Element not found.");
        }
	}
    return start;
}

void display(node *start)
{
    if (!isempty(start))
    {
        node *ptr = start;

        while (ptr != NULL)
        {
            printf("%d\t", (ptr->x));
            ptr = ptr->next;
        }
    }
    else
    {
        printf("No element is present.");
    }
}

int main()
{
    node *start = NULL;
    int opt;

    do
    {

        printf("\n\nOptions:\n\n1.Create a new linked list.\n2.Delete first node.\n3.Delete last node.\n4.Search an element.\n5.Delete after keyvalue.\n6.Delete before keyvalue.\n7.Display elements.\n8.Exit.\n\nChoose an option:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            start = create(start);
            break;
        }
        case 2:
        {
            start = del_begin(start);
            break;
        }
        case 3:
        {
            start = del_end(start);
            break;
        }
        case 4:
        {
            int s;
            printf("\n\nEnter value to search:");
            scanf("%d", &s);
            search(start,s);
            break;
        }
        case 5:
        {
            start = del_after(start);
            break;
        }
        case 6:
        {
            start = del_before(start);
            break;
        }
        case 7:
        {
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
            printf("Wrong Choice.");
        }
        }
    } while (opt != 8);
    return 0;
}
