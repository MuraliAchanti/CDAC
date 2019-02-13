#include<stdio.h>
#define stringify(s) (#s)
#define add(a,b) (a+b)
int main()
{
    printf("%s\n",stringify(arsenal));
    printf("%s\n",stringify(This is arsenal));
    printf("%d",add(2,3));
}