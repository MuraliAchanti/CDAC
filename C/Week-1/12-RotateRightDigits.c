#include<stdio.h>
#include<math.h>
void RotateRight(int num,int r)
{
    int length;
    int og;
    og = num;
    int i;
    while(num!=0)
    {   
        length++;
        num=num/10;
    }
    num = og;
    int rotate = 0;
    for(i=0;i<r;i++)
    {
        int temp = num%10; 
        num = num/10;
        rotate = temp*pow(10,length-1);
        rotate  = rotate + num;
        num  = rotate;
    }
    printf("%d",rotate);
}
int main()
{
    int num,r;
    printf("Enter the number\n");
    scanf("%d",&num);
    printf("\nThe no of rotations");
    scanf("%d",&r); 
    RotateRight(num,r); 
}