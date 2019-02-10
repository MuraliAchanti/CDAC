#include<stdio.h>
struct data
{
    int x;
    char y;
};
union info
{
    int x;
    char y;
};
int main()
{
    struct data d;
    union info i;
    d.x = 10;
    d.y = 'A';
    i.x = 5;
    i.y = 'A';
    printf("Structure - ");
    printf("d.x = %d, d.y = %c and size = %lu\n",d.x,d.y,sizeof(d));
    printf("Union - i.x = %d , i.y = %c and size = %lu",i.x,i.y,sizeof(i));
}