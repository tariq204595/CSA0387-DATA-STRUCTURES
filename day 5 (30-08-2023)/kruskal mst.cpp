#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAX_VERTICES 100
struct Edge {
    int source, destination, weight;
};
struct Subset {
    int parent, rank;
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
int find(struct Subset subsets[], int vertex) {
    if (subsets[vertex].parent != vertex)
        subsets[vertex].parent = find(subsets, subsets[vertex].parent);
    return subsets[vertex].parent;
}
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}
void kruskalMST(struct Edge edges[], int numVertices, int numEdges) {
    struct Subset subsets[MAX_VERTICES];
    struct Edge result[MAX_EDGES];

    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    int resultIndex = 0;
    int edgeIndex = 0;

    while (resultIndex < numVertices - 1 && edgeIndex < numEdges) {
        struct Edge nextEdge = edges[edgeIndex++];
        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        if (x != y) {
            result[resultIndex++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d - %d: %d\n", result[i].source, result[i].destination, result[i].weight);
    }
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Edge edges[MAX_EDGES];

    printf("Enter the edges and their weights (source destination weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    kruskalMST(edges, numVertices, numEdges);

    return 0;
}
}
