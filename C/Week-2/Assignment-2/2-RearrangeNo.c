#include<stdio.h>
void Rearrange(int *arr,int n)
{   
    int min;
    min = 0;
    int i,j,temp;
    i = 0;
    j = -1;
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        {   
            j++;
            int temp = arr[i];
            arr[i] = arr[j]; 
            arr[j] = temp;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
int main()
{
    int n;
    int i;
    printf("Enter the no. of elements");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array  ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    Rearrange(arr,n);
}