#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES MAX_NODES * (MAX_NODES - 1) / 2

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = x;
    int yroot = y;

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int findSet(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = findSet(parent, parent[i]);
    }
    return parent[i];
}

void kruskalMST(int graph[MAX_NODES][MAX_NODES], int V) {
    int parent[MAX_NODES];
    int rank[MAX_NODES];
    int edges[MAX_EDGES][3]; // [src, dest, weight]
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges based on weight
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp[3];
                for (int k = 0; k < 3; k++) {
                    temp[k] = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp[k];
                }
            }
        }
    }
    int t=0;

    
    printf("Edge \tWeight\n");
    for (int i = 0; i < edgeCount; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        int weight = edges[i][2];

        int srcParent = findSet(parent, src);
        int destParent = findSet(parent, dest);
        
        if (srcParent != destParent) {
            printf("%d - %d \t%d\n", src, dest, weight);
            unionSets(parent, rank, srcParent, destParent);
            t+=weight;
        }
    }
    printf("Total weight: %d\n",t);
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

    kruskalMST(graph, V);
    

    return 0;
}
