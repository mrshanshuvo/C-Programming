#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100], str2[100];

    gets(str1);
    gets(str2);
    int firstString=0, sceondString=0;

    for(int i=0; i<strlen(str1); i++)
    {
        if(str1[i] >= 'A' && str1[i] <= 'Z')
        {
            int count = str1[i] - 64;
            firstString = firstString + count;
        }
        else if(str1[i] >= 'a' && str1[i] <= 'z')
        {
            int count = str1[i] - 96;
            firstString = firstString + count;
        }
    }
    for(int i=0; i<strlen(str2); i++)
    {
        if(str2[i] >= 'A' && str2[i] <= 'Z')
        {
            int count = str2[i] - 64;
            sceondString = sceondString + count;
        }
        else if(str2[i] >= 'a' && str2[i] <= 'z')
        {
            int count = str2[i] - 96;
            sceondString = sceondString + count;
        }
    }
    if(firstString > sceondString)
    {
        printf("1");
    }
    else if(firstString == sceondString)
    {
        printf("0");
    }
    else if(firstString < sceondString)
    {
        printf("-1");
    }
}