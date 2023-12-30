#include <iostream>
using namespace std;
int graph[10][10] = {0}, i, j, edge, vertex;
int k, v, visited[10], step = 1, connection[10];
int Queue[10], Front = 0, Rare = 0;
int main()
{
    cout << "Enter the number of vertices: ";
    cin >> vertex;
    cout << "enter the number of edge: ";
    cin >> edge;
    for (k = 1; k <= edge; k++)
    {
        cin >> i >> j;
        graph[i][j] = 1;
    }
    cout << "enter the starting vertex: ";
    cin >> v;
    cout << "BFS order: " << v << " ";
    visited[v] = 1;
    while (step < vertex)
    {
        for (j = 1; j <= vertex; j++)
        {
            if (graph[v][j] == 1 && visited[j] == 0 &&
                connection[j] == 0)
            {
                connection[j] = 1;
                Queue[Rare] = j;
                Rare = Rare + 1;
            }
        }
        v = Queue[Front];
        Front = Front + 1;
        cout << v << " ";
        visited[v] = 1;
        connection[v] = 0;
        step++;
    }
}
