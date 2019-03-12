#include<iostream>
using namespace std;
#define SIZE 100
char* ExpandString(char *CompressedString)
{   
    int flag = 0;
    char *expanded = NULL;
    int len = strlen(CompressedString);
    if(CompressedString[len -1] == '-' || CompressedString[0] == '-')//Last and first indices are hyphens
    {
        cout<<"First and Last Hyphens"<<endl;
        return NULL;
    }
    if(1)//Consecutive hyphens
    {
        for(int i=0;i<len;i++)
        {
            if(CompressedString[i] == '-' && CompressedString[i+1] == '-')
            {
                cout<<"Consecutive Hyphens"<<endl;
                return NULL;
            }
        }
    }
    if(1)//Negative Numbers
    {   
        int flag = 0;
        int index = 0;
        for(int i=0;i<len;i++)
        {   
            if(CompressedString[i] == '-' && flag == 0)
            {
                flag = 1;
                index = i+1;
            }
            else if(CompressedString[i] == '-' && flag == 1)
            {
                if((i-1) != index)
                {
                    flag = 0;
                }
                else
                {   
                    cout<<"Negative Number"<<endl;
                    return NULL;
                }
                
            }
        }
    }
    if(1)//Lower and Upper Check
    {
        for(int i = 0;i<len;i++)
        {
            if(CompressedString[i] == '-')
            {   
                if(isalpha(CompressedString[i-1]) && isalpha(CompressedString[i+1])) 
                {
                    if((CompressedString[i-1]>64 && CompressedString[i-1]<91) && (CompressedString[i+1]>64 && CompressedString[i+1]<91)) 
                    {
                    }
                    else if((CompressedString[i-1]>96 && CompressedString[i-1]<123) && (CompressedString[i+1]>96 && CompressedString[i+1]<123)) 
                    {

                    }
                    else
                    {   
                        cout<<"Upper and Lower Mismatch"<<endl;
                        return NULL;
                    }
                }                
            }
        }
    }
    if(1)
    {
        for(int i = 0;i<strlen(CompressedString);i++)
        {
            if(CompressedString[i] == '-')
            {
                if((i-2)>=0)
                {
                    if(CompressedString[i-2] == '.')
                    {   
                        cout<<"Floating Type Input"<<endl;
                        return NULL;
                    }
                } 
            }
        }
    }
    if(1)//Expansion
    {
        expanded = new char[SIZE];
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
                if(CompressedString[i-1] > CompressedString[i+1]) 
                {
                    for(j = CompressedString[i+1]+1;j<CompressedString[i-1];j++,k++)
                    {
                        expanded[k] = j;
                    }
                }
                else if(CompressedString[i-1] == CompressedString[i+1])
                {
                    i++;
                }
                else if(CompressedString[i-1] < CompressedString[i+1])
                {
                    for(j = CompressedString[i-1]+1;j<CompressedString[i+1];j++,k++)
                    {
                        expanded[k] = j;
                    }
                }
                else
                {
                    //cout<<"Invalid String"<<endl;
                    return NULL;
                }   
                }
            }
            else
            {
                expanded[k] = CompressedString[i];  
                k++;
            }   
        }
        expanded[k]  = '\0';
    return expanded;
    }
}
int main()
{ 
    char ShortHandString[SIZE];
    cout<<"Enter the String"<<endl;
    cin>>ShortHandString;
    char *output = ExpandString(ShortHandString);
    if(output!=NULL)
        cout<<"Expanded String is - "<<output;
    else
    {
        cout<<"Error!!!Please Run Again";
    }
    
}
