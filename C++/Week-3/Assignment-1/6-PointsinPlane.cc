#include<iostream>
#include<cmath>
using namespace std;
class Point
{
    int x;
    int y;
    public:
    Point()
    {
        x = 0;
        y = 0;
    }
    void Set_value(int x,int y)
    {
        //printf("Enter the X-coordinate and Y-coordinates");
        //scanf("%d %d",&x,&y);
        this->x = x;
        this->y = y;
    }
    void Get_Value()
    {
        printf("X-Coordinate = %d,Y-Coordinate = %d",x,y); 
    }
    friend int FindDistance(Point p1,Point p2);
}; 
int FindDistance(Point p1,Point p2)
{
    int temp;
    temp = pow(abs((p1.x - p2.x)),2) + pow(abs((p1.y - p2.y)),2);
    return sqrt(temp);
}
int main()
{   
    Point p1,p2;
    p1.Set_value(5,6);
    p1.Get_Value();
    p2.Set_value(7,6);
    cout<<"The Distance is"<<FindDistance(p1,p2);
}
