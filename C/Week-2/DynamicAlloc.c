#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   /* Dynamic Columns and Rows
    char **arr;
    int i;
    arr = (char **)malloc(sizeof(char *)*5);
    for(i=0;i<5;i++)
    {
        arr[i] = (char *)malloc(sizeof(char)*5);
        strcpy(arr[i],"jack");
    }
    printf("%s",arr[1]);
    */
   /*Fixed Rows Dynamic Columns
   int i = 0;
   char *s[5];
   for(i=0;i<5;i++)
   {
       s[i] = (char *)malloc(sizeof(char)*5);
       strcpy(s[i],"Jack");   
       printf("%s",s[i]);
   }*/  
   char (*s1)[20];
}