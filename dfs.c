//to implement DFS
#include <stdio.h>
#include <stdlib.h>
int vis[100];
struct Graph
{
  int V;
  int E;
  int **Adj;
};//end of structure definition
struct Graph *adjMatrix ()
{
  int u, v, k;
  struct Graph *G = (struct Graph *) malloc (sizeof (struct Graph));
  if (!G)
    {
      printf ("Memory Error\n");
      return NULL;
    }//end of if block
  G->V =7;
  G->E =7;
  G->Adj=(int**)malloc((G->V)*sizeof(int*));
  for (k = 0; k < G->V; k++)
      G->Adj[k] = (int *) malloc ((G->V) * sizeof (int));
  for (u = 0; u < G->V; u++)
    {
      for (v = 0; v < G->V; v++)
	  G->Adj[u][v] = 0;
    }//end of for loop
  G->Adj[0][1] = G->Adj[1][0] = 1;
  G->Adj[0][2] = G->Adj[2][0] = 1;
  G->Adj[1][3] = G->Adj[3][1] = 1;
  G->Adj[1][4] = G->Adj[4][1] = 1;
  G->Adj[1][5] = G->Adj[5][1] = 1;
  G->Adj[1][6] = G->Adj[6][1] = 1;
  G->Adj[6][2] = G->Adj[2][6] = 1;
  return G;
}//end of fn.
void DFS (struct Graph *G, int u)
{
  int v;
  vis[u] = 1;
  printf ("%d ", u);
  for (v = 0; v < G->V; v++)
    {
      if (!vis[v] && G->Adj[u][v])
      DFS (G, v);
    }//end of for loop
}//end of fn.
void DFStraversal (struct Graph *G)
{
  int i;
  for (i = 0; i < 100; i++)
      vis[i] = 0;
  for (i = 0; i < G->V; i++)
    {
      if (!vis[i])
	  DFS (G, i);
    }//end of for loop
}//end of fn.
void main ()
{
  struct Graph *G;
  G = adjMatrix ();
  DFStraversal (G);
}//end of main
