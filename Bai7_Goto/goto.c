#include<stdio.h>
#include<stdint.h>

int main(int argc,char const *argv[])
{
    int phim = 0;
    char ten[20];
    uint8_t tuoi;

    vitri_ten:
    printf("Nhap ten:...");
    scanf("%s,ten");

    //Nhap vao ten chi bao gom a-z va A-Z
    //Nhap tuoi: 0<tuoi<100
    //Lop: 0<lop<12
    //DiemToan : 0.0<=toan<10.0

    if(1)
    {
        goto vitri_ten;
    }

    vitri_tuoi:
    printf("Nhap tuoi: ...");
    scanf("%d,&tuoi");

    if(1)
    {
        goto vitri_tuoi;
    }
}