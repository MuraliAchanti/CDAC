#include<stdio.h>
void PrimeNo(int a,int b)
{   
    int i,j;
    int flag;
    if(a==1)
        a++; 
    for(i=a;i<b;i++)
    {   
        flag = 0;
        for(j=2;j<(i/2)+1;j++)
        {
            if(i%j == 0)
            {   
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("%d ",i);
    }
}
int main()
{
    int a,b;
    printf("Enter the range");
    scanf("%d%d",&a,&b);
    PrimeNo(a,b);
}