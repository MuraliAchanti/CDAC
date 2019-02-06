#include<stdio.h>
int HexComplement(int num)
{
    return (~num);
}
int Masking(int num)
{
    int oper;
    int choice;
    printf("Enter the number\n");
    scanf("%X",&oper);
    printf("1.And\t2.Or\t3.Ex-Or\n");
    printf("Enter the choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:return (num & oper);
               break;
        case 2:return (num | oper);
               break;
        case 3:return (num ^ oper);
               break;
        default:printf("Invalid Option\n"); 
                break;
    }
    return -1;
}
int Shifting(int num)
{
    int choice;
    int bits;
    printf("1.Right Shift\n2.Left Shift\n");
    printf("Enter the type of shift\n");
    scanf("%d",&choice);
    printf("Enter the no of bits");
    scanf("%d",&bits);
    switch(choice)
    {
        case 1: return (num >> bits);
                break;
        case 2: return (num << bits);
                break;
        default: printf("Invalid Option");
                 break;
    }
    return  -1;
}
int main()
{
    int num;
    int choice;
    printf("Enter the hexadecimal number ");
    scanf("%X",&num);
    do
    {
    printf("1.One's Complement\n2.Masking\n3.Shifting\n4.Exit\n");
    printf("Enter the choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("The One's Complement in Hexadecimal is %X\n",HexComplement(num));
               break;
        case 2:printf("The solution is %X\n",Masking(num));
               break;
        case 3:printf("The solution is %X\n",Shifting(num));
               break;
    }
    } while(choice!=4); 
}