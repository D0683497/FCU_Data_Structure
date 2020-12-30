#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge
{
    int src;
	int dest;
	int weight;
} Edge;

typedef struct Graph
{
    int V;
	int E;
    Edge* edge;
} Graph;

typedef struct Subset
{
    int parent;
    int rank;
} Subset;

Graph* CreateGraph(int V, int E)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(sizeof(Edge) * E);
 
    return graph;
}

Graph* InitGraph(Graph* graph)
{
	// add edge 0-1 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 14;
    // add edge 0-5
	graph->edge[1].src = 0;
    graph->edge[1].dest = 5;
    graph->edge[1].weight = 10;
    // add edge 0-6
	graph->edge[2].src = 0;
    graph->edge[2].dest = 6;
    graph->edge[2].weight = 20;
    // add edge 1-2
	graph->edge[3].src = 1;
    graph->edge[3].dest = 2;
    graph->edge[3].weight = 11;
    // add edge 1-3
	graph->edge[4].src = 1;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 21;
	// add edge 1-6
	graph->edge[5].src = 1;
    graph->edge[5].dest = 6;
    graph->edge[5].weight = 19;
	// add edge 2-3
	graph->edge[6].src = 2;
    graph->edge[6].dest = 3;
    graph->edge[6].weight = 23;
	// add edge 3-4
	graph->edge[7].src = 3;
    graph->edge[7].dest = 4;
    graph->edge[7].weight = 9;
	// add edge 4-5 
	graph->edge[8].src = 4;
    graph->edge[8].dest = 5;
    graph->edge[8].weight = 30;
	// add edge 4-6
	graph->edge[9].src = 4;
    graph->edge[9].dest = 6;
    graph->edge[9].weight = 25;
	// add edge 5-6
	graph->edge[10].src = 5;
    graph->edge[10].dest = 6;
    graph->edge[10].weight = 13;
	// add edge 5-7  
	graph->edge[11].src = 5;
    graph->edge[11].dest = 7;
    graph->edge[11].weight = 15;
    
    return graph;
}

int Find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
    	subsets[i].parent = Find(subsets, subsets[i].parent);
	} 
 
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y)
{
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
    	subsets[xroot].parent = yroot;
	}
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
    	subsets[yroot].parent = xroot;
	}
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

/* qsort �һݪ�����禡 */
int Compare(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    
    if (a1->weight > b1->weight)
    {
    	return 1;
	}
	else if (a1->weight < b1->weight)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void KruskalMST(Graph* graph)
{
	int V = graph->V;
    Edge result[V]; // Tnis will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    qsort(graph->edge, graph->E, sizeof(Edge), Compare);
 
    Subset* subsets = (Subset*)malloc(sizeof(Subset) * V);
 
    for (int v = 0; v < V; ++v)
	{
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    printf("Kruskal Algorithm\n");
    printf("--------------\n");
    while (e < V - 1 && i < graph->E)
	{
        Edge next_edge = graph->edge[i++];
        
        int x = Find(subsets, next_edge.src);
        int y = Find(subsets, next_edge.dest);
 
        if (x != y)
		{
            result[e++] = next_edge;
            printf("%dth : Link:%d-%d Weight:%d\n", e, next_edge.src, next_edge.dest, next_edge.weight);
            Union(subsets, x, y);
        }
        else
        {
        	printf("%dth : Link:%d-%d Weight:%d\n", e, next_edge.src, next_edge.dest, next_edge.weight);
        	printf("Waring:It cause the cycle\n");
		}
    }
    printf("--------------\n");
	printf("End\n");
}

int main()
{
	int V = 8; // Number of vertices in graph(���I)
    int E = 12; // Number of edges in graph(��) 
    
    Graph* graph = CreateGraph(V, E);
    graph = InitGraph(graph);
    
    KruskalMST(graph);
	
	return 0;
}

