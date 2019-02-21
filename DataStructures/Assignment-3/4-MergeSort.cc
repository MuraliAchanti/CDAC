#include<iostream>
using namespace std;
void MergeArray(int *arr,int low,int mid,int high)
{
    int low1 = low;
    int high1 = mid;
    int low2 = mid + 1;
    int high2 = high; 
    int size1 = mid - low + 1;
    int size2 = high2 - low2 + 1; 
    int new_arr[size1+size2];
    int i,j,k;
}
void Merge(int *arr,int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        Merge(arr,low,mid);
        Merge(arr,mid+1,high);  
        MergeArray(arr,low,mid,high);  
    }
}
int main()
{

}