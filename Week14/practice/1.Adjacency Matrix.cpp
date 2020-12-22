#include <stdio.h>
#include <stdlib.h>

#define MAX 80

void init(int adjacency[MAX][MAX])
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
    	for (j = 0; j < MAX; j++)
    	{
    		adjacency[i][j] = 0;
		}
	}
}

void addEdge(int adjacency[MAX][MAX], int x, int y)
{
	adjacency[x][y] = 1;
}

void printAdjMatrix(int adjacency[MAX][MAX], int nodes)
{
	int i, j;
	
	printf("Adjacency Matrix\n");
	
	for(i = 0; i < nodes; i++)
	{
		for(j = 0; j < nodes; j++)
		{
			printf("%d ", adjacency[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int nodes;
	int edges;
	int i,x, y;
	int adjacency[MAX][MAX];
	
	while (1)
	{
		printf("Insert the number of nodes : ");
		scanf("%d", &nodes);
		
		if (nodes == 0 || nodes > MAX)
		{
			break;
		}
		
		init(adjacency);
		
		printf("Insert the number of edges : ");
		scanf("%d", &edges);
		
		for (i = 1; i <= edges; i++)
		{
			printf("Insert the edge%d : ", i);
			scanf("%d %d", &x, &y);
			addEdge(adjacency, x, y);
		} 
		
		printf("--------------------------------\n");
		
		printAdjMatrix(adjacency, nodes);
	}
	
	return 0;
}

