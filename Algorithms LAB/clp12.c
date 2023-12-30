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
int distance[MAX_VERTICES]; // Array to store distances from the source
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

void BFS(int source, int destination, int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        distance[i] = -1; // Initialize distances to -1 (indicating unreachable)
    }

    visited[source] = 1;
    distance[source] = 0;
    enqueue(source);

    while (!isQueueEmpty()) {
        int current = dequeue();

        if (current == destination) {
            printf("Distance from %d to %d is %d\n", source, destination, distance[current]);
            return;
        }

        for (int i = 0; i < vertices; i++) {
            if (adjacency_matrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                enqueue(i);
            }
        }
    }

    printf("There is no path from %d to %d\n", source, destination);
}

int main() {
    int vertices = 7;
    int source_vertex = 0;
    int destination_vertex = 6;

    printf("Calculating distance from vertex %d to %d:\n", source_vertex, destination_vertex);
    BFS(source_vertex, destination_vertex, vertices);

    return 0;
}
