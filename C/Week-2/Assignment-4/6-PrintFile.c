#include<stdio.h>
void PrintFile(char *ch)
{   
    static FILE *fp;
    static int i = 0;
    char c; 
    if(i == 0)
    {
        fp = fopen(ch,"r");
        c = fgetc(fp);
        printf("%c",c);
        i++;
        return PrintFile(ch); 
    }
    c = fgetc(fp);
    if(c!=EOF)
    {
        printf("%c",c);
        return PrintFile(ch); 
    }
    else
    {
        return;
    }
    
}
int main()
{   
    char ch[10];
    printf("Enter the file name"); 
    scanf("%s",ch);
    PrintFile(ch); 
}