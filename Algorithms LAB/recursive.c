#include<stdio.h>

void Test(int n)
{
    if(n>0)
    {
        for(int i=0; i<n; i++)
        {
            printf("%d ",i);
        }
        printf("\n");
        Test(n-1);
    }
    
}

int main()
{
    int n = 5;
    Test(n);
}