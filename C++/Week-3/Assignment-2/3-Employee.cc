#include<iostream>
using namespace std;
class Employee
{
    int empno;
    char *name;
    int salary;
    public:
    Employee()
    {
        empno =  0;
        name = NULL;
        salary = 0;
    }
    Employee(int empno,const char *name,int salary)
    {
        this->empno = empno;
        int len = strlen(name);
        this->name = (char *)malloc(sizeof(char)*len);
        strcpy(this->name,name);
        this->salary = salary;
    }
    friend istream& operator>>(istream &cin,Employee &emp);
    friend ostream& operator<<(ostream &cout,Employee &emp);
    void Print_Data()
    {
        cout<<(*this);
        return;
    }
};
istream& operator>>(istream &cin,Employee &emp)
{
        emp.name = (char *)malloc(sizeof(char)*25);
        cout<<"Enter the employee number"<<endl;
        cin>>emp.empno; 
        cout<<"Enter the name"<<endl;
        cin>>emp.name;
        cout<<"Enter the salary"<<endl;
        cin>>emp.salary; 
        return cin;
}
ostream& operator<<(ostream &cout,Employee &emp)
{
    cout<<"Employee Details are"<<endl;
    cout<<"Employee Id "<<emp.empno<<endl;
    cout<<"Employee Name "<<emp.name<<endl;
    cout<<"Employee Salary"<<emp.salary<<endl;
    return cout; 
}
int main()
{
    Employee e[2];
    for(int i=0;i<2;i++)
    {
        cin>>e[i];
        cout<<e[i];
    }
    e[0].Print_Data();
}