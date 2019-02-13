#include<stdio.h>
//only constant expression in #if
#define a 20
#if a<10
#define a 120
#elif a<20
#define a 130
#else
#define a 140
#endif
#ifdef a
#define b 120 
#endif
int main()
{
    printf("a = %d b = %d",a,b);
}