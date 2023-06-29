#include<stdio.h>

//Con trỏ đặc biệt void *ptr có thể lưu mọi giá trị
void Tong(int a, int b)
{
    printf("Tong %d va %d la %d\n",a,b,a+b);
}

int a = 10;
char c = 'A';

//Khi khai báo 1 con trỏ k sử dụng khai báo NULL hoặc khi không sử dụng nữa
int *ptr_null = NULL;

//Point to Pointer
int *pt_cap1 = &a;
int **pt_cap2 = &pt_cap1; //Lưu địa chỉ con trỏ cấp 1 bởi địa chỉ con trỏ cấp 2 

int main(int argc, char const *argv)
{
    int i = 10;
    void *ptr = &i;

    printf("Dia chi la: %p , Gia tri la: %d \n",ptr,*(int*)ptr);
    //Vì void không xác định nên cần sử dụng ép kiểu con trỏ

    void *ptr_tong = &Tong;
    ((void(*)(int,int))ptr_tong)(9,7);  //Ép kiểu con trỏ void về con trỏ hàm

    void *arr[] = {&Tong,&a,&c};        //Con trỏ mảng Lưu địa chỉ

    printf("a: %d\n",*(int*)arr[1]);
    printf("c: %c\n",*(char*)arr[2]);
    ((void(*)(int,int))arr[0])(9,7);

    printf("Dia chi con tro : %p\n",pt_cap1);
    printf("Dia chi con tro cap 1: %p\n",*pt_cap2); //Xet tu con tro pt_cap2
    printf("Dia chi con tro cap 2: %p\n",pt_cap2);  //Xet tu con tro pt_cap2

    return 0;
}