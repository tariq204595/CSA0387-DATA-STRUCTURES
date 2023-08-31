#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Graph {
    int vertices;
    int adjacencyList[MAX_NODES][MAX_NODES];
};
void initializeGraph(struct Graph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->adjacencyList[i][j] = 0;
        }
    }
}
void addEdge(struct Graph *graph, int source, int destination) {
    graph->adjacencyList[source][destination] = 1;
    graph->adjacencyList[destination][source] = 1;
}
void dfs(struct Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->vertices; ++i) {
        if (graph->adjacencyList[vertex][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    struct Graph graph;
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    bool visited[MAX_NODES] = {false};
    printf("Depth-First Traversal starting from vertex 0:\n");
    dfs(&graph, 0, visited);

    return 0;
}

