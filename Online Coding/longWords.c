#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char str[101];
    for(int i=0; i<=n; i++)
    {
        gets(str);
        int length = strlen(str);
        if(length <= 10)
        {
            printf("\n");
            printf(str);
            printf("\n");
        }
        else if(length > 10)
        {
            printf("\n%c%d%c\n",str[0],(length-2),str[length-1]);
        }
    }
}