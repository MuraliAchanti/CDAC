#include<stdio.h>
#include<string.h>
void Reverse(char *s,int i,int  j)
{
    if(i>j)
        return;
    else
    {
        char temp;
        temp = s[i];
        s[i]  = s[j];
        s[j] = temp;
        return Reverse(s,i+1,j-1); 
    }
    
}
int main()
{
    char s[100];
    printf("Enter the string");
    scanf("%s",s);
    Reverse(s,0,strlen(s)-1);
    printf("%s",s);
}