#include<iostream>
using namespace std;
class _Stack_
{
    struct sta
    {
        int top;
        char *elements;
        int size;
    }stack;
    public:
        _Stack_()
        { 
        }
        _Stack_(int size)
        {
            stack.size  = size;
            stack.elements = new char[size];
            stack.top = -1;
        }
        bool isEmpty()
        {
            if(stack.top == -1)
                return true;
            return false;
        }
        bool isFull()
        {
            if(stack.top  == stack.size - 1)
            {
                return true;
            }
            return false;
        }
        void Push(char x)
        {
            if(stack.top == stack.size - 1)
            {
                cout<<"Stack Full";
                return;
            }
            else
            {
                stack.elements[++stack.top] = x;
            }
        }
        char Pop()
        {   
            int x = -999;
            if(stack.top == -1)
            {
                cout<<"Stack Empty";
                return x;
            }
            else
            {
                x = stack.elements[stack.top--];
                return x;
            } 
        }
        char Peek()
        {
            int x = -999;
            if(stack.top == -1)
            {
                cout<<"Stack Empty";
                return x;
            }
            else
            {
                x = stack.elements[stack.top];
                return x;
            } 
        }
        void Display()
        {
            for(int i=0;i<=stack.top;i++) 
            {
                cout<<stack.elements[i]<<endl;
            }
        }
        /*void GetSize(int size)
        {   
            stack.size = size;
        }*/
        ~_Stack_()
        {
            delete (stack.elements);
        }
};
int Precedence(char x)
{
    if( x == '*' || x == '/')
        return  3;
    else if(x == '+' || x == '-')
        return 2;
    else   
        return 1;
}
int main()
{
    char temp[100];
    cout<<"Enter the infix String";
    cin>>temp;
    char ch;
    char output[10];
    for(int i=0;i<strlen(temp);i++)
    {
    }
}