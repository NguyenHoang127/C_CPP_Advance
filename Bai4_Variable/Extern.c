#include <stdio.h>
#include <stdint.h>

extern void count();
extern uint8_t temp;

int main()
{

    count(); //output 15
    count(); //output 16

    temp = 35;
    
    count(); //output 35
    count(); //output 36

return 0 ;
}