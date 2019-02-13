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
}