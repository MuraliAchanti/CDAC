#include<stdio.h>
int Reverse(int num)
{
    int reverse = 0;
    while(num!=0)
    {
        int temp = num%10;
        reverse = reverse*10 + temp;
        num = num/10; 
    }
    return reverse;
}
int main()
{
    int num;
    printf("Enter the number");
    scanf("%d",&num);
    printf("%d",Reverse(num));
}