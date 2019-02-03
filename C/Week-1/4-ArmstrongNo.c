#include<stdio.h>
#include<math.h>
int Armstrong_Check(int num)
{   
    int og = num;
    int check = 0;
    int temp = 0;
    while(num!=0)
    {   
        temp = num%10;
        check = check + pow(temp,3);
        num = num/10;
    }
    if(og == check)
        return 1;
    return 0;
}
int main()
{
    int val;
    printf("Enter the Number");
    scanf("%d",&val);
    if(Armstrong_Check(val))
        printf("Armstrong Number");
    else
        printf("Not an Armstrong Number");
    
}