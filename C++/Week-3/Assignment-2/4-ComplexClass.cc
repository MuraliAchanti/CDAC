#include<iostream>
using namespace std;
class Complex
{
    int real;
    int imaginary;
    int id;
    static int count;
    public:
    Complex()
    {
        real =  0;
        Count_Objects();
        this->id = count;  
        imaginary = 0;
    }
    Complex(int x,int y)
    {
        real = x;
        imaginary = y;
    }
    ~Complex()
    {   
        printf("Object %d is destroyed\n",this->id); 
        cout<<"Destructor Called"<<endl;
    }
    static void Count_Objects()
    {
        count++;
    }
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = this->real + c.real; 
        temp.imaginary = this->imaginary + c.imaginary;
        return temp; 
    }
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = this->real - c.real; 
        temp.imaginary = this->imaginary - c.imaginary;
        return temp; 
    }
    /*Complex operator=(Complex c)
    {
        this->real = c.real;
        this->imaginary = c.imaginary;
        return (*this);
    }*/
    Complex operator-()
    {
        Complex temp;
        temp.real =  -(this->real);
        temp.imaginary = -(this->imaginary); 
        return temp; 
    }
    Complex operator++()    
    {
        real = ++real;
        imaginary = ++imaginary;
        return *(this); 
    }
    Complex operator++(int x)
    {
        Complex temp;
        temp.real = ++real;
        temp.imaginary = ++imaginary;
        return temp; 
    }
    friend ostream& operator<<(ostream &cout,Complex c);
    friend istream& operator>>(istream &cin,Complex &c);
};
ostream& operator<<(ostream &cout,Complex c)
{
        cout<<"Real part\n"<<c.real;
        cout<<"Imaginary part"<<c.imaginary;
        cout<<endl; 
        return cout; 
}
istream& operator>>(istream &cin,Complex &c)
{   
    cout<<"Enter the real and imaginary part"; 
    cin>>c.real>>c.imaginary;
    return cin;
}
int Complex::count = 0;
int main()
{
    Complex c1(2,3);
    Complex c2(4,5);
    cout<<c1;
    Complex c3;
    cin>>c3;
}