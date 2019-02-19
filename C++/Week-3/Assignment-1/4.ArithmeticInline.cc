#include<iostream>
using namespace std;
inline int add(int a,int b)
{   
    return (a+b);
}
inline int substract(int a,int b)
{
    return abs(a-b);
}
inline int multiplication(int a,int b)
{
    return (a*b);
}
inline int divide(int a,int b)
{
    if(b==0)
        return -1;
    else
    {
        return (a/b);
    }
    
} 
int main()
{
    int a,b;
    printf("Enter the values");
    scanf("%d%d",&a,&b);
    printf("Addition - %d\n",add(a,b));
    printf("Substraction - %d\n",substract(a,b));
    printf("Multiplication - %d\n",multiplication(a,b));
    printf("Divide - %d",divide(a,b));
}