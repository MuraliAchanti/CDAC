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
                //cout<<"Stack Empty";
                return x;
            }
            x = stack.elements[stack.top--];
            return x; 
        }
        char Peek()
        {
            int x = -999;
            if(stack.top == -1)
            {
                //cout<<"Stack Empty";
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
                cout<<stack.elements[i];
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
void reverse(char *temp)
{   
    int n = strlen(temp);
    for(int i = 0,j = n-1;i<=(n/2);i++,j--)
    {
        char t = temp[i];
        temp[i] = temp[j];
        temp[j] = t;
    }
}
int main()
{
    char temp[100];
    cout<<"Enter the string";
    cin>>temp;
    _Stack_ s(20);
    char result[100];
    reverse(temp);
    int k = 0;
    for(int i=0;i<strlen(temp);i++)
    {
        char ch = temp[i];
        if(isdigit(ch) || isalpha(ch))
        {   
            result[k++] = ch;
        }
        else if(ch == ')')
        {
            s.Push(ch);
        }
        else if(ch == '(')
        {
            while(s.Peek() != ')')
            {
                result[k++] = s.Pop();
            }
            s.Pop();
        }
       else if(s.isEmpty())
       {
           s.Push(ch);
       }
       else if(Precedence(ch)>Precedence(s.Peek()))
       {
           s.Push(ch);
       }
       else
       {
           while(Precedence(ch)<=Precedence(s.Peek()))
           {
              result[k++] = s.Pop(); 
           }
           s.Push(ch);
       }
    }
    while(!s.isEmpty())
    {
        result[k++] = s.Pop();
    }
    result[++k] ='\0';
    reverse(result);
    cout<<result;
} 
