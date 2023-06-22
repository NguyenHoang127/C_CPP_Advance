#include <stdio.h>
#include <stdint.h>

//Struct là kiểu dữ liệu do người dùng tự định nghĩa
//Căn cứ vào member có kích thước lớn nhất mỗi lần quét là 4byte

typedef struct 
{
    uint8_t ngay;       //Quét 4 byte : sử dụng 1byte + 3 byte bộ nhớ đệm    
    uint32_t thang;     //Quét 4 byte : sử dụng 4 byte
    uint16_t nam;       //Quét 4 byte : sử dụng 2 byte + 2 byte bộ nhớ đệm 
}typeDate;
//Kích thước là 12 byte

//VD2:
typedef struct 
{
    uint32_t thang;     //Quét 4 byte : sử dụng 4 byte
    uint8_t ngay;       //Quét 4 byte : sử dụng 1byte + 3 byte bộ nhớ đệm :{2byte (name) + 1byte đệm }    
    uint16_t nam;       //Vì nam chỉ sử dụng 2 byte mà nhỏ hơn bộ nhớ đệm ở trên
                        
}typeDate2;
//Kích thước là 8 byte

//VD3:
typedef struct
{
    uint8_t ngay;   //Quét 8 byte: sử dụng 1 byte + 7byte Đệm
    uint64_t tuan;  //Quét 8 byte: sử dụng 8 byte
    uint16_t nam;   //Quét 8 byte: sử dụng 2 byte + 6byte Đệm:{4byte thang + 2byte Đệm}
    uint32_t thang; 
}typeDate3;
//Kích thước là 24 byte

//VD4:
typedef struct 
{
    uint8_t ngay[3];
    /*
    Tách ra ta được:

    uint8_t ngay1;  //Quét 4byte đủ 3 byte cho 3 ngày + 1 byte đệm
    uint8_t ngay2;
    uint8_t ngay3;
    */

    uint32_t thang[4];

    /*
    Tách ra ta được:
     
    uint32_t thang1;  //Quét đủ 16 byte
    uint32_t thang2;
    uint32_t thang3;
    uint32_t thang4;
    */
    uint16_t nam[5]; //Quét 4 byte thu dc nam[0]: 2 byte nam[1]: 2 byte
                     //Quét 4 byte ...
                     //Quét 4 byte ...

    /*
    Tách ra ta được:
     
    uint16_t nam1;  
    uint16_t nam2;
    uint16_t nam3;
    uint16_t nam4;
    uint16_t nam5;
    */
}typeDate4;
//Kích thước là 32 byte


//VD5: Member max is 8 byte
typedef struct 
{
    uint8_t ngay[3];    //3byte + 5 byte đệm:{1 thang + 1 byte dem}
    uint32_t thang[4];  //8byte:{2 thang} + 8byte:{1 thang + 4 byte dem}
    uint64_t tuan[3];   //24 byte
    uint16_t nam[5];    //16 byte

}typeDate5;
//Kích thước là 64byte


//=> Kích thước biến struct tạo ra phụ thuộc vào cách sắp xếp 



void hienThi(typeDate date)
{
    printf("Ngay: %d, Thang: %d, Nam: %d",date.ngay,date.thang,date.nam);
}


int main(int argc,char const *argv[])
{
    typeDate5 date;

    printf("Size: %d \n",sizeof(date));

    // date.ngay = 23;
    // date.thang = 5;
    // date.nam = 2023;

    //Hoac typeDate date = {23,5,2023};

    // hienThi(date);
    return 0;
}