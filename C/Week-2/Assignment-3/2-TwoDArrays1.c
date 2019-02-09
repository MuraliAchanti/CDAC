#include<stdio.h>
int main()
{
    char *color[6] = {"red","green","blue","white","black","yellow"};
    //array of character pointers each pointing to a string
    printf("%lu\n",color);
    printf("%lu\n",&color);
    printf("%d\n",sizeof(color));
    printf("%lu\n",(color+2));
    //contains the address of the 3 string
    printf("%s\n",*color);
    printf("%s\n",*(color+2));
    //returns the  first string
}