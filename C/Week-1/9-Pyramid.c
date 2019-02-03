#include<stdio.h>
int main()
{
    int no = 5;
    //scanf("%d",&no);
    int i,j,k,l;
    for(i=1;i<=no;i++)
    {
        for(j=no-i;j>0;j--)
            printf(" ");
        for(k=i;k>0;k--)
        {
            printf("%d",k);
        }
        for(l = 2;l<=i;l++)
        {
            printf("%d",l);
        }
        printf("\n");
    }
}