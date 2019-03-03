//strrev,strcpy,strcat,strcmp
#include<iostream>
using namespace std;
void SWAP(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
char* STRREV(char* input)
{
    int length = strlen(input);
    char *endptr = input + length - 1;
    char *temp = input;
    while(input<endptr)
    {
        SWAP(input,endptr);
        input++;
        endptr--;
    }
    return temp;
}
void STRCPY(char *d,char *s)
{
    while((*d++ = *s++))
    {
    }
}
char* STRCAT(char *d,char *s)
{
    int len = strlen(d);
    STRCPY(d+len,s);
    return d;
}
int STRCMP(const char* s1,const char *s2)
{
    while(*s1 == *s2 && (*s1!='\0' || *s2!='\0'))
    {
        {
            s1++;
            s2++;
        }
    }
    return *s1 - *s2;
}
int main()
{
    cout<<"Enter the String"<<endl;
    int choice;
    do
    {
    char input_string[100];
    printf("1.String Reverse\n2.String Copy\n3.String Concatenate\n4.String Compare\n5.Quit");
    cin>>choice;
    switch(choice)
    {
        case 1:cout<<"String Reverse"<<endl;
               cin>>input_string;
               cout<<STRREV(input_string)<<endl;
               break;   
        case 2:char input_string1[100];
               cout<<"String Copy"<<endl;
               cout<<"First String is - "<<endl;
               cin>>input_string;
               cout<<"Second String is"<<endl;
               cin>>input_string1;
               STRCPY(input_string,input_string1); 
               cout<<"String 1 is - "<<input_string<<endl;
               break;
        case 3:
               cout<<"String Concatenate"<<endl;
               cout<<"String Copy"<<endl;
               cout<<"First String is - "<<endl;
               cin>>input_string;
               cout<<"Second String is"<<endl;
               cin>>input_string1;
               cout<<"Concatenated First String is - "<<STRCAT(input_string,input_string1)<<endl;
               break;
        case 4:
               cout<<"String Compare"<<endl;
               cout<<"String Copy"<<endl;
               cout<<"First String is - "<<endl;
               cin>>input_string;
               cout<<"Second String is"<<endl;
               cin>>input_string1;
               if(STRCMP(input_string,input_string1) == 0)
               {
                   cout<<"Equal"<<endl;
               }
               else
               {
                   cout<<"Not Equal"<<endl;
               }
               break;
        case 5:cout<<"QUIT"<<endl;
               break;
    }
    }while(choice!=5);
}