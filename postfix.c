// C program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};//end of structure definition
struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}//end of fn.
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}//end of fn.
char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}//end of fn.
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}//end of fn.
int evaluatePostfix(char* exp)
{
	struct Stack* stack = createStack(strlen(exp));
	int i;
	if (!stack) return -1;
	for (i = 0; exp[i]; ++i)
	{
		if (isdigit(exp[i]))
			push(stack, exp[i] - '0');
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2/val1); break;
			}//end of switch
		}//end of else
	}//end of for loop
	return pop(stack);
}//end of fn.
void main()
{
    int n;char *exp;
    printf("Enter the maximum number of characters in the expression : ");
    scanf("%d", &n);
    exp = (char*)malloc(n * sizeof(char));
    printf("Enter the expression : ");
    scanf("%s", exp);
	printf ("postfix evaluation: %d", evaluatePostfix(exp));
    free(exp);
}//end of main
