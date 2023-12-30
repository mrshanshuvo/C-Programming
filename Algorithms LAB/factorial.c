#include<stdio.h>
int fact(int n)
{
    int sum = 0;
    if(n>0)
        return fact(n-1) * n;
    else
        return 1;
}

int main()
{
    int n = fact(5);
    printf("%d ",n);
}