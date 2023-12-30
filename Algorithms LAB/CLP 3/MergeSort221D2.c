#include <stdio.h>

int c[] = {90, 23, 101, 45, 65, 23, 67, 89, 34, 23};

void merge(int left, int mid, int right)
{
	int l = mid - left + 1;
	int r = right - mid;

	int L[10], R[10];

	for (int i = 0; i < l; i++)
	{
		L[i] = c[left + i];
	}
	for (int j = 0; j < r; j++)
	{
		R[j] = c[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;
	while (i < l && j < r)
	{
		if (L[i] <= R[j])
		{
			c[k++] = L[i++];
		}
		else
		{
			c[k++] = R[j++];
		}
	}
	while (i < l)
	{
		c[k++] = L[i++];
	}
	while (j < r)
	{
		c[k++] = R[j++];
	}
}

void mergesort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergesort(left, mid);
		mergesort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main()
{
	mergesort(0, 9);
	printf("Output: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", c[i]);
	}
	return 0;
}
