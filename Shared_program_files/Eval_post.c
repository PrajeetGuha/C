/* Name: Prajeet Guha
   Roll: 28
   CSE 2nd Year 3rd Sem
   Date: 13/1/2021
   Assignment: 15
   Question: To evaluate postfix expression
   */


#include<stdio.h>
#include<strings.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 100

float stack[SIZE];
int top = -1;

void push( float val )
{
	if ( top == SIZE - 1 )
		printf("overflow.");
	else
		stack[++top] = val;
}

float pop ()
{
	if ( top == -1 )
		printf("underflow");
	else
		return stack[top--];
}

int is_operator ( char val )
{
	if ( val == '/' || val == '*' || val == '+' || val == '-' || val == '^' )
		return 1;
	else
		return 0;
}

float evaluate ( char postfix[] )
{	
	int i = 0, temp;
	float opd_1, opd_2, dig, res;
	char target = postfix[i];
	
	while ( target != '\0' )
	{
		if ( isdigit(target))
		{
			temp = (int)target;
			temp = temp - 48;
			dig = temp * 1.00;
			push(dig);
		}
		else if ( is_operator(target) )
		{
			if ( top == 0 )
			{
				printf("Wrong postfix expression.");
				exit(1);
			}
			opd_1 = pop();
			opd_2 = pop();
			if ( target == '/' )
				res = opd_1 / opd_2;
			else if ( target == '*' )
				res = opd_1 * opd_2;
			else if ( target == '-' )
				res = opd_1 - opd_2;
			else if ( target == '+' )
				res = opd_1 + opd_2;
			else if ( target == '^' )
				res = pow( opd_1, opd_2 );
			
			push(res);
		}
		else
		{
			printf("Invalid postfix expression.");
			exit(1);
		}
		target = postfix[++i];
	}
	if ( top >0 )
	{
		printf("Invalid postfix expression.");
		exit(1);
	}
	
	return pop();
}

int main()
{
	char postfix[SIZE];
	printf("Enter the postfix equation:");
	gets(postfix);
	float r;
	r = evaluate( postfix );
	printf("The result:%f",r);
	return 0;
}