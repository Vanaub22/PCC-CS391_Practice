/*To check if the user-input matrix is a sparse matrix.
If it is a sparse matrix, display it in 3 tuple form and find the transpose.*/
#include<stdio.h>
#include<stdlib.h>
void display(int **,int,int);
int count(int **,int,int);
void sparse(int **,int,int);
void transpose(int **,int,int);
void main()
{
    int r,c,**p,i,j,cn;
    printf("\nEnter the number of rows: ");
    scanf("%d",&r);
    printf("\nEnter the number of columns: ");
    scanf("%d",&c);
    p=(int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++)
    p[i]=(int*)malloc(c*sizeof(int));
    printf("\nEnter the elements: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\nEnter the element in row %d and column %d: ",i+1,j+1);
            scanf("%d",&p[i][j]);
        }///end of inner for loop
    }//end of outer for loop
    display(p,r,c);
    cn=count(p,r,c);
    if(cn>((r*c)/2))
    {
        printf("\nThe matrix is sparse.");

        printf("\nThe matrix in 3 tuple form is:\n");
        printf("%d\t%d\t%d\n",c,r,cn);
        sparse(p,r,c);
        printf("\nThe transpose of the matrix is: \n");
        transpose(p,r,c);
    }//end of if block
    else
    printf("\nThe matrix is not sparse");
}//end of main
void display(int **p,int r,int c)
{
    int i,j;
    printf("\nThe matrix is: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        printf("\n%d\t",p[i][j]);
    }//end of for loop
}//end of fn.
int count(int **p,int r,int c)
{
    int i,j,k,l,m,n,count=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(p[i][j]==0)
            count++;
        }//end of inner for loop
    }//end of outer for loop
    return count;   
}//end of fn.
void sparse(int **p,int r,int c)
{
    int i,j,k,l,m,n;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(p[i][j]!=0)
                printf("%d\t%d\t%d\n",i,j,p[i][j]);
        }//end of inner for loop
    }//end of outer for loop
}//end of fn.
void transpose(int **p,int r,int c)
{
    int i,j,k,l,m,n;
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        printf("\n%d\t",p[j][i]);
    }//end of for loop
}//end of fn.