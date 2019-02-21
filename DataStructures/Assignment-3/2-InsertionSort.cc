#include<iostream>
using namespace std;
//Best for partially sorted arrays
void InsertionSort(int *arr,int size)
{   
    int j = 0;
    for(int i=1;i<size;i++)
    {   
        int temp = arr[i];
        for(j = i-1;j>=0 && arr[j]>temp;j--)
            arr[j+1] = arr[j];
        arr[j+1]=temp;
    }
}
int main()
{
    int arr[10] = {34,56,23,88,12,9,10,23,56,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr,size);
    for(int i=0;i<size;i++) 
    {
        cout<<arr[i]<<endl;
    }
}