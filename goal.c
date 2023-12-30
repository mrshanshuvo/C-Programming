#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,s=0;
        scanf("%d",&n);
        while(n-->1)
        {
        int g;
        scanf("%d",&g);
        s += g;
        }
        printf("%d\n",-1*s);
    }
    return 0;
}