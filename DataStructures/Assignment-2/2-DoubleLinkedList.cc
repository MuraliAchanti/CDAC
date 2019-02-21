#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
class DLL
{
    struct Node *start;
    public:
    DLL()
    {
        start = NULL;
    }
};
int main()
{

} 