#include<iostream>
using namespace std;
class _Stack_
{
    struct sta
    {
        int top;
        int *elements;
        int size;
    }stack;
    public:
        _Stack_()
        { 
        }
        _Stack_(int size)
        {
            stack.size  = size;
            stack.elements = new int[size];
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
        void Push(int x)
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
        int Pop()
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
        int Peek()
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
int main()
{
    _Stack_ s(10);
    s.Pop();
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(3);
    cout<<s.Peek()<<endl;
    cout<<s.Pop()<<endl;
    s.Display();
}
