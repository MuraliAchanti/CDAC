#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
class String
{
    char *string;
    int len;
    public:
    String()
    {
        string = NULL;
        len  = 0;
    }
    String(const char *str)
    {
        this->len = strlen(str);
        this->string =  (char *)malloc(sizeof(char)*(this->len));
        strcpy(this->string,str);
    }
    ~String()
    {
        free(string);
        cout<<"Destructor Called\n";
    }
    String(const String &s)
    {
        len = s.len;
        string = (char *)malloc(sizeof(char)*len);
        strcpy(string,s.string);
    }
    void DisplayString()
    {
        cout<<"Length = "<<len<<endl;
        cout<<"String = "<<string<<endl;
    }
    String operator=(String s)
    {   
        len = s.len;
        if(string  == NULL)
        {
        string  = (char *)malloc(sizeof(char)*len);
        }
        strcpy(string,s.string);
        return (*this);
    }
    char& operator[](int i) 
    {
        return string[i];
    }
    String operator+(String s)
    {  
        String temp;
        temp.len = len + s.len + 1;  
        temp.string = (char *)malloc(sizeof(char)*(temp.len)); 
        temp.string = strcat(string,s.string);
        return temp;
    }
    friend istream& operator>>(istream& cin,String &s);  
    friend ostream& operator<<(ostream& cout,const String s);
};
istream& operator>>(istream& cin,String &s)
{
    cout<<"Enter the length ";
    cin>>s.len;
    s.string = (char *)malloc((sizeof(char))*(s.len)); 
    cin>>s.string; 
    return cin; 
}
ostream& operator<<(ostream& cout,const String s)
{
    cout<<"Length = "<<s.len<<endl;  
    cout<<"String = "<<s.string<<endl;
    return cout;
}
int main()
{
    String s1("arsenal");
    cout<<s1;
    String s2;
    cin>>s2;
    cout<<s2;
    String s3;
    s3 =  s1 + s2;
    cout<<s3;
}