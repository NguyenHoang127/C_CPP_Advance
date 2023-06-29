#include<stdio.h>
#include<stdint.h>
#include<setjmp.h>

int main(int argc,char const *argv[])
{
    jmp_buf jumb;
    int i = setjmp(jumb);
    
    printf("i=%d \n",i);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("i=%d \n",i);
    //     if(i==5)
    //     {
    //         exit(0);
    //     }
    //     printf("test");
    //     return 0;
    // }

    //Thoat khoi chuong trinh khi i=1
    if(i!=0)
    {
        exit(0);
    }

    //Trả về giá trị jumb bằng 1 bằng cách quay lại lên trên vị trí setjmp
    longjmp(jumb,1);

    printf("test\n");
    return 0;
    
}