#include <stdio.h>

void Tong(int a, int b)
{
    printf("Tong %d va %d la %d\n",a,b,a+b);
}

void Hieu(int a, int b)
{
    printf("Hieu %d va %d la %d\n",a,b,a-b);

}

float tich(float a,float b)
{
    return a*b;
}

void thuong(int a, int b)
{
    printf("Thuong %d va %d la %f\n",a,b,(float)a/b);
}

void phepTinh(int a,int b,void (*ptr)(int,int))
{
    printf("Chuong trinh tinh toan \n");
    ptr(a,b);
}

int main(int argc, char const *argv)
{
    // void (*ptr)(int,int);            //Khai báo con trỏ hàm
    // ptr = &Tong;
    // ptr(9,8);

    // float (*ptr_tich)(float,float);  //Khai báo con trỏ hàm
    // ptr_tich = &tich;

    // printf("tich: %f \n",ptr_tich(5.3,5.6));

    phepTinh(8,6,&Tong);
    phepTinh(8,6,&Hieu);

    return 0;
}