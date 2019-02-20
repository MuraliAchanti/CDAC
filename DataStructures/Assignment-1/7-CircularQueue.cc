#include<iostream>
using namespace std;
class CircularQueue
{
    struct Q
    {
        int *arr;
        int size;
        int front;
        int rear;
    }queue;
    public:
    CircularQueue(int size)
    {
        queue.front  = -1;
        queue.rear = -1;
        queue.size = size;
        queue.arr = new int[size];
    }
    bool OverFlow()
    {
        if(queue.front == ((queue.rear+1)%(queue.size)))
        {  
            cout<<"Overflow\n";
            return true;
        }
        return false;        
    }
    bool UnderFlow()
    {
        if(queue.front == -1 && queue.rear == -1)
        {
            cout<<"Underflow\n";
            return true;
        }
        return false;
    }
    void Enqueue(int ele)
    {
        if(queue.front == ((queue.rear+1)%(queue.size)))
        {
            cout<<"aaaa";
            cout<<"OverFlow\n";
        }
        if(queue.front == -1)
            queue.front = 0;
        queue.rear = (++queue.rear)%queue.size;
        queue.arr[queue.rear] = ele;
    }
    int Dequeue()
    {
        int x = -999;
        if(queue.front == -1 && queue.rear == -1)
        {
            cout<<"UnderFlow\n";
        }
        else
        {   
            x = queue.arr[queue.front];
            if(queue.front == queue.rear)
            {
                queue.front = -1;
                queue.rear = -1;
            }
            else
            {
            queue.front  =  (++queue.front)%(queue.size);
            }
        }
        return  x;
    }
    void Display()
    {   
        if(queue.front != -1 && queue.rear != -1)
        {
        int i;
        cout<<"The Queue Elements are\n";
        for(i=(queue.front);i!=queue.rear;(i=(i+1)%queue.size)) 
        {
            cout<<queue.arr[i]<<endl;
        }
        cout<<queue.arr[i]<<endl;
        }
        else
        {
            cout<<"Underflow";
        }
        
    }
};
int main()
{
    CircularQueue q(5);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Display();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    q.Display();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    q.Enqueue(9);
    q.Display();
}
