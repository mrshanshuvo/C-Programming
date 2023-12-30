#include <stdio.h>
#include <stdlib.h>

int _lis(int arr[], int n, int *max_ref)
{
    if (n == 1)
        return 1;

    int res, max_ending_here = 1;

    for (int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;

    return max_ending_here;
}

int lis(int arr[], int n)
{
    int max = 1;

    _lis(arr, n, &max);

    return max;
}

int main()
{
    int arr[] = {9, 2, 5, 3, 7, 11, 8, 10, 13, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of lis is: %d", lis(arr, n));
    return 0;
}
