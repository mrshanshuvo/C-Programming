#include <stdio.h>

int countCombinations(int coins[], int n, int N)
{
    int dp[N + 1];
    for (int i = 0; i <= N; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= N; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[N];
}

int main()
{
    int coins[] = {1, 5, 10};
    int n = sizeof(coins) / sizeof(coins[0]);

    int N;
    printf("Enter the amount (N): ");
    scanf("%d", &N);

    int combinations = countCombinations(coins, n, N);

    printf("Number of combinations to make %d taka: %d\n", N, combinations);

    return 0;
}
