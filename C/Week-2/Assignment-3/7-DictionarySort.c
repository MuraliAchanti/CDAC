#include<stdio.h>
#include <string.h>
#include<stdlib.h>
void  DictionarySort(char str[][50],int num)
{   
    int i = 0;
    int j = 0;
    char temp[50];
    for(i=0; i<(num-1); ++i)
    {
        for(j=i+1; j<num ; ++j)
        {
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]); 
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}
int main()
{
    int i, j;
    int num;
    printf("Enter the number of strings");
    scanf("%d",&num);
    char str[num][50];
    for(i=0; i<num; ++i)
    {   
        scanf("%s",str[i]);
    }
    DictionarySort(str,num);
    for(i=0; i<num; ++i)
    {
        puts(str[i]);
    }
    return 0;
}