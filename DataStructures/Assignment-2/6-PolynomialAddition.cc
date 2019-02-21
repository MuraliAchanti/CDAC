#include<iostream>  
using namespace std;
struct Node
{
    int data;
    int power;
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
    void Insert_First(int ele,int power)
    {
        struct Node *temp;
        temp = new Node;
        temp->data =  ele;
        temp->power = power; 
        temp->next =  start;
        start = temp;
    }
    void Insert_Last(int ele,int power) 
    {   
        struct Node *temp = NULL,*curr = NULL;
        temp = new Node;
        temp->data = ele;
        temp->power = power;  
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
    void Insert_After(int key,int ele,int power)
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
            temp->power = power; 
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            cout<<"Element Not Found"<<endl;
            
        }
    }
    void Insert_Before(int key,int ele,int power)
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
            temp->power = power; 
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
            temp->power = power;
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
                cout<<"Power - "<<curr->power<<"Co-Efficient - "<<curr->data<<endl;
                curr = curr->next;
            }
        }
    }
    friend void Print(struct Node *s);
    friend void PolynomialAddition(SLL &s1,SLL &s2); 
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
        cout<<"Power - "<<curr->power<<"Co-Efficient - "<<curr->data<<endl; 
    } 
    else
    {
        return;
    }
}
void PolynomialAddition(SLL &s1,SLL &s2)   
{
    if(s1.start == NULL)
        s1.Traverse_Forward(); 
    else if(s2.start == NULL)
        s2.Traverse_Forward(); 
    else
    {
        SLL summation_list;
        summation_list.start = NULL;
        struct Node *iter1,*iter2; 
        iter1 = s1.start;
        iter2 = s2.start;  
        while(iter1!=NULL && iter2!=NULL)
        {
            if(iter1->power == iter2->power)
            {
                summation_list.Insert_Last(iter1->data + iter2->data,iter1->power); 
                iter1 = iter1->next; 
                iter2 = iter2->next;
            }
            else if(iter1->power > iter2->power)
            {   
                summation_list.Insert_Last(iter1->data,iter1->power); 
                iter1 = iter1->next;
            }
            else if(iter2->power > iter1->power)
            {   
                summation_list.Insert_Last(iter2->data,iter2->power);  
                iter2 = iter2->next;
            }
        }
        while(iter1 != NULL)
        {
                summation_list.Insert_Last(iter1->data,iter1->power); 
                iter1 = iter1->next;
        }
        while(iter2 != NULL )
        {
                summation_list.Insert_Last(iter2->data,iter2->power);  
                iter2 = iter2->next;
        }
        summation_list.Traverse_Forward();
    }
}
int main()
{
    SLL s1,s2;
    s1.Insert_First(4,0);
    s1.Insert_First(5,1);
    s1.Insert_First(6,2);
    s1.Insert_First(7,3);
    s1.Insert_First(7,4);
    s1.Insert_First(8,5);
    s2.Insert_First(4,0);
    s2.Insert_First(5,1);
    s2.Insert_First(6,3);
    s2.Insert_First(7,4);
    PolynomialAddition(s1,s2); 
}