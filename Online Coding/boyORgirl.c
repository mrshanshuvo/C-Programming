#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int n = strlen(str);

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(str[i] == str[j])
            {
              str[i] = '0';
            }
        }
    }

    int num = 0;

    for(int i=0; i<n; i++)
    {
      if(str[i] != '0')
      {
        num++;
      }
    }

    if(num % 2 == 0)
    {
        printf("CHAT WITH HER!");
    }
    else
    {
        printf("IGNORE HIM!");
    }
}