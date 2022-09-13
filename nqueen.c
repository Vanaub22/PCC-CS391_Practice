//to solve the n-queen problem and also find the number of a solutions for a particular case 
#include<stdio.h>
#include<stdlib.h>
int is_attack (int i, int j, int board[100][100], int N)
{
  int k, l;
  // checking for column j
  for (k=1;k<=i-1;k++)
    {
      if (board[k][j] == 1)
	return 1;
    }//end of for loop
  k=i-1;
  l=j+1;
  while(k>=1&&l<=N)
    {
      if(board[k][l] == 1)
	return 1;
      k=k+1;
      l=l+1;
    }//end of while loop
  k = i-1;
  l = j-1;
  while (k >= 1 && l >= 1)
    {
      if (board[k][l] == 1)
	return 1;
      k=k-1;
      l = l - 1;
    }//end of while loop
  return 0;
}//end of fn.
int n_queen (int row, int n, int N, int board[100][100])
{
  if (n == 0)
    return 1;
  int j;
  for (j = 1; j <= N; j++)
    {
      if (!is_attack (row, j, board, N))
	{
	  board[row][j] = 1;
	  if (n_queen (row + 1, n - 1, N, board))
	    return 1;
	  board[row][j] = 0;//backtracking operation
	}//end of if-block
    }//end of for loop
  return 0;
}//end of fn.
int main ()
{
  int board[100][100];
  int i, j, r, c;
  printf ("Enter the number of rows/columns:");
  scanf ("%d", &r);
  for (i = 0; i <= r; i++)
    {
      for (j=0;j<=r;j++)
	board[i][j] = 0;
    }
  n_queen(1,r,r,board);
  for (i=1;i<=r;i++)
    {
      for (j=1;j<=r;j++)
	printf ("%d\t", board[i][j]);
      printf ("\n");
    }//end of for loop
  return 0;
}//end of main
