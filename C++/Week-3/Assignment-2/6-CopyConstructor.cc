#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
class String
{
    int len;
    char *string;
    public:
    String()
    {
        len = 0;
        string = NULL;
    }
    String(const char *str)
    {
        len = strlen(str);
        string = (char *)malloc(sizeof(char)*len);
        strcpy(string,str);
    }
    String(String &s)
    {
        len = s.len;
        string = (char *)malloc(sizeof(char)*len);    
        strcpy(string,s.string);
    }
    String operator=(String s1)
    {
        printf("Errors-1");
        len = s1.len;
        string =  (char*)malloc(sizeof(char)*len);
        strcpy(string,s1.string);
        return (*this);
    }
    String* operator->()
    {
        return (this);
    }
    String operator,(String s)
    {
        printf("Errors");
        return (*this);
    }
    friend istream& operator>>(istream& cin,String &s);
    friend ostream& operator<<(ostream &cout,String s);
};
istream& operator>>(istream& cin,String &s)
{
    cout<<"Enter the length"<<endl;
    cin>>s.len;
    cout<<"Enter the string"<<endl;
    s.string = (char  *)malloc(sizeof(char)*(s.len));
    cin>>s.string; 
    return  cin;
}
ostream& operator<<(ostream &cout,String s)
{
    cout<<"The string is = "<<s.string;
    return  cout; 
}
int main()
{
    String s2("arsenal");
    String s1;
    String s3;
    cin>>s3;
    s1  = s2,s3; 
    cout<<s3;
}