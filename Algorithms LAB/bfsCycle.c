#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100
// Function to add an edge between two vertices
void addEdge(int adj[][max], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to check for cycles in a connected component using BFS
bool isCyclicConnected(int adj[][max], int V, int s, bool visited[]) {
    int parent[max];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    // Create a queue for BFS
    int queue[max];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
                parent[v] = u;
            } else if (adj[u][v] && parent[u] != v) {
                return true;
            }
        }
    }
    return false;
}

// Function to check for cycles in the entire disconnected graph
bool isCyclicDisconnected(int adj[][max], int V) {
    bool visited[max];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicConnected(adj, V, i, visited)) {
            return true;
        }
    }
    return false;
}
int main() {
    int V = 4;
    int adj[max][max];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if (isCyclicDisconnected(adj, V)){
        printf("Cycle is Detected\n");
    } else {
        printf("There in no Cycle\n");
    }
}