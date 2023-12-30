#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    gets(str);
    int num = strlen(str);
    int n = str[0];
    if(n >= 65 && n <= 90)
    {
        printf(str);
    }
    else if(n >= 97 && n <= 122)
    {
        n = n - 32;
        printf("%c",n);
        for(int i=1; i < num; i++){
            printf("%c",str[i]);
        }
    }
}