#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Stack data structure
int stack[MAX_NODES];
int top = -1;

// Graph representation using adjacency matrix
int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

// Push operation for stack
void push(int node) {
    if (top == MAX_NODES - 1) {
        printf("Stack is full\n");
    } else {
        //top++;
        stack[++top] = node;
    }
}

// Pop operation for stack
int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int node = stack[top--];
        //top--;
        return node;
    }
}

// Depth-First Search
void dfs(int start, int numNodes) {
    push(start);
    visited[start] = 1;
    printf("%d(%c)-> ", start, start + 97);

    while (top != -1) {
        int currentNode = stack[top];
        bool foundUnvisited = false;

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = 1;
                printf("%d(%c)-> ", i+1, i + 97);
                foundUnvisited = true;
                break;
            }
        }

        if (!foundUnvisited) {
            pop();
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

    printf("DFS traversal starting from node %d: ", startNode);
    dfs(startNode, numNodes);

    return 0;
}
