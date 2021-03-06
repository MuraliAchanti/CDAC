#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class DLL
{
	struct node *start;
public:
	DLL() 
	{
		start = NULL;
	}
	void InsertFirst(int e);
	void InsertLast(int e);
	void InsertAfter(int e, int k);
	void InsertBefore(int e, int k);
	int DeleteFirst();
	int DeleteLast();
	void DeleteSpecific(int e);
	void TraverseForward();
    void TraverseBackward();
	~DLL();
};
void DLL::InsertFirst(int e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
    if(start!=NULL)
	start->prev=temp;
	temp->next = start;
	temp->prev=NULL;
	start = temp;
}
void DLL::InsertLast(int e) {
	struct node *temp, *cur;
	temp = new node;
	temp->data = e;
	if (start != NULL)
	{
		cur = start;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		temp->prev=cur;
		cur->next = temp;
		temp->next = NULL;
	}
}
void DLL::TraverseForward()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << "--->";
		cur = cur->next;
	}
	cout << endl;
}
void DLL::TraverseBackward()
{
	struct node *cur;
	cur = start;
	while (cur->next != NULL)
	{
		
		cur = cur->next;
	}
	while (cur!= NULL)
	{
		cout << cur->data << "--->";
		cur = cur->prev;
	}
	
	cout << endl;
}
void DLL::InsertAfter(int e, int k)
{
	struct node *cur, *temp;
	cur = start;
	if (start != NULL)
	{
		while (cur != NULL&&cur->data != k)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			temp = new node;
			temp->data = e;
			temp->next = cur->next;
			temp->prev=cur;
			cur->next = temp;
		}
		else
			cout << endl << "no such element" << endl;
	}
	else
		cout << endl << "List empty" << endl;

}
void DLL::InsertBefore(int e, int k)
{
	struct node *cur, *temp;
	cur = start;
	if (start != NULL)
	{
		if (start->data == k)
		{
			temp = new node;
			temp->next = start;
			start = temp;
			temp->data = e;
		}
		else
		{
			while (cur->next != NULL &&cur->next->data != k)
			{
				cur = cur->next;
			}
			if (cur->next != NULL)
			{
				temp = new node;
				temp->next = cur->next;
				cur->next = temp;
				temp->prev=cur;
				temp->data = e;
			}
			else
				cout << endl << "no such eele" << endl;
		}
	}
	else
		cout << endl << "no list" << endl;

}
int DLL::DeleteFirst()
{
	struct node *temp;
	int e = -1;
	if (start != NULL)
	{
		temp = start;
		start = start->next;
		start->prev=NULL;
		e = temp->data;
		delete temp;
	}
	return e;
}
int DLL::DeleteLast()
{
	int e = -1;
	struct node *temp, *cur;
	if (start != NULL)
	{
		cur = start;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		temp = cur;
	    temp->prev->next=NULL;
		e = temp->data;
		delete temp;
	}
	return e;
}
void DLL::DeleteSpecific(int e) {
	struct node *cur, *temp;
	cur = start;
	if (start != NULL)
	{
		if (start->data == e)
		{
			temp = start;
			start = NULL;
			delete temp;

		}
		else
		{
			while (cur!= NULL &&cur->data != e)
			{
				cur = cur->next;
			}
			if (cur != NULL)
			{
				temp = cur;
				cur->prev->next= temp->next;
				temp->next->prev=cur->prev;
				delete temp;
			}
			else
				cout << endl << "no such eele" << endl;
		}
	}
	else
		cout << endl << "no list" << endl;

}

DLL ::~DLL()
{
	struct node *cur, *temp;
	cur = start;
	while (cur != NULL)
	{
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	start = NULL;
	cout << "DONe";
}
int main()
{
	DLL l;int e;
	l.InsertFirst(2);
	l.InsertFirst(1);
	l.InsertFirst(0);
	l.InsertLast(3);
	l.InsertLast(4);
	l.InsertAfter(5, 4);
	l.InsertBefore(5, 3);
    l.TraverseForward();
	l.DeleteSpecific(5);
    l.TraverseForward();
    l.DeleteFirst();
    l.TraverseForward();
    l.DeleteLast();
	l.TraverseForward();
	l.TraverseBackward();
}