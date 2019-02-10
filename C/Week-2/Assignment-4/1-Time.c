#include<stdio.h>
#include<stdlib.h>
struct time
{
    int hours;
    int minutes;
    int seconds;
};
int main()
{   
    /*time t; 
    printf("Enter the time in hours minutes and seconds");
    scanf("%d%d%d",&t.hours,&t.minutes,&t.seconds);
    printf("The Current Time is\n%d : %d : %d\n",t.hours,t.minutes,t.seconds);*/
    struct time *t; 
    t = (struct time *)malloc(sizeof(struct time));
    printf("Enter the time in hours minutes and seconds");
    scanf("%d%d%d",&(t->hours),&(t->minutes),&(t->seconds));
    printf("The current time is %d : %d : %d",(*t).hours,t->minutes,t->seconds);
}