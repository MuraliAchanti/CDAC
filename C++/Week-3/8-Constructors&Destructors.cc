#include<iostream>
using namespace std;
int count = 0;
class Employee
{
    char *name;
    int id;
    public:
    Employee()
    {
        //Default Constructor called when an object is declared
        printf("Default Constructor\n");
        ::count++; 
        id = ::count;
        printf("Id initialized to zero\n");
    } 
    Employee(const char *name,int id)
    {
        //Parameterized Constructor is called when parameters are passed
        printf("Parameterized Constructor is called\n");
        int len = strlen(name);
        ::count++;
        id = ::count;
        this->name = (char *)malloc(sizeof(char)*len);
        strcpy(this->name,name);
        this->id  = id;
    }
    void Display()
    {   
        printf("The Employee Details are - \n");
        printf("Name - %s,Id - %d\n",name,id);
    }
    ~Employee()
    {
        //is called when the object goes out of scope
        printf("Destructor is called %d\n",id);
    }
};
int main()
{
    Employee E1;
    Employee E2("Giroud",12);
    E2.Display();
    {
        Employee E3;
    }
}