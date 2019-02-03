#include<stdio.h>
#include<math.h>
void itob(int n)
{
    int size;
    size = log2(n)+1;
    int bits[size];
    int i;
    for(i=size-1;i>=0;i--)
    {
        bits[i] = n%2;
        n=n/2;
    }
    printf("Binary Represenatation\n");
    for(i=0;i<size;i++)
        printf("%d",bits[i]);
    printf("\n");
    return;
}
void itoh(int n)
{
    int size;
    char bits[100];
    int i;
    while(n!=0)
    {
        int rem;
        rem = n%16;
        if(n<10)
        { 
            bits[i] = rem + 48;
            i++;
        }
        else
        {   bits[i] = rem + 55;
            i++;         
        }
        n=n/16;
    }
    int j;
    printf("Hexadecimal Representation\n");
    for(j=i-1;j>=0;j--)
    {
        printf("%c",bits[j]);
    }
    printf("\n");
}
int main()
{
    int num = 51966;
    //scanf("%d",&num);
    itob(num);
    itoh(num);
}