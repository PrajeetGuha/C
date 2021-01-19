/* Name: Prajeet Guha
   Roll: 28
   CSE 2nd Year 3rd Sem
   Date: 13/1/2021
   Assignment: 15
   Question: To convert infix expression to prefix expression 
   */


#include<stdio.h>
#include<strings.h>
#include<ctype.h>
#include<stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void check()
{
	printf("check");
}

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

void infix_to_prefix( char set1[], char set2[] )
{
	int s = strlen(set1);
	int j = 0,i;
	for ( i = s-1; i >= 0; i-- )
	{
		if ( set1[i] == '(' )
			set1[i] = ')';
		else if ( set1[i] == ')' )
			set1[i] = '(';
		
		set2[j++] = set1[i];
	}
	set2[j] = '\0';
	
	infix_to_postfix( set2, set1 );
	
	s = strlen(set1);
	j = 0;
	for ( i = s-1; i >= 0; i-- )
		set2[j++] = set1[i];
	set2[j] = '\0';
}
	

int main()
{
	char infix[SIZE], prefix[SIZE];
	printf("Enter the infix equation:");
	gets(infix);
	
	infix_to_prefix( infix, prefix );
	printf("The prefix expression is:");
	puts(prefix);
	return 0;
}