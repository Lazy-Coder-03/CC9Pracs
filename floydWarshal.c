#include <stdio.h>

#define INF 9999
#define MAX_VERTICES 100

void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int vertices)
{
    int dist[MAX_VERTICES][MAX_VERTICES];

    // Initialize the distance matrix with the given adjacency matrix
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the distance matrix
    for (int k = 0; k < vertices; ++k)
    {
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < vertices; ++j)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            if (dist[i][j] == INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (use -1 for no edge):\n");
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            if (i != j)
            {
                printf("Enter the weight of edge from %d to %d: ", i, j);
                scanf("%d", &graph[i][j]);
                if (graph[i][j] == -1)
                { // Assuming -1 represents INF
                    graph[i][j] = INF;
                }
            }
        }
    }

    floydWarshall(graph, vertices);

    return 0;
}
