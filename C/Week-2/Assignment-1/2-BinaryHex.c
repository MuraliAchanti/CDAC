#include<stdio.h>
#include<math.h>
#include<string.h>
void BinaryHex(char *s)
{
    int num;
    int i;
    for(i=0;i<strlen(s);i++)
    {
        int temp;
        temp = s[i] - 48;
        num = num + temp*pow(2,i);
    }
    printf("The Hexadecimal number is %x",num);
}
void HexBinary(char *s)
{
    int num=0;
    int temp;
    int i;
    for(i=0;i<strlen(s);i++)
    {   
        if(s[i]>47 && s[i]<58)
            temp = s[i] - 48;
        else
            temp = s[i] - 55;
        num = num + temp*pow(16,i);
    }
    int length = log2(num)+1;
    int bits[length];
    for(i=0;i<length;i++)
    {
        bits[i] = num%2;
        num = num/2;
    }
    printf("Decimal Representation\n");
    for(i=length-1;i>=0;i--)
        printf("%d",bits[i]);
}
int main()
{   
    printf("Enter the choice\n");
    printf("1.Binary to Hexadecimal\n2.Hexadecimal to Binary\n");
    int choice;
    scanf("%d",&choice);
    char s[100];
    switch(choice)
    {
        case 1: printf("Enter the Binary string");
                scanf("%s",s);
                break;
        case 2: printf("Enter the Hexadecimal string");
                scanf("%s",s);
                HexBinary(s);
                break;
        default:printf("Enter a valid option");
    }
}