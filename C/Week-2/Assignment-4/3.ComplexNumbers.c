#include<stdio.h>
typedef struct 
{
    int x;
    int y;
}Complex;
int main()
{   
    Complex c1,c2;
    enum{add,substract};
    int choice;
    int x1,y1,x2,y2;
    printf("Enter the choice");
    scanf("%d",&choice);
    do
    {
    switch(choice)
    {
        case add:printf("Enter the numbers");
               scanf("%d%d%d%d",&c1.x,&c1.y,&c2.x,&c2.y);
               printf("%d + i%d",(c1.x+c2.x),(c1.y+c2.y));
               break;
        case substract:printf("Enter the numbers"); 
                       scanf("%d%d%d%d",&c1.x,&c1.y,&c2.x,&c2.y);
                       printf("%d + i%d",(c1.x-c2.x),(c1.y-c2.y));
                       break;
    }
    }while(choice!=-1);
}
