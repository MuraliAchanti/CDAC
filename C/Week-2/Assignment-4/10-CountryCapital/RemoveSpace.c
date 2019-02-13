#include<stdio.h>
int main()
{
    FILE *fp,*fp1;
    fp = fopen("country.txt","r");
    fp1 = fopen("Countries.txt","w");
    char ch;
    while((ch = fgetc(fp))!= EOF)
    {
        if(ch == ':')
        {   
            fputc(ch,fp1); 
            ch = fgetc(fp);
            if(ch == ' ')
            {
                continue;
            }
        }
        else
        {
            fputc(ch,fp1);
        }
        
    }
    fclose(fp);
    fclose(fp1);
}