#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100
int minDistance(int distances[], bool visited[], int vertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}
void printShortestPath(int distances[], int parent[], int source, int vertices) {
    printf("Vertex\tDistance from Source\tPath\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\t\t\t", i, distances[i]);
        int j = i;
        while (j != source) {
            printf("%d <- ", j);
            j = parent[j];
        }
        printf("%d\n", source);
    }
}


void dijkstra(int graph[MAX_NODES][MAX_NODES], int source, int vertices) {
    int distances[MAX_NODES];
    bool visited[MAX_NODES];
    int parent[MAX_NODES];

    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[source] = 0;
    parent[source] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(distances, visited, vertices);
        visited[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printShortestPath(distances, parent, source, vertices);
}

int main() {
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, vertices);

    return 0;
}

