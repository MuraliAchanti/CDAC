#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
class LinkedLists
{
    struct Node *start;
    public:
    LinkedLists()
    {
        start = NULL;
    }
    
}