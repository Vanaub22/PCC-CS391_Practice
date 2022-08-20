//To evaluate the value of a polynomial using Horner's rule
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,*a,x,s;
    printf("\nEnter the order of the polynomial: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("\nEnter the coefficients of the polynomial: ");
    for(i=0;i<n;i++)
    {
        printf("\nEnter coefficient %d: ",i+1);
        scanf("%d",&a[i]);
    }//end of for loop
    printf("\nEnter the value of x: ");
    scanf("%d",&x);
    printf("\nThe value of the polynomial is: ");
    s=a[0];
    for(i=1;i<n;i++)
    s=s*x+a[i];
    printf("%d\n",s);
}//end of main
