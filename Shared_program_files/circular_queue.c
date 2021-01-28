/*Name: Prajeet Guha
  Roll:28
  CSE 2nd Year
  Question: Make circular queue
  Assignment:17
  Date:28/1/2021 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node {
	int x;
	struct node *next;
}node;

#define SIZE 10
int front = -1;
int rear = -1;

int isempty_ll( node *start)
{
	if (start == NULL)
		return 1;
	else
		return 0;
}

int isfull_ll()
{
	node *new = (node *)malloc(sizeof(node));
	if (new == NULL)
	{
		free(new);
		return 1;
	}
	else
	{
		free(new);
		return 0;
	}
}

node * enqueue_ll( node *start)
{
	if (isfull_ll())
		printf("The list overflowing.\n\n");
	else
	{
		int data;
		node *new = (node *)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d",&data);
		new->x = data;
		new->next = start;
		if (isempty_ll(start))
		{
			start = new;
			start->next = start;
		}
		else
		{
			node *ptr = start;
			while(ptr->next != start)
			{
				ptr = ptr->next;
			}
			ptr->next = new;
		}
	}
	return start;
}

node * dequeue_ll( node *start)
{
	if (isempty_ll(start))
		printf("The list underflowing.\n\n");
	else
	{
		node *temp = start;
		node *ptr = start;
		while (ptr->next != start)
			ptr = ptr->next;
		ptr->next = start->next;
		printf("The data %d is dequeued.\n\n",temp->x);
		start = start->next;
		free(temp);
	}
	return start;
}

void display_ll( node *start )
{
	if (isempty_ll(start))
		printf("No element in the queue.\n\n");
	else
	{
		printf("The elements are:\n\n");
		node *ptr = start;
		while (ptr->next != start)
		{
			printf("%d\t",ptr->x);
			ptr = ptr->next;
		}
		printf("%d\t",ptr->x);
	}
}

int isempty()
{
	if ( front == -1 && rear == -1 )
		return 1;
	else
		return 0;
}

int isfull()
{
	int x = rear + 1;
	if (x == SIZE )
		x = 0;
	if (x == front)
		return 1;
	else
		return 0;
}

void enqueue( int *arr )
{
	if (isfull())
		printf("The array is overflowing.\n\n");
	else
	{
		int data;
		printf("Enter data:");
		scanf("%d",&data);
		if (isempty())
		{
			++rear;
			++front;
			arr[0] = data;
		}
		else
		{
			++rear;
			if ( rear == SIZE )
				rear = 0;
			arr[rear] = data;
		}
	}
}

void dequeue( int *arr )
{
	if (isempty())
		printf("The array is underflowing.\n\n");
	else
	{
		printf("The data %d is dequeued.\n\n",arr[front]);
		if ( rear == front )
		{

			rear = -1;
			front = -1;
		}
		else
		{
			++front;
			if ( front == SIZE )
				front = 0;
		}
	}
}

void display(int *arr)
{
	if (isempty())
		printf("No element in the queue.\n\n");
	else
	{
		printf("The elements in the queue are:\n\n");
		int i = front;
		if ( front == rear )
			printf("%d\t",arr[front]);
		else
		{
			while( i != rear )
			{
				printf("%d\t",arr[i]);
				++i;
				if ( i == SIZE )
					i = 0;
			}
			printf("%d",arr[i]);
		}
	}
}

node * linked_list( node *start )
{
	do
	{
		printf("Options (linked list):\n\n1.Enqueue.\n\n2.Dequeue.\n\n3.Display.\n4.Move back in menu.\n");
		int c;
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				start = enqueue_ll(start);
				break;
			}
			case 2:
			{
				start = dequeue_ll(start);
				break;
			}
			case 3:
			{
				display_ll(start);
				break;
			}
			case 4:
			{
				return start;
			}
			default:
			{
				printf("Wrong option.Try again.\n\n");
			}
		}
	}
	while(1);
}

void array( int arr[] )
{
	do
	{
		printf("Options (array):\n\n1.Enqueue.\n\n2.Dequeue.\n\n3.Display.\n4.Move back in menu.\n");
		int c;
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				enqueue(arr);
				break;
			}
			case 2:
			{
				dequeue(arr);
				break;
			}
			case 3:
			{
				display(arr);
				break;
			}
			case 4:
			{
				return;
			}
			default:
			{
				printf("Wrong option.Try again.\n\n");
			}
		}
	}
	while(1);
}

int main()
{
	int c;
	do
	{
		node *start = NULL;
		int ar[SIZE];
		printf("Main menu:\n\n1.Do queue by array.\n\n2.Do queue by linked list.\n\n3.Exit with print.\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				array(ar);
				break;
			}
			case 2:
			{
				start = linked_list(start);
				break;
			}
			case 3:
			{
				display_ll(start);
				printf("\n\n");
				display(ar);
				printf("\n\nGoodbyee.\n");
				break;
			}
			default:
			{
				printf("Wrong input. Try again.\n\n");
			}
		}
	}while( c != 3 );
	return 0;
}