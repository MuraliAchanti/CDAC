#include<stdio.h>
#include<string.h>
#include<math.h>
void DecBinary(int n)
{
    int og = n;
    int size = log2(n) + 1;
    int i = 0;
    int bits[size];
    for(i=0;i<size;i++)
    {
        bits[i] = og%2;
        og=og/2;
    }
    printf("Decimal to Binary\n");
    for(i=size-1;i>=0;i--)
        printf("%d",bits[i]);
    printf("\n");
}
void BinaryDec(char *s)
{
    int num = 0;
    int i;
    for(i=0;i<strlen(s);i++)
    {   
        int temp = s[i] - 48;
        num = num + temp*pow(2,i);
    }
    printf("Binary to Decimal\n");
    printf("%d",num);
}
int main()
{
    int num;
    char s[100];
    int choice;
    printf("Enter the Option\n");
    printf("1.Decimal to Binary\n2.Binary to Decimal\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the number");
                scanf("%d",&num);
                DecBinary(num);
                break;
        case 2:printf("Enter the Binary string\n");
               scanf("%s",s);
               BinaryDec(s);
               break;
        default:printf("Enter a valid option\n");
    }
}