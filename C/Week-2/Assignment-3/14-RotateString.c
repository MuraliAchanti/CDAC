#include<stdio.h>
#include<string.h>
void RotateString(char *str)
{
    int i;
    int len = strlen(str);
    for(i=0;i<len;i++)
    {   
        char s[1];
        char temp[100];
        s[0] = str[0];
        strcpy(temp,str+1); 
        strcat(temp,s); 
        printf("1 - %s\n",temp);
        strcpy(str,temp); 
    } 
}
int main()
{
    char str[100];
    printf("Enter the string");
    scanf("%s",str);
    RotateString(str);
}