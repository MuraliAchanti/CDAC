#include<stdio.h>
#include<stdlib.h>
void SubArraySum(int *a,int n,int sum1)
{
    int i,j;
    int sum = 0;
    for(i=0;i<n;i++)
    {   
        sum = 0;
        for(j=i;j<n;j++)
        {
            sum = sum + a[j];
            if(sum == sum1)  
            {   
            printf("%d %d",i,j);
            return;
            }
        }
    }
    printf("0");
    return;
}
int main()
{
    int n,i;
    int sum;
    printf("Enter the number of elements");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the required Sum");
    scanf("%d",&sum);
    SubArraySum(a,n,sum);
}