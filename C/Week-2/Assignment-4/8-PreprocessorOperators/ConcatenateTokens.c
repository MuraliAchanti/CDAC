#include<stdio.h>
#define concat(a,b) a##b
int main()
{
    int xy = 30;
    printf("%d",concat(x,y)); 
}