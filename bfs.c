#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Queue data structure
int queue[MAX_NODES];
int front = -1, rear = -1;

// Graph representation using adjacency matrix
int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

// Enqueue operation
void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1)
            front = 0;
        //rear++;
        queue[++rear] = node;
    }
}

// Dequeue operation
int dequeue() {
    int node;
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        node = queue[front++];
        //front++;
        if (front > rear) {
            front = rear = -1;
        }
        return node;
    }
}

// Breadth-First Search
void bfs(int start, int numNodes) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int currentNode = dequeue();
        printf("%d(%c)-> ", currentNode, currentNode+97);

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Initialize graph and visited array
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input connections
    printf("Enter the connections (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {  // Avoid redundant input and self-loop
            int connection;
            printf("Is node %d(%c) connected to node %d(%c)? ", i+1,i+97,j+1,j+97);
            scanf("%d", &connection);
            graph[i][j] = graph[j][i] = connection;
            
        }
        printf("-------------------------------------------------------\n");
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    bfs(startNode, numNodes);

    return 0;
}
