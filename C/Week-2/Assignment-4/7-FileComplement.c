#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{   
    char str[100];
    char *s;
    s = str;
    FILE *fp;
    fp = fopen(argv[1],"w"); 
    printf("Enter a line");
    scanf("%s",str);
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] == '0')
            fputc('1',fp);
        else
            fputc('0',fp);
        
    }
    fclose(fp);
    char ch;
    fopen(argv[1],"r");
    printf("Original Data - ");
    while((ch=fgetc(fp))!=EOF)
    {   
        printf("%c",ch);
    }
    printf("\nComplemented Data - ");
    rewind(fp);
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch == '0')
            printf("1");
        else        
            printf("0");        
    }
}