#include<iostream>  
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void Print(struct Node *s);
class SLL
{
    Node *start;
    public:
    SLL()
    {
        start = NULL;
    }
    //INSERT OPERATIONS
    void Insert_First(int ele)
    {
        struct Node *temp;
        temp = new Node;
        temp->data =  ele;
        temp->next =  start;
        start = temp;
    }
    void Insert_Last(int ele)
    {   
        struct Node *temp = NULL,*curr = NULL;
        temp = new Node;
        temp->data = ele;
        temp->next = NULL;
        if(start == NULL)
        {
            start = temp;
        }
        else
        {
            curr = start;
            while(curr->next!=NULL)
            {
                curr = curr->next;
            }

            
            curr->next=temp;
        }
    }
    void Insert_After(int key,int ele)
    {
        if(start == NULL)
        {   
            cout<<"Empty List"<<endl;
            return;
        }
        struct Node *curr,*temp;
        curr = start; 
        while(curr != NULL && curr->data!=key)
        {
            curr = curr->next;
        }
        if(curr!=NULL)
        {   
            temp = new Node;
            temp->data = ele;
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            cout<<"Element Not Found"<<endl;
            
        }
    }
    void Insert_Before(int key,int ele)
    {   
        cout<<"aaa";
        if(start == NULL)
        {
            cout<<"Empty List"<<endl;
            return;
        }
        struct Node *curr;
        curr = start;
        struct Node *temp;
        if(start->data == key)
        {   
            cout<<"aaa";
            temp = new Node;
            temp->data = ele;
            temp->next =  start;
            start = temp;
        }
        else
        {
        while(curr->next != NULL && curr->next->data == key)
        {
            curr = curr->next;
        }
        if(curr!=NULL)
        {   
            temp = new Node;
            temp->data = ele;
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            cout<<"Element Not Found"<<endl;
        }
        }
    } 
    //DELETE OPERATIONS
    int Delete_First()
    {
        if(start == NULL)
        {
            cout<<"List Empty";
            return -99; 
        }
        struct Node *temp;
        int data;
        temp = start;
        data =  temp->data;
        start = temp->next;
        delete temp;
        return data;
    }
    void Delete_Last()
    {   
        if(start == NULL)
        {
            cout<<"List Empty";
            return;
        }
        struct Node *temp;
        if(start->next == NULL) 
        {   
            temp = start; 
            start = temp->next;
            free(temp);
        }
        else
        {
            struct Node *curr;
            curr = start; 
            while(curr->next != NULL &&  curr->next->next != NULL)   
            {
                curr  = curr->next;
            }
            free(curr->next);
            curr->next =  NULL;
        }
    }
    void Delete_Specific(int ele)
    {
        if(start == NULL)
        {
            cout<<"List Empty"<<endl;
            return;
        }
        struct Node *temp,*curr;
        if(start->data == ele)
        {
            temp = start;
            free(temp);
            start =  temp->next;
        }
        else
        {
            curr = start;
            while(curr->next !=NULL && curr->next->data == ele)
            {
                curr = curr->next;
            }
            temp = curr->next;
            curr->next = curr->next;
            delete(temp);
        }
    }
    void Traverse_Forward()
    {
        struct Node *curr;
        if(start == NULL)
        {
            cout<<"Empty List";
            return;
        }
        else
        {   
            cout<<"Queue ELEMENTS ARE"<<endl;
            curr = start;
            while(curr != NULL)
            {   
                cout<<curr->data<<endl;
                curr = curr->next;
            }
        }
    }
    friend void Print(struct Node *s);
    void Traverse_Backward()
    {   
        if(start != NULL)
            Print(start); 
    }  
    ~SLL()
    {
        struct Node *temp;
        while(start!=NULL)
        {
            temp = start;
            start = temp->next;
            delete temp; 
        }
    }
};
void Print(struct Node *curr)
{   
    struct Node *temp;
    temp  = curr;  
    if(temp!=NULL)
    {    
        Print(temp->next);
        cout<<temp->data<<endl;  
    } 
    else
    {
        return;
    }
    
}
class Queue
{
    SLL queue;
    public:
    Queue()
    {
        cout<<"Queue Created";
    }
    void Enqueue(int ele)
    {   
        cout<<"Element Inserted"<<endl; 
        queue.Insert_Last(ele);
    }
    int Dequeue()
    {
        cout<<"Dequeued Element is";
        return queue.Delete_First(); 
    }
    void Display()
    {
        queue.Traverse_Forward();
    }
};
int main()
{
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Display();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    q.Enqueue(7);
    q.Display();
    cout<<q.Dequeue();
    q.Display();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
}