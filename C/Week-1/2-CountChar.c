#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void Count_Char(char *text);
int main()
{
    char *text;
    text = (char *)malloc(sizeof(char)*80);   
    printf("Enter the String");
    scanf("%[^\n]s",text);
    printf("%s",text);
    Count_Char(text);
}
void Count_Char(char *text)
{   
    int i;
    int alpha,digit,blank,tab = 0;
    for(i=0;i<(sizeof(text));i++)
    {   
        if(isalpha(text[i]))
        {
            alpha++;
        }
        else if(isdigit(text[i]))
        {
            digit++;
        }
        else if(text[i] == ' ')
        {
            blank++;
        }
        else if(text[i] == '\t')
        {
            tab++;
        }
    }
    printf("Alphabets = %d,Digits = %d,Blanks = %d,Tab = %d",alpha,digit,blank,tab);
}