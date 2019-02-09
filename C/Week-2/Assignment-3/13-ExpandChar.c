#include<stdio.h>
#include<string.h>
void ExpandChar(char *s)
{
    char expanded[100];
    int i;
    int k = 0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i] == '-')
        {   
            int j = 0;
            for(j = s[i-1]+1;j<s[i+1];j++,k++)
            {
                expanded[k] = j;
            }
        }
        else
        {
            expanded[k] = s[i];
            k++;
        }   
    }
    printf("%s",expanded);
}
int main()
{   
    char s[100];
    printf("Enter the string");
    scanf("%s",s);
    ExpandChar(s);
}