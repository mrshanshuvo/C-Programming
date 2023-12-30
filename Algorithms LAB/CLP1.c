#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7

int adjacency_matrix[7][7] = {
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0}
};

int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = 0;
int rear = -1;

void enqueue(int vertex) {
    queue[++rear] = vertex;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front > rear;
}

void BFS(int start, int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0; // Initialize all vertices as unvisited
    }

    visited[start] = 1;
    enqueue(start);

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adjacency_matrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int vertices = 7;
    int start_vertex = 0;

    printf("Breadth-First Traversal starting from vertex %d:\n", start_vertex);
    BFS(start_vertex, vertices);

    return 0;
}
