#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int src, dest, weight;
} Edge;
typedef struct {
    int parent, rank;
} Subset;
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void kruskal(Edge edges[], int V, int E) {
    Edge result[V]; // Array to store the MST
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    for (i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    i = 0; // Index for sorted edges
    while (e < V - 1) { // We need exactly V-1 edges in the MST
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
    free(subsets);
}
int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    kruskal(edges, V, E);
    return 0;
}

