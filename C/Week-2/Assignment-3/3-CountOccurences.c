#include<stdio.h>
int CountOccurences(char *s[],int n)
{
    int i = 0;
    int count = 0;
    int j = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;s[i][j]!='\0';j++)
        {
            if(s[i][j] == 'e')
                count++;
        }
    }
    return count;
}
int main()
{
    char *s[] = {"we will teach you how to","Move a mountain","Level a building","Erase the past","Make a million"};
    printf("%d",CountOccurences(s,5));
}