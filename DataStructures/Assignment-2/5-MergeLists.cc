#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*new_start;
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
    void Delete_First()
    {
        if(start == NULL)
        {
            cout<<"List Empty";
            return;
        }
        struct Node *temp;
        temp = start;
        start = temp->next;
        delete temp;
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
    /*~SLL()
    {
        struct Node *temp;
        while(start!=NULL)
        {
            temp = start;
            start = temp->next;
            delete temp; 
        }
    }*/
    friend void MergeLists(SLL &s1,SLL &s2); 
    friend void Push(struct Node *new_start,struct Node *element);
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
void Push(struct Node *element)
{
    //cout<<element;
    if(new_start == NULL)
    {
        new_start = element; 
        element->next = NULL;  
    }
    else
    {
        struct Node *curr;
        curr = new_start;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }   
        curr->next = element; 
        element->next = NULL;
    }
}
void MergeLists(SLL &s1,SLL &s2)
{   
    struct Node *curr1,*curr2; 
    curr1 = s1.start;
    curr2 = s2.start;  
    if(curr1==NULL)
        s2.Traverse_Forward();
    else if(curr2==NULL)
        s1.Traverse_Forward(); 
    else
    {   
        while(curr1!=NULL && curr2!=NULL)  
        {   
            //cout<<"aaa"<<endl;
            if(curr1->data>curr2->data)   
            {   
                struct Node *temp;
                temp = curr2->next;
                Push(curr2);
                curr2 = temp;   
            }
            else
            {   struct Node *temp;
                temp = curr1->next;
                Push(curr1);
                curr1 = temp; 
            }  
        }  
        //cout<<"new-start"<<new_start<<endl;
        while(curr1!=NULL)
        {   
            //cout<<"aaa"<<endl;
            struct Node *temp;
            temp = curr1->next;
            Push(curr1);
            curr1 = temp; 
        }
        while(curr2!=NULL)  
        {   
            //cout<<"aaa"<<endl;
            struct Node *temp; 
            temp = curr2->next;
            Push(curr2);
            curr2 = temp;
        }
    }
    //cout<<new_start;
    //s1.start = new_start;
    //s1.Traverse_Forward();
}
int main()
{
    SLL s1,s2;
    s1.Insert_First(50);
    s1.Insert_First(40);
    s1.Insert_First(30);
    s1.Insert_First(10);
    s2.Insert_First(90);
    s2.Insert_First(70);
    s2.Insert_First(50);
    s2.Insert_First(20);
    MergeLists(s1,s2);
    struct Node *temp;
    temp = new_start;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}