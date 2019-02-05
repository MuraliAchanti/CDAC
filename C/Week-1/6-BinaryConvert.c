#include<stdio.h>
#include<math.h>
void BinaryConvert(int num)
{   
    int length;
    length = log2(num) + 1;
    int i;
    int bits[length];
    for(i=0;i<length;i++)
    {
        bits[i] = num%2; 
        num = num/2;
    }
    printf("The Binary Representation is - ");
    for(i=length-1;i>=0;i--)
    {
        printf("%d",bits[i]);
    }
}
int main()
{
    int num = 0;
    printf("Enter a number");
    scanf("%d",&num);
    BinaryConvert(num);
}