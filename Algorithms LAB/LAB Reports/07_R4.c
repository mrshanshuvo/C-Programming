#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5  // Number of vertices

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[V][V], int src, int vertexCost[]) {
    int dist[V];  // The output array dist[i] holds the shortest distance from src to i

    // sptSet[i] will be true if vertex i is included in the shortest
    // path tree or the shortest distance from src to i is finalized
    bool sptSet[V];

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = vertexCost[src];

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] + vertexCost[v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v] + vertexCost[v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Example graph represented by an adjacency matrix
    int graph[V][V] = {
        {0, 1, 4, 0, 0},
        {0, 0, 2, 5, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0}
    };

    // Example vertex costs
    int vertexCost[V] = {1, 2, 3, 4, 5};

    // Source vertex
    int src = 0;

    // Run Dijkstra's algorithm
    dijkstra(graph, src, vertexCost);

    return 0;
}
