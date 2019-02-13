#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    FILE *fp;
    fp = fopen("test.txt","w+");
    char string[100];
    printf("Enter the string");
    scanf("%[^\n]s",string);
    int len = strlen(string);
    int i = 0;
    for(i=0;i<len;i++)
    {   
        if(isupper(string[i]))
        {
            fputc(tolower(string[i]),fp);
        }
        else 
        {
            fputc(toupper(string[i]),fp);
        }
    }
    fseek(fp,0,SEEK_SET);
    char ch;
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    printf("\n%ld",ftell(fp));
    fclose(fp);
}