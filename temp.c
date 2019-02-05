#include<stdio.h>
int main()
{
    char *p;
    int h = 20;
    int a;
    p = &h;
    a = *p;
    printf("%d %c",*p,a);    
}