#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char buffer[100];
int index1= 0;
char * STRTOK(char *str,char ch)
{   
    char *s;
    int i = 0;
    if(str[index1] == '\0')
    {
    return NULL;
    }
    if(index1 != 0)
    {
    index1++;
    }
    s = str+index1;
    while((*s!=ch) && (*s!='\0'))
    {
        buffer[i++] = *s;
        index1++;
        s++;
    }    
    buffer[i] = '\0';
    return buffer;
}
int main()
{   
    char s[100];
    char delimiter;
    printf("Enter the string");
    gets(s);
    printf("%d",strlen(s));
    printf("Enter the delimiter");
    scanf("%c",&delimiter);
    char *p;
    p = STRTOK(s,delimiter);
    while(p)
    {   
        printf("%s\n",p);
        p = STRTOK(s,delimiter);
    }
}