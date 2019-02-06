#include<stdio.h>
int main()
{
    int arr[] = {10,20,30,40,50,60,70,80};
    printf("%d\n",arr);
    printf("%d\n",(arr+2));
    printf("%d\n",&arr); 
    printf("%d\n",*arr);
    printf("%d\n",(*arr+2));
    printf("%d\n",*(arr+2));
}