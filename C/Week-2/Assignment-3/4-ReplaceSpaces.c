#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ReplaceSpaces(char *temp)
{   
    int count;
    char *og = temp;
    while(*temp != '\0')
    {
        if(*temp ==  ' ')
        {
            count++;
            *temp = '-';
        }
        temp = temp + 1; 
    }
    printf("%s\n",og);
    return count;
}
int main()
{
    char *s = "the cat sat";
    char *temp = (char *)malloc(sizeof(s));
    strcpy(temp,s);
    printf("The number of spaces are %d",ReplaceSpaces(temp)); 
}