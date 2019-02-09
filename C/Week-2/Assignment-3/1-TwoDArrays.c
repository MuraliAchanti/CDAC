#include<stdio.h>
int main()
{
    float table[2][3] = {{1.1,1.2,1.3},{2.1,2.2,2.3}};
    //Table is a two dimensional array with rows and columns with each element of type float
    printf("%lu\n",table);
    printf("%lu\n",*table);
    printf("%lu\n",(table+1));
    //return an address pointing to the first element in second row;
    printf("%lu\n",*(table+1));
    //returns an address of the first element in the second row;
    printf("%lu\n",(*(table+1)+1));
    //returns an address pointing to the second element in second row;
    printf("%f\n",*(*(table+1)+1));
    printf("%lu\n",(*(table)+1));
    //points to the second element in 1st row
    printf("%f\n",*(*(table)+1));
    //
    printf("%f",*(*(table)+1));
    //returns the second element of first row
    printf("%f\n",*(*(table+1)));
    //points to the first element in second row
    printf("%f\n",*(*(table)+1)+1);
    //increment the first element in first row
}