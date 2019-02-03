#include<stdio.h>
#include<math.h>
void InvertBits(int n,int p,int b)
{
    int i;
    int size = log2(n)+1;
    int og[size];
    int invert[size];
    int num = n;
    for(i=size-1;i>=0;i--)
    {
        og[i] = n%2;
        n = n/2;
    }
    printf("Original Number\n");
    for(i=0;i<size;i++)
        printf("%d",og[i]);
    printf("\n");
    n = num;
    for(i=0;i<b;i++)
    {
        if(og[size-p+i] == 1)
            og[size-p+i] = 0;
        else
        {
            og[size-p+i] = 1;
        }   
    }
    printf("Inverted Number\n");
    for(i=0;i<size;i++)
        printf("%d",og[i]); 
    printf("\n");
    return;
}
int main()
{
    int num =  51966;
    //scanf("%d",&num);
    InvertBits(num,7,1);
}