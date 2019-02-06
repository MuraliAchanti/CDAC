#include<stdio.h>
void Rearrange(int *arr,int n)
{   
    int min;
    min = 0;
    int i,j,temp;
    i = 0;
    j = 0;
    int flag = 0;
    while(i<n)
    {
        if(arr[i]>0 && flag == 0)
        {
            j = i;
            flag = 1;
        }
        else if(flag == 1 && arr[i] < 0)
        { 
            temp = arr[i];
            arr[i] =  arr[j];
            arr[j] = temp;
            j = j+1;
        }
        i++;
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