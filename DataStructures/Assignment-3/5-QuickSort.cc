#include<iostream>
using namespace std;
template<class T>void swap(T* a, T* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
template<class T>T partition (T arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);   
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
template<class T>void quickSort(T arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
template<class T>void printArray(T arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<" ";
    printf("\n"); 
} 
int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
} 