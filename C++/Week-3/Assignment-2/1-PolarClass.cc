#include<iostream>
using namespace std;
class Polar
{
    int radius;
    int angle;
    static int count;
    public:
    Polar()
    {
        radius = 0;
        angle = 0;
        count++;
    }
    Polar(int radius,int angle)
    {
        this->radius = radius;
        this->angle = angle;
    }
    static void CountObjects()
    {
        count++;
    }
    void Get_Count()
    {
        cout<<"The Count is"<<count<<endl;
    }
};
int Polar::count  = 0;
int main()
{
    Polar p1;
    p1.CountObjects();
    Polar p2;
    Polar p3;
    p3.Get_Count();
}