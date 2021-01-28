#include<stdio.h>
#include<strings.h>
#include<ctype.h>
#include<stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push( char val )
{
	if ( top == SIZE - 1 )
		printf("overflow.");
	else
		stack[++top] = val;
}

int pop ()
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

int precedence ( char val )
{
	if ( val == '^' )
		return 3;
	else if ( val == '/' || val == '*' )
		return 2;
	else if ( val == '+' || val == '-' )
		return 1;
	else
		return 0;
}

void infix_to_postfix ( char infix[], char postfix[] )
{
	push('(');
	strcat(infix,")");
	//infix = infix + )
	int i = 0;
	int j = 0;
	char prev;
	
	char target = infix[i];
	
	while ( target != '\0' )
	{
		if ( target == '(' )
			push('(');
		else if ( isdigit(target) || isalpha(target) )
			postfix[j++] = target;
		else if ( is_operator(target) )
		{
				prev = pop();
				while ( precedence(prev) >= precedence(target) )
				{
					postfix[j++] = prev;
					prev = pop();
				}
				push(prev);
				push(target);
		}
		else if ( target == ')' )
		{
			prev = pop();
			while ( prev != '(' )
			{
				postfix[j++] = prev;
				prev = pop();
			}
		}
		else
		{
			printf("Invalid infixing.");
			exit(1);
		}
		target = infix[++i];
	}
	if ( top >= 0 )
		printf("Invalid infixing.");
	
	postfix[j] = '\0';
}

int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("Enter the infix equation:");
	gets(infix);
	
	infix_to_postfix( infix, postfix );
	printf("The postfix expression is:");
	puts(postfix);
	return 0;
}