#include<stdio.h>
#include<string.h>
void DeleteChar(char *s,char ch)
{   
    char og[100];
    int i = 0;
    while(*s != '\0')
    {
        if(*s != ch)
        {   
            og[i++] = *s;
        }
        s++;
    }
    og[i] = '\0';
    printf("%s",og);
}
int main()
{
    char s[100];
    printf("Enter the String");
    scanf("%s%*c",s);
    char ch;
    printf("Enter the char");
    scanf("%c",&ch);
    DeleteChar(s,ch);
}