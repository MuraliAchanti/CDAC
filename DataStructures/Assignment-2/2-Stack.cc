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
            return -999;
        }
        int data;
        struct Node *temp;
        temp = start;
        data = temp->data;
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
    int Display_First()
    {
        if(start == NULL)
        {
            cout<<"Empty"<<endl;
            return -99;
        }
        else
        {
            return start->data;
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
            cout<<"LIST ELEMENTS ARE"<<endl;
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
class Stack
{
    SLL top;
    public:
    Stack()
    {
        cout<<"Stack Created"; 
    } 
    void Push(int ele)
    {   
        cout<<"Element Inserted";
        top.Insert_First(ele);
    }
    int Pop()
    {
        cout<<"Element Popped";
        int popped_element = top.Delete_First();
        return popped_element;
    }
    int Peek()
    {
        cout<<"Top Element is"<<endl;
        return top.Display_First();
    }
    void Display()
    {
        //cout<<"Stack Elements are"<<endl;
        top.Traverse_Forward();
    }
};
int main()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Display();
    cout<<s.Pop();
    cout<<s.Pop();
    cout<<s.Pop();
    s.Peek();
    s.Pop();
    s.Display();
}