#include <stdio.h>
#include <stdlib.h>

int MAX_VERTICES = 100;

int queue[100];
int front = 0;
int rear = -1;

int in_degree[100];

void enqueue(int vertex)
{
    if (rear == MAX_VERTICES - 1)
    {
        printf("Queue is full!\n");
        return;
    }

    queue[++rear] = vertex;
}

int dequeue()
{
    if (front > rear)
    {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue[front++];
}

void topologicalSort(int vertices, int edges, int adjacency_matrix[][vertices])
{
    for (int i = 0; i < vertices; i++)
    {
        in_degree[i] = 0;
    }

    for (int i = 0; i < edges; i++)
    {
        int source = adjacency_matrix[i][0];
        int destination = adjacency_matrix[i][1];

        in_degree[destination]++;
    }

    for (int i = 0; i < vertices; i++)
    {
        if (in_degree[i] == 0)
        {
            enqueue(i);
        }
    }

    while (front <= rear)
    {
        int vertex = dequeue();

        for (int i = 0; i < vertices; i++)
        {
            if (adjacency_matrix[vertex][i] == 1)
            {
                in_degree[i]--;

                if (in_degree[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
        printf("%d ", vertex);
    }
}

int main()
{
    int vertices = 7;
    int edges = 11;

    int adjacency_matrix[7][7] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0}};

    printf("Following is a Topological Sort of the given graph:\n");
    topologicalSort(vertices, edges, adjacency_matrix);

    return 0;
}
