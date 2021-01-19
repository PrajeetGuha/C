/* Name: Prajeet Guha
   Roll: 28
   CSE 2nd Year
   Question: Stack operation PUSH, POP, DISPLAY using array
   Date: 30/12/2020
   Assignment: 13
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int max = 7, arr[8], last = -1, c, o, i;
	printf("Stack using array.\n");
	do
	{
		printf("\nOptions:\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				if ( last == max )
					printf("\nOverflow. Cannot push.");
				else
				{
					printf("\nEnter data:");
					scanf("%d",&o);
					arr[++last] = o;
				}
				break;
			}
			
			case 2:
			{
				if ( last == -1 )
					printf("\nUnderflow. Cannot pop.");
				else
				{
					o = arr[last--];
					printf("\nThe popped data is:%d",o);
				}
				break;
			}
			
			case 3:
			{
				if ( last == -1 )
					printf("\nNo element present.");
				else
				{
					for ( i = last; i >= 0; i-- )
						printf("%d\n---------\n",arr[i]);
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
		