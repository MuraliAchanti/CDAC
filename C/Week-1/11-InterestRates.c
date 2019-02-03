#include<stdio.h>
#include<math.h>
void Interest(int amount);
int main()
{
    int amount = 500000;
    //scanf("%d",&amount);
    Interest(amount);
}
void Interest(int amount)
{
    long double si,ci;
    int i=0;
    int rate = 5;
    int time[] = {1,2,4,12,365};
    si = (float)(amount*10*rate)/100;
    printf("Simple Interest is %LF\n",si);
    for(i=0;i<5;i++)
    {
        ci = (amount*(1 + (0.05/10)));
        ci = ci*pow(ci,time[i]);
        printf("Coumpund Interest for yearly %d times is %LF\n",time[i],ci);
    }
}