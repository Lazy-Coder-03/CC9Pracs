#include <stdio.h>

#define INF 9999
#define MAX_VERTICES 100

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex, int destinationVertex)
{
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int prev[MAX_VERTICES];

    for (int i = 0; i < vertices; ++i)
    {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < vertices - 1; ++count)
    {
        int minDist = INF;
        int minVertex = -1;

        // Find the vertex with the minimum distance among the unvisited vertices
        for (int v = 0; v < vertices; ++v)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                minVertex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minVertex] = 1;

        // Update the distances of adjacent vertices
        for (int v = 0; v < vertices; ++v)
        {
            if (!visited[v] && graph[minVertex][v] != INF &&
                dist[minVertex] + graph[minVertex][v] < dist[v])
            {
                dist[v] = dist[minVertex] + graph[minVertex][v];
                prev[v] = minVertex;
            }
        }
    }

    // Print the shortest path and distance
    printf("Shortest path from vertex %d to vertex %d:\n", startVertex, destinationVertex);
    int current = destinationVertex;
    while (current != -1)
    {
        printf("%d ", current);
        current = prev[current];
    }
    printf("\nShortest distance: %d\n", dist[destinationVertex]);
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
        for (int j = i + 1; j < vertices; ++j)
        {
            int connection;
            printf("Enter the weight of edge from %d to %d: ", i + 1, j + 1);
            scanf("%d", &connection);
            graph[i][j] = graph[j][i] = connection;
            if (graph[i][j] == -1)
            {
                graph[i][j] = INF;
            }
        }
    }

    int startVertex, destinationVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    printf("Enter the destination vertex: ");
    scanf("%d", &destinationVertex);

    dijkstra(graph, vertices, startVertex, destinationVertex);

    return 0;
}