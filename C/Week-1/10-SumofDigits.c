#include<stdio.h>
void SumofDigits(int num)
{
    int sum = 0;
    while(num!=0)
    {
        sum = sum + (num%10);
        num = num/10;
    }
    printf("Sum of Digits is %d\n",sum);
}
int main()
{
    int num;
    printf("Enter the number");
    scanf("%d",&num);
    SumofDigits(num);
}