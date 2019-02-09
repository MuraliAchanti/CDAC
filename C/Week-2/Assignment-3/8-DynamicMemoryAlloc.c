#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char (*str)[10];
    int num;
    printf("Enter the number of strings");
    scanf("%d",&num);
    int i;
    str = (char (*)[10])malloc(num*10);
    for(i=0;i<num;i++)
    {
        scanf("%s",str[i]);
    }
    for(i=0;i<num;i++)
        printf("%s\n",str[i]);
}