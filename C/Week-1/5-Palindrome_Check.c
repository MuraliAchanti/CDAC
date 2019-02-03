#include<stdio.h>
int PalindromeCheck(int num)
{
    int reverse = 0;
    int og = num;
    int temp = 0;
    while(num!=0)
    {   
        temp = num % 10;
        reverse = reverse*10 + temp;
        num = num/10;
    }   
    if(reverse == og)
        return 1;
    return 0;
}
int main()
{
    int num;
    printf("Enter the number");
    scanf("%d",&num);
    if(PalindromeCheck(num))
        printf("A Palindrome");
    else
    {
        printf("Not a Palindrome");
    }  
}