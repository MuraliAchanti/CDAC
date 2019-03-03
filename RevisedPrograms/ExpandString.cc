#include<iostream>
using namespace std;
void ExpandString(char *CompressedString)
{   
    int len = strlen(CompressedString);
    if(CompressedString[len -1] == '-' || CompressedString[0] == '-')
    {
        cout<<"Invalid String"<<endl;
    }
    else if(1)
    {
        for(int i=0;i<len;i++)
        {
            if(CompressedString[i] == '-' && CompressedString[i+1] == '-')
            {
                cout<<"Invalid String"<<endl;
                return;
            }
        }
    }
    else    
    {
        char expanded[100];
        int i;
        int k = 0;
        for(i=0;i<strlen(CompressedString);i++)
        {
            if(CompressedString[i] == '-')
            {   
                if((isdigit(CompressedString[i-1]) && isdigit(CompressedString[i+1]))
                     || (isalpha(CompressedString[i-1]) && isalpha(CompressedString[i+1])))
                {
                int j = 0; 
                for(j = CompressedString[i-1]+1;j<CompressedString[i+1];j++,k++)
                {
                    expanded[k] = j;
                }
                }
            }
            else
            {
                expanded[k] = CompressedString[i];  
                k++;
            }   
        }
    }
    
}
int main()
{
    char ShortHandString[100];
    cout<<"Enter the String"<<endl;
    cin>>ShortHandString;
    ExpandString(ShortHandString);
}
