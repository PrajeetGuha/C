/* Name: Prajeet Guha Roll:28 */

#include<stdio.h>
#define MAX 7

int arr[MAX],front=-1,rear=-1,count=0;
int isempty()
{
    if((front==-1 && rear==-1)||!(count))
        return 1;
    else
        return 0;
}
int isfull()
{
    if(count==MAX)
        return 1;
    else
        return 0;
}

void enqueue()
{   
    if(isfull())
    {    
        printf("\nQueue is Full!");
        return;
    }
    
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    if(isempty())
    {
        arr[++rear]=data;
        front++;
        count++;
    }
    
    
    else
    {
        arr[++rear]=data;
        count++;
    }
}
void dequeue()
{
    front++;
    count--;
}
void display()
{
    if(isempty())
     {   printf("\nQueue is empty!\n");
        return;
     }
    printf("Queue: ");
    for(int i=front;i<=rear;i++)
        printf("%d ",arr[i]);
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