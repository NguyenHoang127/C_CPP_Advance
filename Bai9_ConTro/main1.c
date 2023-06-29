#include <stdio.h>

int swap(int a,int b) //2 Địa chỉ của hàm này khác với địa chỉ số đầu vào
{
    printf("So a: %d,dia chi: %p\n",a,&a);
    printf("So b: %d,dia chi: %p\n",b,&b);

    int temp;
    temp = a;
    a = b;
    b = temp;

    printf("Value a after: %d\n",a);
    printf("Value b after: %d\n",b);

    return a,b;
}

void swap2(int *a,int *b) //2 Địa chỉ của hàm này là địa chỉ 2 số đầu vào
{
    printf("So a: %d,dia chi: %p\n",*a,a);
    printf("So b: %d,dia chi: %p\n",*b,b);

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, char const *argv)
{
    int so1 = 10;
    int so2 = 20;

    printf("Truoc Swap so1: %d,dia chi: %p\n",so1,&so1);
    printf("Truoc Swap so2: %d,dia chi: %p\n",so2,&so2);

    int so3,so4;
    so3,so4 = swap(so1,so2);
    //swap2(&so1,&so2);

    printf("Sau Swap so1: %d,dia chi: %p\n",so3,&so1);
    printf("Sau Swap so2: %d,dia chi: %p\n",so4,&so2);


    return 0;
}