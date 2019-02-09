#include<stdio.h>
#include<string.h>
void DeleteString(char *d,char  *s)
{
    int i,j;
    int  flag =  0;
    char mod[100];
    int k = 0;
    for(i=0;i<strlen(d);i++)
    {   
        flag  = 0;
        for(j=0;j<strlen(s);j++)
        {
            if(d[i] ==  s[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {   
            mod[k] = d[i]; 
            k = k+1;
        }
    }
    mod[k] = '\0';
    printf("The string is %s",mod);
}
int main()
{   
    char d[100];
    char s[100]; 
    printf("Enter the main string");
    scanf("%s",d);
    printf("Enter the second string");
    scanf("%s",s);
    DeleteString(d,s);
}