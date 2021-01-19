#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stackpush(char *arr, char val, int max)
{
	++max;
	*(arr + max) = val;
	return max;
}

int stackpop(char *arr, int max)
{
	return --max;
}

void stack_display(char *arr, int max)
{
	int i;
	for ( i = 0; i <= max; i++ )
	{
		printf("%c",*(arr + i) );
	}
}

void main()
{
	char s[100],operand[100],post[100],mul_div[100];
	int max1 = -1, max2 = -1,i,flag;
	printf("Enter the infix operation:");
	scanf("%s",s);
	int n = strlen(s);
	for( i = 0; i <= n; i++ )
	{
		if ( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')')
		{
			if ( s[i] == ')' )
			{
				while ( operand[max1] != '(' )
				{
					char val = *(operand + max1);
					max1 = stackpop(operand, max1);
					max2 = stackpush(post,val,max2);
				}
				max1 = stackpop(operand,max1);
			}
			else if ( s[i] == '*' || s[i] == '/' )
			{
				flag = 1;
			}
			else
			{
				max1 = stackpush(operand,s[i],max1);
			}
		else if (flag)
		{
			
		}
		else if ( s[i] >= '0' && s[i] <= '9' )
		{
			max2 = stackpush(post,s[i],max2);
		}
	}
	stack_display(operand, max1);
	printf("\n\n");
	stack_display(post, max2);
}