#include<iostream>
using namespace std;
template<class U> class Complex;
template <typename U> ostream& operator <<(ostream& cout, Complex<U> c); 
template<class T> int LinearSearch(T elements[],int size,T key)
{
    int i = 0; 
    for(i=0;i<size;i++)
    {   
        if(elements[i] ==  key)
        {
            return i+1;
        }
    }
    return  -1;
}
//specialization for specific data type
template<> int LinearSearch<const char *>(const char *str[],int  size,const char* key)    
{
    int i =  0;
    for(i=0;i<size;i++)
    {
        if(strcmp(str[i],key) == 0)
        {
            return  i+1;
        }
    }
    return -1;
}
template<class U> class Complex
{
    U real;
    U imaginary;
    public:
    Complex()
    {
        real = (U)0;
        imaginary = (U)0;
    }
    Complex(U x,U y)
    {
        real = x;
        imaginary = y;
    }
    Complex(Complex &c)
    {
        real = c.real;
        imaginary = c.imaginary;
    }
    friend ostream& operator<<<>(ostream& cout,Complex<U> c); 
};
template<class U> 
ostream& operator<<(ostream& cout,Complex<U> c)  
{ 
    cout<<"Imaginary Part - "<<c.imaginary;
    cout<<"  Real Part - "<<c.real;
    return cout;
}
int main()
{
    int arr[10]  = {2,3,4,5,6,2,65,24,52,44};
    int key = 44;
    printf("For integer values = %d",LinearSearch<int>(arr,10,key));
    float arr1[7] = {1.23,4.532,6.584,8.90,5.4,12.45,7.98};
    float key1  = 12.45;
    printf("\nFor Floating point elements = %d",LinearSearch<float>(arr1,7,key1)); 
    double arr2[6]  = {1.23567,1.4567,6.4667,3.6879,1.3333,9.04241};
    double key2 =  9.999;
    printf("\nFor Double elements =  %d",LinearSearch<double>(arr2,6,key2));
    const char *s[5] = {"arsenal","giroud","auba","laca","ramsey"};
    const char *key3 = "giroud"; 
    printf("\nFor String type elements = %d",LinearSearch<const char *>(s,5,key3)); 
    Complex<float> c1(2.5,3.5);
    cout<<c1<<endl;

}
/*template<typename T>
class Vec2 {
public:
    Vec2(T x, T y):x(x), y(y) {}

    friend std::ostream& operator <<(std::ostream& os, const Vec2 &vec)
    {
        return os << "x: " << vec.x << ", y: " << vec.y << std::endl;
    }
private:
    T x;
    T y;
};
template <typename T> class Vec2;

template <typename T>
std::ostream& operator <<(std::ostream& os, const Vec2<T>& vec);

template<typename T>
class Vec2 {
public:
    Vec2(T x, T y):x(x), y(y) {}

#if 0
    // Here all operator << <U> are friend
    template <typename U>
    friend std::ostream& operator <<(std::ostream& os, const Vec2<U> &vec);
#else
    // Here only the matching specialization is friend
    friend std::ostream& operator << <>(std::ostream& os, const Vec2& vec);
#endif

private:
    T x;
    T y;
};

template <typename T>
std::ostream& operator <<(std::ostream& os, const Vec2<T>& vec)
{
    return os << "x: " << vec.x << ", y: " << vec.y << std::endl;
}
*/