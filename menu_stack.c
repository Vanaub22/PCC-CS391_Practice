//To design a menu-driven stack application
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int size;
    int top;
    int *arr;
}stack;//end of structure definition
int isEmpty(stack* ptr);
int isFull(stack* ptr);
void push(stack*,int);
void pop(stack*);
void peek(stack*,int);
void display(stack*);
void display(stack* ptr)
{
    int i;
    if(ptr->top==-1)
    printf("\nStack is empty\nNothing to display");
    else
    {
        printf("\nUser-input stack is as follows: ");
        for(i=0;i<=ptr->top;i++)
        printf("%d ",ptr->arr[i]);
        printf("\n");
    }//end of else block
}//end of fn.
void peek(stack* ptr,int pos)
{
    if((ptr->top-pos+1)<0)
    printf("\nInvalid position for given stack\nNothing to display");
    else
    printf("\nElement at position %d is: %d",pos,ptr->arr[ptr->top-pos+1]);
}//end of fn.
void pop(stack* ptr)
{
    int val;
    if(isEmpty(ptr))
    printf("\nStack Underflow\nNothing to pop");
    else
    {
        val=ptr->arr[ptr->top];
        ptr->top--;
        printf("\n%d has been popped from the stack",val);
    }//end of else block
}//end of fn.
void push(stack* ptr, int val)
{
    if(isFull(ptr))
    printf("\nStack Overflow\n%d cannot be inserted",val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
        printf("%d has been succesfully pushed into the stack",val);
    }//end of else block
}//end of fn.
int isEmpty(stack* ptr)
{
    if(ptr->top==-1)
    return 1;
    else
    return 0;
}//end of fn.
int isFull(stack* ptr)
{
    if(ptr->top==ptr->size-1)
    return 1;
    else
    return 0;
}//end of fn.
void main()
{
    int p,item,choice;
    stack* s;
    s->top=-1;
    printf("\nEnter the size/capacity of the stack: ");
    scanf("%d",&s->size);
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("\nStack has been created succesfully");
    printf("\nPERFORM OPERATIONS IN STACK");
    printf("\n1.To Push\n2.To Pop\n3.To Peek\n4.Check if Empty\n5.Check if Full\n6.Display\n7.EXIT");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the item to be pushed:");
                scanf("%d",&item);
                push(s,item);
                break;
            }//end of case 1
            case 2:
            {
                pop(s);
                break;
            }//end of case 2
            case 3:
            {
                printf("\nEnter the position to peek: ");
                scanf("%d",&p);
                peek(s,p);
                break;
            }//end of case 3
            case 4:
            {
                if(isEmpty(s))
                printf("\nStack is Empty");
                else
                printf("\nThe stack is not empty");
                break;
            }//end of case 4
            case 5:
            {
                if(isFull(s))
                printf("\nStack is Full");
                else
                printf("\nThe stack is not Full");
                break;
            }//end of case 5
            case 6:
            {
                display(s);
                break;
            }//end of case 6
            case 7:
            {
                printf("\nExecution Terminated");
                exit(0);
            }//end of case 7
            default:
            {
                printf("\nInvalid Input...Try Again");
            }//end of default case
        }//end of switch-case
    }//end of while loop
}//end of main