#include<iostream>
using namespace std;
template<class T> int LinearSearch(T arr[],int n,T key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == key)
        {
            return i+1;
        }
    }
    return -1;
}
int main()
{
    int no_of_elements = 6;
    //cin>>no_of_elements;
    //int elements[no_of_elements];
    //cout<<"Enter the Elements"<<endl; 
    //for(int i=0;i<no_of_elements;i++)
        //cin>>elements[i];
    int key = -5;
    int elements[] = {1,5,7,5,3,10}; 
    //cout<<"Enter the element to be searched";
    //cin>>key;
    int temp = LinearSearch(elements,no_of_elements,key);
    if(temp == -1)
        cout<<"Element Not Found"<<endl;
    else
    {
        cout<<temp;
    }
    
}