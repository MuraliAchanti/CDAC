#include<stdio.h>
#include<string.h>
void FindCapital(char *temp,FILE *fp)
{
    while(!feof(fp))
    {   
        char country[100];
        fgets(country,100,fp); 
        //printf("1 - %s",country);
        char *c =  strtok(country,":");
        //printf("2 - %s",c);
        if(strcmp(c,temp)==0) 
        {   
            printf("%s",strtok(NULL,":"));
            break;
        }
        else
        {
            continue;
        }
    }
    fclose(fp); 
}