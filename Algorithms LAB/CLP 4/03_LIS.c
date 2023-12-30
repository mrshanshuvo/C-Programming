#include <stdio.h>

int longestSubSeq(int arr[], int n)
    {
        int lis[n];
        int i, j, max = 0;

        for (i = 0; i < n; i++)
            lis[i] = 1;

        for (i = 1; i < n; i++)
            for (j = 0; j < i; j++)
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        for (i = 0; i < n; i++)
            if (max < lis[i])
                max = lis[i];

        return max;
    }
int main()
{
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of Longest Increasing Subsequence is: %d", longestSubSeq(arr, n));
}