#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, a[1000], i, u = 0, c = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++)
		{
			if (a[i] == 0)
			{
				c++;
				if (c > u)
				{
					u = c;
				}
			}
			else
			{
				c = 0;
			}
		}
		printf("%d\n", u);
	}
	return 0;
}