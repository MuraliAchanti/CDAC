#include<iostream>
using namespace std;
void swap_value(int *x,int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    return;
}
void swap_reference(int &x,int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
    return;
}
int main()
{
    int x,y;
    printf("Enter the numbers");
    scanf("%d%d",&x,&y);
    printf("X = %d,Y = %d\n",x,y);
    int choice = 0;
    do
    {   
        printf("Enter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:printf("Swap by Value\n");
               swap_value(&x,&y);
               printf("X = %d,Y = %d\n",x,y);
               break;
        case 2:printf("Swap by Reference\n");
               swap_reference(x,y);
               printf("X = %d,Y = %d\n",x,y);
               break;
        default:printf("Exit");
                break;
        }
    }while(choice!=-1);
}