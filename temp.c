#include<stdio.h>
union s
{
    int x;
    char y;
};
int main()
{
    union s s1,s2;
    s1.x = 10;
    s1.y = 20;
    s2 = s1;
    printf("%d %d %d %d",&s1,&s2,&s1.x,&s1.y);
    printf("%d %d",s2.x,s2.y);
}