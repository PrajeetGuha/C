/* Name:Prajeet Guha Roll:28 */

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;

node *head=NULL,*tail;

int isempty()
{
    if(head==NULL)
        return 1;
    else
        return 0;
}
void enqueue()
{   int data;
    printf("Enter Data:");
    scanf("%d",&data);
    node *new;
    if(isempty())
    {
        head=(node *)malloc(sizeof(node));
        head->data=data;
        head->link=NULL;
        tail=head;
    }
    else
    {
        new=(node *)malloc(sizeof(node));
        new->data=data;
        new->link=NULL;
        tail->link=new;
        tail=new;
    }
}

void dequeue()
{
    if(head==NULL)
        printf("\nQueue is empty");
    else
        head=head->link;
        
    
}
void display()
{
    if(head==NULL)
        printf("\nQueue is empty");
    else
    {
        node *ptr=head;
        printf("\nQueue: ");
        while(ptr->link!=NULL)
        {   printf("%d ",(ptr->data));
            ptr=ptr->link;
        }
        printf("%d\n",(ptr->data));
    }
}
void main()
{
    int choice;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Choice:");
        scanf("%d",&choice);
        if(choice==4)
            break;
        switch (choice)
        {
        case 1:
                enqueue();
                break;
        case 2:
                dequeue();
                break;
        case 3:
                display();
                break;
        default:
            printf("Invalid Choice!");
            break;
        }
     }
     printf("\nProgram exited Sucessfully!\n");
}