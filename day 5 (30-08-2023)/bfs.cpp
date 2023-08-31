#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
#define QUEUE_SIZE 100
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
void bfs(struct Graph *graph, int startVertex) {
    bool visited[MAX_NODES] = {false};
    int queue[QUEUE_SIZE];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; ++i) {
            if (graph->adjacencyList[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
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

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth-First Traversal starting from vertex %d:\n", startVertex);
    bfs(&graph, startVertex);

    return 0;
}

