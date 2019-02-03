#include<stdio.h>
int main()
{
    int basic;
    float salary = 0;
    printf("Enter the amount");
    scanf("%d",&basic);
    if(basic>0 && basic <= 4000)
    {
        salary = basic + (float)((0.1*basic) + (0.5*basic));
    }
    else if(basic>4000 && basic <= 8000)
    {
        salary = basic + (float)((0.2*basic) + (0.6*basic));
    }
    else if(basic>8000 && basic <= 12000)
    {
        salary = basic + (float)((0.25*basic)+(0.7*basic));
    }
    else
    {
        salary =  basic + (float)((0.3*basic)+(0.8*basic));
    }
    printf("Gross Salary =  %f",salary);
}