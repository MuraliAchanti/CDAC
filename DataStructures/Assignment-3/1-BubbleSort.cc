#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void BubbleSort(int *arr,int size)
{   
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<(size-i-1);j++) 
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

}
int main()
{
    int arr[10] = {34,56,23,88,12,9,10,23,56,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}