#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Pair
{
    int first;
    int second;
} Pair;

int spanningTree(int V, int E, int edges[][3])
{
    int adj[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u][v] = wt;
        adj[v][u] = wt;
    }

    int res = 0;
    Pair *pq = (Pair *)malloc(V * sizeof(Pair));
    bool *visited = (bool *)malloc(V * sizeof(bool));

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        pq[i].first = INT_MAX;
        pq[i].second = i;
    }

    pq[0].first = 0;

    while (true)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && (u == -1 || pq[i].first < pq[u].first))
            {
                u = i;
            }
        }

        if (u == -1)
        {
            break;
        }

        visited[u] = true;
        res += pq[u].first;

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] != 0 && !visited[v] && adj[u][v] < pq[v].first)
            {
                pq[v].first = adj[u][v];
            }
        }
    }

    free(pq);
    free(visited);

    return res;
}

int main()
{
    int graph[][3] = {{0, 1, 5},
                      {1, 2, 3},
                      {0, 2, 1}};

    printf("Number of Spanning Tree Found:  %d\n", spanningTree(3, 3, graph));
    return 0;
}