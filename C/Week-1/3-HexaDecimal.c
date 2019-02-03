#include<stdio.h>
#include<math.h>
int main()
{
    int val=0xCAFE;
    int og = val;
    int val1 = val;
    int temp,i=0;
    int count = 0;
    int size = log2(val);
    int length = size+1;
    temp = 1  << size;
    //Count the number of set bits
    for(i=1;i<4;i++)
    {   
        if(temp&val)
        {  
            count++;
        }
        temp = temp>>i ; 
    }
    //Swapping the Bytes
    int bits[length];
    for(i=length-1;i>=0;i--)
    {
        bits[i] = val%2;
        val = val/2;
    }
    printf("\n");
    int j = 0;
    for(i=0,j=8;i<8;i++,j++)
    {
        temp = bits[i];
        bits[i] = bits[j];
        bits[j]  = temp;
    }
    for(i=0;i<length;i++)
        printf("%d",bits[i]);
    printf("\n");
    int val2 = 0;
    for(i=0;i<length;i++)
    {
        val2 = val2 + (bits[i]*pow(2,size-i));
    }
    //Rotating 4 bits
    temp = 1;
    int temp_bits = 0;
    for(i=0;i<4;i++)
    {
        temp_bits =  temp_bits | (temp & val1);
        temp = temp << 1;
    }
    temp_bits=temp_bits<<12;
    val1 = val1 >> 4;
    val1 = val1 | temp_bits;
    printf("The number of set bits for the original number %d,%#X is - %d\n",og,og,count);
    printf("Swapping the Bytes: the original number is %#X to %#X - %d\n",og,val2,val2);
    printf("After Rotating 4 bits %#X to %#X - %d\n",og,val1,val1);
    //1100101011111110 - 0xCAFE - 51966
    //1111111011001010 - 0xFECA - 65226
    //1110110010101111 - 0xECAF - 60591
}
