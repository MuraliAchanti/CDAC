#include<stdio.h>
typedef struct 
{
    int day;
    int month;
    int year;
}date;
void LeapYear()
{

}
int main()
{
    date d1,d2;
    printf("Enter the date 1");
    scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
    printf("Enter the date 2");
    scanf("%d%d%d",&d2.day,&d2.month,&d2.year);
    CalculateDays(d1,d2);
}