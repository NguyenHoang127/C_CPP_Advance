#include<stdint.h>
#include<stdio.h>
#include<time.h>

/*
    Khi sử dụng biến register tốc độ xử lý nhanh hơn vì biến được 
    lưu ở Register thay vì RAM nên đường đi đến bộ xử lý ALU nhanh hơn

*/

int main(int argc, char const *argv[])
{
   clock_t start, end;

   //uint32_t i;
   register uint32_t i;
   
   start = clock();  //1s

   for (i = 0; i < 0xFFFFFFFF; i++); //3s

   end = clock();    //4s

   printf("time: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
   

    return 0;
}