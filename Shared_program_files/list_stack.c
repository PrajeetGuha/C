/* Name: Prajeet Guha
   Roll: 28
   CSE 2nd Year
   Question: Stack operation PUSH, POP, DISPLAY using linked list
   Date: 30/12/2020
   Assignment: 13
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

int main()
{
	node *low = NULL;
	int c, o;
	printf("Stack using linked list.\n");
	do
	{
		printf("\nOptions:\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				node *new = ( node *) malloc ( sizeof( node ) );
				if ( new == NULL )
					printf("Overflow. Cannot push.");
				else
				{
					printf("\nEnter data:");
					scanf("%d",&o);
					new->data = o;
					new->next = NULL;
					
					if ( low == NULL )
						low = new;
					else
					{
						node *ptr = low;
						while ( ptr->next != NULL )
							ptr = ptr->next;
						ptr->next = new;
					}
				}
				break;
			}
			
			case 2:
			{
				if ( low == NULL )
					printf("\nUnderflow. Cannot pop.");
				else
				{
					if ( low->next == NULL )
						low = NULL;
					else
					{
						node *ptr = low;
						while ( ptr->next->next != NULL )
							ptr = ptr->next;
						node *temp = ptr->next;
						free(temp);
						ptr->next = NULL;
					}
				}
				break;
			}
			
			case 3:
			{
				if ( low == NULL )
					printf("\nNo element present.");
				else
				{
					node *ptr = low;
					while ( ptr != NULL )
					{
						printf("%d\n----------\n",ptr->data);
						ptr = ptr->next;
					}
				}
				break;
			}
			
			case 4:
			{
				printf("\nGoodbyee");
				break;
			}
			
			default:
				printf("\nWrong input.");
		}
	}
	while( c != 4 );
	return 1;
	}