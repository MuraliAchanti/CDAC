#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct 
{
    int day;
    int month;
    int year;
}date;
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int CheckLeapYear(date d)
{   
    int years = d.year;
    if(d.month<=2)
    {
        years--;
    }
    return (years/4) - (years/100) + (years/400);
}
int CalculateDays(date d1,date d2)
{   
    int n1,n2;
    n1 = (d1.year *365) + d1.day;  
    n2 = (d2.year *365) + d2.day; 
    n1 = n1 + CheckLeapYear(d1); 
    n2 = n2 + CheckLeapYear(d2); 
    int  i =  0;
    for(i=0;i<d1.month;i++)
    {
        n1 = n1 + monthDays[i];
    }
    for(i=0;i<d2.month;i++)
    {
        n2 = n2+ monthDays[i];
    }
    return abs(n2-n1); 
}
int main()
{
    date d1 = {1, 2, 2000}; 
    date d2 = {1, 2, 2004};
    //printf("Enter the date 1");
    //scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
    //printf("Enter the date 2");
    //scanf("%d%d%d",&d2.day,&d2.month,&d2.year);
    printf("%d",CalculateDays(d1,d2));
}