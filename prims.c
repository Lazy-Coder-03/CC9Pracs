#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_NODES 100

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX_NODES][MAX_NODES], int V) {
    printf("Edge \tPath \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t", parent[i], i);
        
        // Print the path from parent to current vertex
        int v = i;
        while (v != 0) {
            printf("%d(%c)", v, v + 65);
            v = parent[v];
            if (v != 0) {
                printf(" <- ");
            }
        }
        printf("\t%d\n", graph[i][parent[i]]);
    }
}


void primMST(int graph[MAX_NODES][MAX_NODES], int V) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    bool mstSet[MAX_NODES];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, V);
}

int main() {
    int V;

    printf("Enter the number of nodes: ");
    scanf("%d", &V);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the weights for each edge (0 for no connection):\n");
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            printf("Enter the weight for edge between %d(%c) and %d(%c): ", i + 1, i + 65, j + 1, j + 65);
            scanf("%d", &graph[i][j]);
            graph[j][i] = graph[i][j]; // Graph is undirected, so set symmetric value
        }
        printf("------------------------------------------------\n");
    }

    primMST(graph, V);

    return 0;
}
