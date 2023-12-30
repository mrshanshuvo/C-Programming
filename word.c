#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    gets(str);
    int length = strlen(str);
    int upper=0,lower=0;
    for(int i=0; i<length; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            upper++;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            lower++;
        }
    }
    if(upper > lower)
    {
        for(int i=0; i<length; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                int ascii = str[i]-32;
                printf("%c",ascii);
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
    if(upper <= lower)
    {
        for(int i=0; i<length; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                int ascii = str[i]+32;
                printf("%c",ascii);
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
}