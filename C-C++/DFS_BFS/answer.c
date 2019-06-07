#define MAX 1001
#include <stdio.h>

int Graph[MAX][MAX] = { 0 };
int BFSvisit[MAX] = { 0 };
int DFSvisit[MAX] = { 0 };
int queue[MAX];


//DFS 구현
int DFS(int v, int N)
{
 	int i;
 	DFSvisit[v] = 1;
 	printf("%d ", v);

 	for (i = 1; i <= N; i++)
 	{
  		if (Graph[v][i] == 1 && DFSvisit[i] == 0)
  		{
   			DFS(i, N);
  		}
 	}
 	return 0;
	}


//BFS구현!!

int BFS(int v, int N)
{

 	int front = 0, rear = 0;
 	int i, pop;

 	BFSvisit[v] = 1;
 	printf("%d ", v);
 	queue[0] = v;
 	rear++;

 	while (front < rear)
 	{
  		pop = queue[front]; 
  		front++; 
  		for (i = 1; i <= N; i++)
  		{
   			if (Graph[pop][i] == 1 && BFSvisit[i] == 0)
   			{
    				printf("%d ", i);
    				queue[rear] = i;
    				rear++;
    				BFSvisit[i] = 1;
   			}
  		}
 	}	
 	return 0;
}


int main()
{
 	int N, M, v;
 	int x, y;

 	scanf("%d%d%d", &N, &M, &v);

 	for (int i = 1; i <= M; i++)
 	{
  		scanf("%d%d", &x, &y);
  		Graph[x][y] = 1;
  		Graph[y][x] = 1;

 	}

 	DFS(v, N);
 	printf("\n");
 	BFS(v, N);

 	return 0;
}
