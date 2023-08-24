#include <stdio.h>
#include <stdbool.h>

// Stack for DFS
int stack[100];
int top = -1;

void push(int vertex) {
    if (top < 99)
        stack[++top] = vertex;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return -1;
}

void dfs_shortest_path(int startVertex, int numVertices, float adjacencyMatrix[][numVertices]) {
    bool visited[numVertices];
    int distance[numVertices]; // Keep track of distances
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
        distance[i] = -1; // Initialize distances as -1 (not reachable)
    }

    push(startVertex);
    visited[startVertex] = true;
    distance[startVertex] = 0;

    printf("DFS Shortest Path Distances from Vertex %d:\n", startVertex);
    while (top >= 0) {
        int currentVertex = pop();
        printf("Distance to vertex %d: %d\n", currentVertex, distance[currentVertex]);

        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] > 0 && !visited[i]) {
                push(i);
                visited[i] = true;
                distance[i] = distance[currentVertex] + 1;
            }
        }
    }
}

void printAdjacencyMatrix(int numVertices, float adjacencyMatrix[][numVertices]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%.2f ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Taking input for edge weights
    float adjacencyMatrix[numVertices][numVertices];
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) { // Avoid asking for repeated input
            float weight;
            printf("Enter the Weight of the edge between vertex %d and %d (enter 0 if not connected): ", i, j);
            scanf("%f", &weight);
            adjacencyMatrix[i][j] = weight > 0 ? 1 : 0;
            adjacencyMatrix[j][i] = adjacencyMatrix[i][j]; // Symmetric connection
        }
        adjacencyMatrix[i][i] = 0; // Set diagonal to 0
    }

    printAdjacencyMatrix(numVertices, adjacencyMatrix);

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfs_shortest_path(startVertex, numVertices, adjacencyMatrix);

    return 0;
}
