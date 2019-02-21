#include<iostream>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void SelectionSort(int *arr,int size)
{
    int i,j;
    int min;
    for(i=0;i<size;i++)
    {   
        min = i;
        for(j=i+1;j<size;j++)
        {   
            if(arr[min] > arr[j])
                min = j;
        }
        swap(&arr[min],&arr[i]);  
    }
}
int main()
{
    int arr[10] = {34,56,23,88,12,9,10,23,56,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,size);
    for(int i=0;i<size;i++) 
    {
        cout<<arr[i]<<endl;
    }
}