#include <stdio.h>
#include <stdbool.h>

// Queue for BFS
int queue[100];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == 99)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (front == -1)
        return -1;
    int vertex = queue[front];
    front++;
    if (front > rear)
        front = rear = -1;
    return vertex;
}

void bfs_shortest_path(int startVertex, int numVertices, float adjacencyMatrix[][numVertices]) {
    bool visited[numVertices];
    int distance[numVertices]; // Keep track of distances
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
        distance[i] = -1; // Initialize distances as -1 (not reachable)
    }

    enqueue(startVertex);
    visited[startVertex] = true;
    distance[startVertex] = 0;

    printf("BFS Shortest Path Distances from Vertex %d:\n", startVertex);
    while (front != -1) {
        int currentVertex = dequeue();
        printf("Distance to vertex %d: %d\n", currentVertex, distance[currentVertex]);

        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] > 0 && !visited[i]) {
                enqueue(i);
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
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                adjacencyMatrix[i][j] = 0;
            } else if (i < j) {
                float weight;
                printf("Enter the Weight of the edge between vertex %d and %d (enter 0 if not connected): ", i, j);
                scanf("%f", &weight);
                adjacencyMatrix[i][j] = weight > 0 ? 1 : 0;
                adjacencyMatrix[j][i] = adjacencyMatrix[i][j]; // Assuming symmetric connection
            }
        }
    }

    printAdjacencyMatrix(numVertices, adjacencyMatrix);

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    bfs_shortest_path(startVertex, numVertices, adjacencyMatrix);

    return 0;
}
