#include<stdio.h>
int main()
{
    int num;
    int min = __INT_MAX__,max = 0,avg;
    int count = 0;
    while(1)
    {   
        scanf("%d",&num);
        if(num<=0)
        {
            break;
        }
        else
        {   
            count++;
            avg = avg + num;
            if(num<min)
                min = num;
            if(max < num)
                max = num;
        }
    }
    avg = (float)avg/count;
    printf("Max = %d,Min = %d,Average = %d\n",min,max,avg);
}