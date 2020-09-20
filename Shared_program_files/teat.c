#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *insert(int n)
{
    int i;
    node *head = NULL;
    node *temp = NULL;
    node *p = NULL;

    for (i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    return head;
}

void display(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf("Null");
}

void append()
{
    node *head;
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == temp)
        head = temp;
    else
    {
        node *a;
        a = head;
        while (a == NULL)
            a = a->next;
        a->next = temp;
    }
}

int length()
{
    node *head;
    node *temp;
    temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    return c;
}

void add()
{
    node *head;
    node *k;
    k = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &k->data);
    k->next = NULL;
    if (head == NULL)
        head = NULL;
    else
    {
        k->next = head;
        head = k;
    }
}

void push(int x, int pos)
{
    node *head;
    node *ptr = (node *)malloc(sizeof(node));
    int data = ptr->data;
    int y;
    node *temp = head;
    if (pos == 1)
    {
        ptr->next = temp;
        ptr = head;
        return;
    }

    for (y = 1; y < pos - 1; y++)
        temp = temp->next;
    ptr->next = temp->next;
    temp->next = ptr;
}

int main()
{
    int n, l, x, pos;
    node *head = NULL;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    head = insert(n);
    int ch;
    printf("Enter the operation you want to perform:");
    do
    {
        printf("\n1.Add a node at the end of list: \n2.No. of nodes in list \n3.Add a new node at the beginning of list \n4.Add a new node after specified node \n5.Display the list \n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            printf("Node is added.");
            break;
        case 2:
            l = length();
            printf("The no. of nodes present in the list: %d", l);
            break;
        case 3:
            add();
            printf("Node is added.");
            break;
        case 4:
            printf("Enter the node: ");
            scanf("%d", &x);
            printf("Enter the position: ");
            scanf("%d", &pos);
            push(x, pos);
            printf("The node is added.");
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("Good Bye!");
            break;
        default:
            printf("Wrong Choice!!!");
            break;
        }
    } while (ch != 6);
    return 0;
}
