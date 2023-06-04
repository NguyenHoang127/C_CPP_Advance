#include <stdio.h>

//Trong quá trình tiền xử lí (pre-processor), 
//Các macro được sử dụng trong chương trình được 
//thay thế bởi các khối câu lệnh tương ứng
#define MAX 25
//#define TONG(a,b) a+b

#if MAX < 20

void test()
{
    printf("MAX < 20\n");
}

#elif MAX == 20

void test()
{
    printf("MAX == 20\n");
}

#else

void test()
{
    printf("MAX > 20\n");
}


// #ifdef MIN
// int b = 15;
#endif

int main(int argc,char const *array[])
{
    //printf("MAX = %d\n",MAX);
    test();
    //printf("Tong a va b: %d\n",TONG(6,7));
    return 0;
}