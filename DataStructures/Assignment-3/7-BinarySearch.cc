#include<iostream>
using namespace std;
template<class T>T BinarySearch(T a[],int n,T key)
{
    int beg = 0;
    int end = n-1;
    while(beg<=end)
    {
        int mid = (beg+end)/2;
        if(a[mid] == key)   
            return mid+1;
        else if(a[mid] > key)
            end = mid-1;
        else if(a[mid] <  key)
            beg = mid+1;
    }
        return -1;
}
int main()
{   
    int no_of_elements = 6;
    //cin>>no_of_elements;
    int key = 10;
    int arr[] = {4,6,9,10,23,45};
    //for(int i=0;i<n;i++)
    // cin>>arr[i];
    int temp = BinarySearch<int>(arr,no_of_elements,key);
    if(temp == -1)
        printf("Element Not Found");
    else
    {
        cout<<temp;
    }
    

}