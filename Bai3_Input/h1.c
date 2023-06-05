#include <stdio.h>
#include <stdarg.h>

int tong (int a, int b, int c){
    return a+b+c;
}

int main ()
{
    printf("Tong la: %d", tong(6,3,10));
    
    return 0;
}