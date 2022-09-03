//to solve tower of hanoi problem using recursion
#include<stdio.h>
void initialization(int*);
void Tower_of_Hanoi(int*,int,char,char,char);
void initialization(int *step_count)
{
	*step_count=0;
}//end of fn.
void Tower_of_Hanoi(int *step_count, int N, char Source, char Aux, char Target)
{
	if(N>0)
	{
		Tower_of_Hanoi(step_count,(N-1),Source,Target,Aux);
		printf("\nStep No. %d : transfer disk %d from %c to %c", ++(*step_count),N,Source,Target);
		Tower_of_Hanoi(step_count,(N-1),Aux,Source,Target);
	}//end of if-block
}//end of fn.
void main()
{
	int n, step_no;
	printf("\nEnter the number of disks:");
	scanf("%d",&n);
	initialization(&step_no);
	Tower_of_Hanoi(&step_no,n,'S','A','T');
}//end of main
