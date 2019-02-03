#include<stdio.h>
#include<math.h>
void RotateRight(int n,int b)
{
    int size;
    int new = n;
    size = log2(n) + 1;
    int i;
    int og[size];
    int changed[size];
    int temp = 1;
    int mask = 0;
    for(i=0;i<size;i++)
    {
        og[i] = n%2;
        n = n/2; 
    }
    printf("Original Number\n");
    for(i=size-1;i>=0;i--)
    {
        printf("%d",og[i]); 
    }
    printf("\n");
    n = new;
    for(i=0;i<b;i++)
    {
        mask = mask | (n&temp);
        temp = temp << 1;
    }
    n = n >> 5;
    mask = mask << (size-b);
    n = n | mask; 
    int rot_num;
    for(i=0;i<size;i++)
    {
        changed[i] = n%2;
        n = n/2;
    }
    printf("Rotated Bits\n");
    for(i=size-1;i>=0;i--)
    {
        printf("%d",changed[i]);
    }
    printf("\n");
    return;
}
int main()
{
    int num;
    printf("Enter the number");
    scanf("%d",&num);
    RotateRight(num,4);

}