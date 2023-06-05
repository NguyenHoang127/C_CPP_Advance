#include <stdio.h>
#include <stdarg.h>

//Tính tổng nhiều số
int tong(int so_input,...)
{                         
    int sum = 0;
    va_list value;                    //Khởi tạo dãy
    va_start (value, so_input);       //Truy cập vào danh sách và cập nhật vị trí con trỏ

    for(int i = 0; i < so_input; i++)
    {
         sum = sum + va_arg(value, int);              
    }

    va_end(value);
    
    return sum;
}
int main(){
    printf("tong cac so la: %d\n",tong(5, 1, 2, 3, 4, 5));
    return 0;
}