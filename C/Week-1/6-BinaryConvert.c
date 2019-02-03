#include<stdio.h>
#include<math.h>
void BinaryConvert(int num)
{   
    int bits[5];
    int i;
    for(i=0;i<5;i++)
        bits[i] = 0;
    for(i=0;i<5;i++)
    {
        bits[i] = num%2;
        num = num/2;
    }
    for(i=4;i>=0;i--)
        printf("%d",bits[i]);
}
int main()
{
    int num = 0;
    printf("Enter a number");
    scanf("%d",&num);
    BinaryConvert(num);
}