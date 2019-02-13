#include<stdio.h>
void FindCapital(char *temp,FILE *fp);
void FindCountry(char *temp,FILE *fp);
int main()
{   
    FILE *fp;
    fp = fopen("countries.txt","r");
    int choice = 0;
    char temp[100];
    do
    {   
        printf("Enter the choice");
        scanf("%d%*c",&choice);
        fseek(fp,0,SEEK_SET); 
        switch(choice)
        {
            case 1:printf("Enter the Country");
                   gets(temp);
                   FindCapital(temp,fp);
                   break;
            case 2:printf("Enter the Capital");
                   gets(temp);

                   FindCountry(temp,fp);
                   break;
            default:printf("Enter a valid option");
        }   
        fclose(fp);
    }while(choice!=-1);
}