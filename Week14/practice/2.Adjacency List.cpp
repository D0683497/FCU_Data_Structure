#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "input.txt"
#define MAX 80

void init(int arr[MAX][MAX])
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
    	for (j = 0; j < MAX; j++)
    	{
    		arr[i][j] = 0;
		}
	}
}

void printAdjList(int adjacency[MAX][MAX], int i, int j)
{
	int x, y;
	
	printf("Adjacency List\n");
	
	for (x = 0; x <= i; x++)
	{
		printf("%d", x);
		for(y = 0; y <= j; y++) 
		{
			if (adjacency[x][y] == 1)
			{
				printf(" -> %d", y); 
			}
		}
		printf("\n");
	}
}

void DFS (int visited[MAX], int adjacency[MAX][MAX], int i, int j, int z)
{
	int w;
	visited[z] = 1;
    printf("%d,", z);
    for(w = 0; w <= j; w++)
    {
        if(adjacency[z][w] ==1 && visited[w] == 0)
        {
        	DFS(visited, adjacency, i, j, w);
		}
	}
}

int main()
{
	FILE *fp;
	char c;
	int adjacency[MAX][MAX];
	int visited[MAX] = {0};
	int i, j;
	
	i = 0;
	j = 0;
	fp = fopen(FILE_NAME, "r");
	
	if (fp)
	{
		init(adjacency);
		printf("Adjacency Matrix\n");
		while ((c = getc(fp)) != EOF)
		{
			if (c == '\n')
			{
				j++;
				i = 0;
				printf("%c", c);
			}
			else if (c == ' ')
			{
				printf("%c", c);
			}
			else
			{
				adjacency[i][j] = (c - '0');
				i++;
				printf("%d", (c - '0'));
			}
		}
		i--;
		printf("\n\n\n");
	    fclose(fp);
	}
	
	printAdjList(adjacency, i, j);
	
	printf("\n\nDFS : ");
	DFS(visited, adjacency, i, j, 0);
	
	return 0;
}

