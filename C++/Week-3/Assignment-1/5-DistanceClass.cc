#include<iostream>
using namespace std;
class Distance2;
class Distance1  
{
    int meters;
    int centimeters; 
    float dist;
    public:
    void Set_Value(float res)
    {   
        dist = res;    
        meters = (int)dist;
        centimeters = (dist - meters)*100;
        printf("Meters = %d,Centimeters = %d\n",meters,centimeters);
    }
    Distance1() 
    {
        meters = 0;
        centimeters = 0;
        dist = 0;
    }
    void Get_Data(int meters,int centimeters)
    {
        this->meters = meters;
        this->centimeters = centimeters; 
        this->dist = meters + ((float)centimeters/100);
        printf("%f",dist);
    }
    friend float AddDistances(Distance1,Distance2,int);
};
class Distance2
{
    int feet;
    int inches;
    float dist;
    public:
    void Set_Value(float res)
    {
        dist  = res; 
        feet = (int)dist;
        inches = (dist - feet)*100;
        printf("Feet = %d, Inches = %d\n",feet,inches);
    }
    Distance2()
    {
        feet = 0;
        inches = 0;
        dist = 0;
    }
    void Get_Data(int feet,int inches)
    {
        this->feet = feet;
        this->inches = inches;
        this->dist  = feet + ((float)inches/12);
    }
    friend float AddDistances(Distance1,Distance2,int);
};
float AddDistances(Distance1 d1,Distance2 d2,int choice)
{   
    float result;
    switch(choice)
    {
        case 1:result = d1.dist + (0.3048*(d2.dist)); 
               printf("Result = %f\n",result);
               return result;
        case 2:result = (d1.dist*3.28084) + d2.dist;
               printf("Result = %f\n",result);
               return result;
    }
}
int main()
{
    int choice;
    Distance1 d1,d3;
    d1.Get_Data(1,5);
    Distance2 d2,d4;
    d2.Get_Data(1,5);
    float result;
    do
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:result = AddDistances(d1,d2,choice);
                   d3.Set_Value(result);
                   break;
            case 2:result = AddDistances(d1,d2,choice);
                   d4.Set_Value(result);
                   break;
            default:printf("Exit\n");
        }
    } while(choice!=-1); 
}