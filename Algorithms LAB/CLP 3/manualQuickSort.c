#include <stdio.h>

int partition(int *A, int beg, int end)
{
    int left, right, temp, loc, flag;
    loc = left = beg;
    right = end;
    flag = 0;
    while (flag != 1)
    {
        while (A[loc] <= A[right] && (loc != right))
        {
            right--;
        }
        if (loc == right)
        {
            flag = 1;
        }
        else if (A[loc] > A[right])
        {
            temp = A[loc];
            A[loc] = A[right];
            A[right] = temp;
            loc = right;
        }
        if (flag != 1)
        {
            while ((A[loc] >= A[left]) && (loc != left))
            {
                left++;
            }
            if (loc == left)
            {
                flag = 1;
            }
            else if (A[loc] < A[left])
            {
                temp = A[loc];
                A[loc] = A[left];
                A[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}

void quickSort(int *A, int beg, int end)
{
    int loc;
    if (beg < end)
    {
        loc = partition(A, beg, end);
        quickSort(A, beg, loc - 1);
        quickSort(A, loc + 1, end);
    }
}

int main()
{
    int A[] = {5, 9, 11, 15, 18, 20, 26};
    int n = 7;
    quickSort(A, 0, n - 1);
    printf("The sorted Array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}