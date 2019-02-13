#include<stdio.h>
#include<string.h>
void FindCountry(char *temp,FILE *fp)
{   
    while(!feof(fp))
    {   
        char string[100];
        fgets(string,100,fp); 
        printf("%s %d\n",temp,strlen(temp));
        printf("STRING = %s\n",string);
        char *country =  strtok(string,":");
        printf("%s %d\n",country,strlen(country));
        char *capital = strtok(NULL,":");
        int len = strlen(capital);
        capital[len-1] = '\0';
        printf("%s %d\n",capital,strlen(capital));
        if(strcmp(capital,temp)==0) 
        {  
            printf("aaa\n");
            printf("%s",country);
            break;
        }
        else
        {
            continue;
        }
    }
    fclose(fp); 
}