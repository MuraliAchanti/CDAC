#include<iostream>
using namespace std;
template<class T>void merge(T arr[], int l, int m, int r)  
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	T L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
template<class T>void mergeSort(T arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 
		merge(arr, l, m, r); 
	} 
} 
template<class U>void printArray(U A[], int size)   
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout<<A[i]<<" ";
	printf("\n"); 
} 
int main() 
{ 
	float arr[] = {12.2, 11.45, 13.76, 5.99, 6.01, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	printf("Given array is \n"); 
	printArray(arr, arr_size);  

	mergeSort<float>(arr, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
} 


/*#include<iostream>
using namespace std;
template<class T>void merge(T *arr,int l,int m,int r)
{
	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    T L[n1];
	T R[n2]; 
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;  
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}
template<class T>void mergesort(T *arr,int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main()
{
	int no_of_elements;
	//cin>>no_of_elements;
	int elements[] = {12, 11, 13, 5, 6, 7}; 
	//cout<<"Enter the elements"<<endl;
	//for(int i=0;i<no_of_elements;i++)
		//cin>>elements[i];
	mergesort<int>(elements,0,no_of_elements-1); 
	for(int i=0;i<sizeof(elements)/sizeof(elements[0]);i++)
		cout<<elements[i]<<" ";
}*/