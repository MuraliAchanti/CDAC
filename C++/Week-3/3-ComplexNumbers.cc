#include<iostream>
using namespace std;
class Complex
{
    int real;
    int imaginary;
    public:
    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    Complex(int x)
    {
        real  =  x;
        imaginary = x;
    }
    Complex(int x,int y)
    {
        real  = x;
        imaginary = y;
    }
    friend void AddComplex(Complex &c1,Complex &c2);
    friend void MultiplyComplex(Complex &c1,Complex &c2);
};
void AddComplex(Complex &c1,Complex &c2)
{ 
    printf("%d + i%d\n",c1.real + c2.real,c1.imaginary + c2.imaginary); 
    return;
}
void MultiplyComplex(Complex &c1,Complex &c2)
{
    int result1,result2;
    result1 = ((c1.real)*(c2.real)) - ((c2.imaginary)*(c1.imaginary)); 
    result2 = (c1.real)*(c2.imaginary) + (c1.imaginary)*(c2.real); 
    printf("%d + i%d\n",result1,result2);
}
int main()
{
    Complex C1;
    Complex C2(3);
    Complex C3(4,5); 
    AddComplex(C2,C3);
    MultiplyComplex(C2,C3);
}