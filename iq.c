#include<stdio.h>
int main()
{
    int n,x,i,j,r1,r2,even=0,odd=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x%2==0)
        {
            r1=i;
            even++;
        }
        else
        {
            r2=i;
            odd++;
        }
    }
    if(even==1)
        printf("%d",r1);
    else
        printf("%d",r2);
}