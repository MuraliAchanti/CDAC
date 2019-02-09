#include<stdio.h>
#include<ctype.h> 
void LowerUpper(char *str)
{
    char  *og = str; 
    while(*str++ != '\0' )
    {   
        if(islower(*str))
            *str = *str-32;
        else if(isupper(*str))
            *str = *str+32;
    }
    printf("%s\n",og);
    return;
}
int main()
{
    char str[100];
    printf("Enter the string");
    scanf("%[^\n]s",str);
    LowerUpper(str);
}