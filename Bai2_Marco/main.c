#include <stdio.h>

//Marco cho kiểu dữ liệu và tên
//#define VARIABLE(type,name) type name

//Marco tạo biến đầu vao
#define VARIABLE(name) int int_##name;
char char_##name;
double double_##name

// #define STM32F103 0
// #define STM32F303 1

// #define PIC16F887 2
// #define ATMEGA    3

// //---------------------------------------
// #define MCU ATMEGA

// #if MCU == ATMEGA

// #elif MCU == STM32F103

// #endif



int main(int argc,char const *array[])
{
    //VARIABLE(int,bien);
    //bien=10;

    VARIABLE(bien);
    printf("test: %d\n",bien);

    return 0;
}