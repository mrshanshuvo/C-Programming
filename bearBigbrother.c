
#include<stdio.h>
int main()
{
    int a,b,i,count = 0;
    scanf("%d%d",&a,&b);
    while (1)
    {
        count++;
        a = a*3;
        b = b*2;
        if(a > b)
        {
            printf("%d",count);
            break;
        }
    }
    
}