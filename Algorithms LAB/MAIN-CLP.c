#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0}
};

int visited[MAX_VERTICES];
int startTime[MAX_VERTICES];
int finishTime[MAX_VERTICES];
int currentTime = 0;

void DFS(int vertex, int vertices) {
    visited[vertex] = 1;
    startTime[vertex] = ++currentTime;

    for (int i = 0; i < vertices; i++) {
        if (adjacency_matrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }

    finishTime[vertex] = ++currentTime;
}

int main() {
    int vertices = MAX_VERTICES;

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Depth-First Search Start and Finish Times:\n");
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i, vertices);
        }
    }

    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: Start Time = %d, Finish Time = %d\n", i, startTime[i], finishTime[i]);
    }

    return 0;
}
