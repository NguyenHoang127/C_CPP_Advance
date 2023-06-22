#include<stdio.h>
#include<stdint.h>
#include<string.h>

typedef union 
{
    uint32_t var1[3]; //Member có kích thước 12byte
    uint16_t var2[7]; //Member có kích thước 14byte
    uint64_t var3[4]; //Member có kích thước 32byte
}typeData;

typedef union 
{
    uint32_t var1;
    uint16_t var2;
    uint64_t var3;
}typeData1;

typedef union 
{
    uint8_t  var1[5]; //0 1 2 3 4
    uint16_t var2[2]; //0 0 0 2 (2byte là 2 ô nhớ)
}typeData2;


int main(int argc,char const *arvg)
{
    typeData data;
    typeData1 value ={.var1=2,.var2=3};
    typeData2 data2;

    printf("Test: %d\n",value.var1);                      //Output = 3
    printf("Dia chi cua Union var1: %p\n",&(value.var1)); //Output = 0061FF10
    printf("Dia chi cua Union var2: %p\n",&(value.var2)); //Output = 0061FF10
    printf("Dia chi cua Union var3: %p\n",&(value.var3)); //Output = 0061FF10

    printf("Size: %d \n",sizeof(data)); //Output là 32

    for(int i = 0;i<5;i++)
    {
        data2.var1[i] = i;       //Output 0 1 2 3 4
    }

    for(int i = 0;i<2;i++)
    {
        data2.var2[i] = 2*i;     //Output 0 2
    }

    for(int i = 0;i<5;i++)
    {
        printf("test1: %d\n",data2.var1[i]); //Output 0 0 0 2 4
    }

    return 0; 
}