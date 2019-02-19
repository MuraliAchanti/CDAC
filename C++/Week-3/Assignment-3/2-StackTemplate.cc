#include<iostream>
using namespace std;
#define SIZE 100
template<class T> class Stack; 
template<class T> ostream& operator<<(ostream& cout,Stack<T> &s);
template <class T> class Stack
{
    T elements[SIZE];
    int top;
    public:
    Stack()
    {
        top = -1; 
    }
    void Push(T ele)
    {   
        if(top == SIZE - 1)
            cout<<"Stack Overflow";
        elements[++top] = ele;
    }
    T Pop()
    {   
        if(top == -1)
            cout<<"Stack Underflow";
        return (top--);
    }
    friend ostream& operator<<<T>(ostream& cout,Stack &s);  
    void Display(Stack &s){
        
    }
}; 
template<class T>
ostream& operator<<(ostream& cout,Stack<T> &s)
{
    int i = 0;
    cout<<"Stack Elements are"<<endl;
    for(i=0;i<=s.top;i++)
    {   
        cout<<s.elements[i]<<" "<<endl;
    }
    return cout;
}

void Stack<float>::Display(Stack<float> &s)   
{ 
 
}
int main()
{
    Stack<int> istack;
    istack.Push(1);
    istack.Push(1);
    istack.Push(2);
    istack.Pop();
    cout<<istack;
    Stack<float> fstack;
    fstack.Push(1.234);
    fstack.Push(2.567);
    fstack.Pop();
    fstack.Pop();
    cout<<fstack;
}