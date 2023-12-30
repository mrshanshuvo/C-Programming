#include<stdio.h>
#include<string.h>

char c[8] = {'A','B','C','D','E','F','G','S'};    // vertecies
int e[8] = {2,2,2,2,2,2,3,3};   // adjacency matrix
int list[8][3] = {{3,7},{4,7},{5,7},{0,6},{1,6},{2,6},{3,4,5},{0,1,2}};  //  vertex position in the array c
int checked[20], que[20], first = 0, last = 0;

void enq(int n)     // enqueue
{
    checked[n] = 1;
    que[last++] = n;
}

int dq()    // dequeue
{
    printf("%c ",c[que[first]]);
    first++;
    return que[first-1];
}

int notChecked(int n)   // checking the vertex
{
    if(checked [n] == 1)
        return 0;
    return 1;
}

int main(void)  // main function
{
    enq(7);
    while (first < last)
    {
        int n = dq();
        for(int i=0; i<e[n]; i++)
        {
            if(notChecked(list[n][i]) == 1)
                enq(list[n][i]);
        }
    }
}
