#include<stdio.h>
int CountOnes(int num)
{   
    int i = 0;
    int count = 0;
    while(num!=0)
    {
        if(num%2 == 1)
            count++;
        num = num/2;
    }
    return count;
}
int CountOnes1(char *bits)
{
    int i;
    int count = 0;
    for(i=0;i<8;i++)
    {
        if(bits[i] == '1')
            count++;
    }
    return count;
}
int main()
{   
    int num;
    char bits[8];
    int choice;
    printf("1.As a number\n2.As bits");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the number ");
               scanf("%d",&num);
               printf("Number of set bits are %d",CountOnes(num));
               break;
        case 2:printf("Enter the bits ");
               scanf("%s",bits);
               printf("Number of set bits are %d",CountOnes1(bits));
               break;
    }
}