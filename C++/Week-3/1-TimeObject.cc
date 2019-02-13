#include<iostream>
using namespace std;
class Time
{
    int hours;
    int minutes;
    int seconds;
    public: 
            Time()
            {
                hours = 0;
                minutes = 0;
                seconds = 0;
            }
            Time(int hours,int minutes,int seconds)
            {
                this->hours = hours;
                this->minutes  =  minutes;
                this->seconds = seconds;
            }
            void DisplayTime()
            {
                printf("The time is %d : %d : %d\n",hours,minutes,seconds);
            }
            void AddTime(Time t1,Time t2)
            {
                int rem = 0;
                seconds = (t1.seconds + t2.seconds)%60;
                rem = (t1.seconds + t2.seconds)/60;
                minutes = (t1.minutes+t2.minutes+rem)%60;
                rem = (t1.minutes + t2.minutes+rem)/60;
                hours  = (t1.hours + t2.hours + rem)%24;
            }
};
int main() 
{   
    Time t1(11,43,34);
    Time t2(13,43,44);
    Time t3;
    t1.DisplayTime();
    t2.DisplayTime();
    t3.AddTime(t1,t2); 
    t3.DisplayTime();
}