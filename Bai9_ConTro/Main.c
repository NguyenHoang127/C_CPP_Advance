//Khai báo biến con trỏ int *ptr = 0xc1 lưu địa chỉ thay vì giá trị
//Bản chất của ram chỉ bao gồm giá trị và địa chỉ
//Lấy được giá trị từ địa chỉ *0xC1 = 10;
//&0xC1 lấy giá trị từ địa chỉ
#include <stdio.h>

//Stage1
int a = 10;
char c = 'A';

void hello()
{
    printf("Hello \n");
}

void Tong(int a, int b)
{
    printf("Tong %d va %d la %d\n",a,b,a+b);

}

int main(int argc, char const *argv)
{
    int *pa = &a;              //Tạo biến con trỏ và trỏ lưu địa chỉ biến a
    *pa = 27;                  //Trỏ đến địa chỉ biến a và lưu giá trị bằng 27

    printf("C1. Gia tri a: %d\n",a);    //Khi này giá trị a = 27
    printf("C2. Gia tri a: %d\n",*pa);

    printf("C1. Dia Chi a: %p \n",&a); //Lấy địa chỉ
    printf("C2. Dia Chi a: %p \n",pa); //Lấy địa chỉ
    
    
    printf("Dia Chi c: %p \n",&c);
    printf("Dia Chi tong: %p \n",&hello);
    return 0;
}