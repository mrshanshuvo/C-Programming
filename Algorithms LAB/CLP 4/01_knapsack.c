#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int knap[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                knap[i][w] = 0;
            else if (wt[i - 1] <= w)
                knap[i][w] = max(val[i - 1] + knap[i - 1][w - wt[i - 1]], knap[i - 1][w]);
            else
                knap[i][w] = knap[i - 1][w];
        }
    }
    return knap[n][W];
}
int main()
{
    int val[] = {12, 10, 20, 15};
    int wt[] = {2, 1, 3, 2};
    int W = 5;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Maximum total profit : %d", knapsack(W, wt, val, n));
    return 0;
}