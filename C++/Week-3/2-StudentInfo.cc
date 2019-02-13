#include<iostream>
using namespace  std;
class Student
{
    char *name;
    char *grade;
    int marks[3];
    public:
        void set_data(const char *name,int mark1,int mark2,int mark3)
        {
            int len = strlen(name);
            this->name = (char *)malloc(sizeof(char)*len);
            strcpy(this->name,name);
            marks[0] = mark1;
            marks[1] = mark2;
            marks[2] = mark3;
        }
        int calc_average()
        {
            float avg;
            avg = (marks[0]+marks[1]+marks[2])/3;
            return avg;
        }
        void display()
        {
            printf("Student Name : %s\n",name);
            printf("Grade : %s\n",grade);
            printf("Marks %d %d %d\n",marks[0],marks[1],marks[2]);
        }
        void SetGrade(const char *grade)
        {   
            int len = strlen(grade);
            this->grade = (char *)malloc(sizeof(char)*len);
            strcpy(this->grade,grade);
        }
};
class CollegeCourse:public Student
{   
    int average;
    public:
    CollegeCourse(char *name,int mark1,int mark2,int mark3)
    {
        set_data(name,mark1,mark2,mark3); 
    }
    void CalculateAverage()
    {   
        average  = calc_average();
        //printf("The average is %d",average);
        return;
    }
    void ComputeGrade()
    {
        if(average>60)
        {   
            SetGrade("First Class");
            //printf("First Class");
        }
        else if(average>50)
        {   
            SetGrade("Second Class");
            //printf("Second Class");
        }
        else
        {   
            SetGrade("Third Class");
            //printf("Third Class");
        }
        
    }
    void Display()
    {
        display();
        printf("The Average is %d\n",average);   
    }
}; 
int main()
{
    CollegeCourse C1("Giroud",40,50,60);
    C1.CalculateAverage();
    C1.ComputeGrade();
    C1.Display();
    CollegeCourse C2("Aubameyang",30,30,30);
    C2.CalculateAverage();
    C2.ComputeGrade();
    C2.Display();
}