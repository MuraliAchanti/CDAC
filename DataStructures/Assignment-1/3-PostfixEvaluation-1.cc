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
    char temp[100];
    cout<<"Enter the postfix evaluation\n";
    cin>>temp;
    for(int i=0;i<strlen(temp);i++)
    {   
        char ch;
        ch = temp[i];
        if(isdigit(ch) && !s.isFull()) 
        {
            s.Push(ch - '0');  
        }
        else
        {   
            int a = s.Pop();
            int b = s.Pop();
            switch(ch)
            {
                case '+' : s.Push(b+a);
                            break;
                case '-' : s.Push(b-a);
                            break;
                case '*' : s.Push(b*a);
                            break;
                case '/' : s.Push(b/a);
                            break;
            }
        }
    }
    cout<<"Result = "<<s.Pop();
}
