#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 7

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

int queue[MAX_VERTICES];
int front = 0;
int rear = -1;
int distance[MAX_VERTICES];
bool visited[MAX_VERTICES];

void enqueue(int vertex) {
    queue[++rear] = vertex;
}

int dequeue() {
    return queue[front++];
}

bool isQueueEmpty() {
    return front > rear;
}

void inputGraph(int vertices) {
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }
}

void BFS(int source, int destination, int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        distance[i] = -1;
    }

    visited[source] = true;
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
                visited[i] = true;
                distance[i] = distance[current] + 1;
                enqueue(i);
            }
        }
    }

    printf("There is no path from %d to %d\n", source, destination);
}

int main(void) {
    int vertices = MAX_VERTICES;
    int source_vertex, destination_vertex;

    inputGraph(vertices);

    printf("Enter the source vertex: ");
    scanf("%d", &source_vertex);
    printf("Enter the destination vertex: ");
    scanf("%d", &destination_vertex);

    if (source_vertex < 0 || source_vertex >= vertices || destination_vertex < 0 || destination_vertex >= vertices) {
        printf("Invalid source or destination vertex.\n");
        return 1;
    }
    printf("Calculating distance from vertex %d to %d:\n", source_vertex, destination_vertex);
    BFS(source_vertex, destination_vertex, vertices);
}


    // 0 1 0 1 0 0 0
    // 1 0 1 1 0 1 1
    // 0 1 0 1 1 1 0
    // 1 1 1 0 1 0 0
    // 0 0 1 1 0 0 1
    // 0 1 1 0 0 0 0
    // 0 1 0 0 1 0 0