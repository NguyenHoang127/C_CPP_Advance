#include <stdio.h>

//gcc là một complier nổi tiếng của C
//B1: File .c là file source và file .h là file header

//B2: Preprocessor quá trình tiền xử lý build thành file .I gọi là preprocessed source
//gcc -E B1_Complier.c -o  B1_Complier.i

//B3: Compiler từ file.I thành file.s gọi là Assemply code
//gcc B1_Complier.i -S -o main.s

//B4: Assembler tạo ra file object file .o +library
//B5: Linker tạo ra chương trình executable .exe

#define MAX 10

void test()
{
    printf("Hello");
}

int main(int argc,char const *argv[])
{
    test();
    return 0;
}