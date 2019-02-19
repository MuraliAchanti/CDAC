#include<iostream>
using namespace std;
class Queue
{
    struct q
    {
        int *arr;
        int size;
        int front;
        int rear;
    }queue;
    public:
    Queue()
    {
        queue.arr = NULL;
        queue.size = 0;
    }
    Queue(int size)
    {
        queue.front = -1;
        queue.rear = -1;
        queue.arr = new int[size];
    }
    bool OverFlow()
    {
        if(queue.rear == queue.size-1)
        {
            cout<<"Queue Overflow"<<endl;
            return true;
        }
        return false;
    }
    bool UnderFlow()
    {
        if(queue.front == -1  && queue.rear  ==  -1)
        {
            cout<<"Queue Underflow"<<endl;
            return true;
        }
        return false;
    }
    void Enqueue(int ele)
    {   
        if(queue.rear!=queue.size-1)
        {
        if(queue.front == -1)
        {
            queue.front++;
        }
        queue.arr[++queue.rear] = ele; 
        }
        else
        {
            cout<<"Queue Overflow\n";
        }
    }
    int Dequeue()
    {   
        int x = -999;
        if(queue.front == -1 && queue.rear == -1)
        {   
            cout<<"Underflow\n";
        }
        else
        {   
            x = queue.front;
            ++queue.front;
            if(queue.front > queue.size-1)
            {
                queue.front = -1;
                queue.rear = -1;
            }
        }  
        return x;
    }
    void Display()
    {   
        if(queue.front == -1 && queue.rear == -1)
        {
            cout<<"Underflow\n";
        }
        else
        {
        cout<<"The Queue Elements are\n";
        for(int i=queue.front;i<=queue.rear;i++)
        {
            cout<<queue.arr[i]<<"\n";
        }
        }
    }
}; 
int main()
{
    Queue q(10);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Display();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();
}