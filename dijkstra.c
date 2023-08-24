#include <stdio.h>

#define INF 9999
#define MAX_VERTICES 100

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < vertices; ++i) {
        dist[i] = INF;
    }
    
    dist[startVertex] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int minDist = INF;
        int minVertex = -1;
        
        // Find the vertex with the minimum distance among the unvisited vertices
        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minVertex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minVertex] = 1;

        // Update the distances of adjacent vertices
        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && graph[minVertex][v] != INF && 
                dist[minVertex] + graph[minVertex][v] < dist[v]) {
                dist[v] = dist[minVertex] + graph[minVertex][v];
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances from vertex %d:\n", startVertex);
    for (int i = 0; i < vertices; ++i) {
        printf("To %d: ", i);
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (use -1 for no edge):\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (i != j) {
                printf("Enter the weight of edge from %d to %d: ", i+1, j+1);
                scanf("%d", &graph[i][j]);
                if (graph[i][j] == -1) {
                    graph[i][j] = INF;
                }
            } else {
                graph[i][j] = INF;
            }
        }
    }
    
    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dijkstra(graph, vertices, startVertex);

    return 0;
}

