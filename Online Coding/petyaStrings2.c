#include <stdio.h>
#include <string.h>
int main ()
{
    char str1[100], str2[100];
    gets(str1);
    gets(str2);

    int ret;

    ret = stricmp(str1, str2);

    if(ret > 0)   printf("1");

    else if(ret < 0)  printf("-1");

    else      printf("0");
}