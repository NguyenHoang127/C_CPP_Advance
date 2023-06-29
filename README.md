# Lesson 1: Complier

> Biên dịch từ ngôn ngữ do lập trình viên viết trên các ngôn ngữ (C/C++, Python ) sang ngôn ngữ máy.

Một file c thông dụng bao gồm:
- File `.c`  là file source và file `.h` là file header

Quá trình xử lý biên dịch bao gồm:
- B1: Preprocessor quá trình tiền xử lý build thành file `.I` gọi là preprocessed source
- `gcc -E B1_Complier.c -o  B1_Complier.i`

- B2: Compiler từ `file.I` thành `file.s` gọi là Assemply code
- `gcc B1_Complier.i -S -o main.s`

- B3: Assembler tạo ra file object file `.o` +library
- B4: Linker tạo ra chương trình executable `.exe`

---
# Lesson 2: Marco

- Marco trong C là một cách ngắn gọn để định nghĩa các hằng số và hàm ngắn gọn bằng cách sử dụng từ khóa #define
- Biên dịch có thể kể đến là sử dụng #ifdef và #ifndef để kiểm tra biến vừa được tạo đã được define trong hàm main hay chưa

```
#define MAX_ARR_LENGTH 100

int a[MAX_ARR_LENGTH];

int main(){
    printf("MAX_ARR_LENGTH: %d", MAX_ARR_LENGTH);
    return 0;
}
```

```
#define Max 24

#if Max < 20
    void test (){
        printf("Max < 20\n");
    }

#elif Max == 20
    void test (){
        printf("Max == 20\n");
    }

#else 
    void test (){
        printf("Max > 20\n");
    }

#endif

int main(){
    test();
}
```

- Dùng `##` để nối chuỗi trong Marco và định nghĩa nhiều dòng bằng \
```
#define typeVar(type, name) type var_##name
```
```
#define typeVar(type, name) type var_##name\
                            type var1_##name\
                            type var2_##name
```
---
# Lesson 3: Input
- va_list: Đây là một kiểu phù hợp để lưu trữ thông tin cần thiết bởi ba macro là va_start(), va_arg() và va_end()

1. Macro va_start() trong C: void va_start(va_list ap, last_arg);
2. Macro va_arg() trong C: type va_arg(va_list ap, type)
3. Macro va_end() trong C: void va_end(va_list ap)

---
# Lesson 4: Variable Type

1. Biến Static
- Biến static tồn tại hết chương trình không bị mất khi kết thúc hàm
- Sự khác nhau giữa biến Static và Normal

```
#include <stdio.h>

//Thư viện stdint.h dùng để dùng các kiểu dữ liệu uint_t(kích thước của biến)
#include <stdint.h>

//----------------------------------------------------------------------------------

//Hoạt động biến bình thường địa chỉ biến được khởi tạo trong hàm và
//biến mất khi kết thúc hàm vd hàm count
/*
    1. Khởi tạo biến count ở địa chỉ nào đó trên vùng nhớ.
    2. In giá trị nó ra.
    3. Cộng giá trị ở vùng nhớ đó lên 1 -> vô nghĩa vì
    4. Giải phóng địa chỉ của biến count.
    Tương tự cho những lời gọi hàm ở dưới.
*/

//Tương tự nhưng hàm này sử dụng kiểu biến static
/*
    1. Khởi tạo biến count ở địa chỉ nào đó trên vùng nhớ.
    2. In giá trị nó ra.
    3. Cộng giá trị ở vùng nhớ đó lên 1
    4. Không giải phóng vùng nhớ ở Stack vì static là khởi tạo ở "data segment"
    Tương tự cho những lời gọi hàm ở dưới.
*/

void count()
{
    uint8_t temp = 0;                  //Biến Normal
    printf("Count value is: %d\n",temp);
    temp = temp + 1;
}

void count_2()
{
    uint8_t static temp = 0;                  //Biến Static
    printf("Count value static is: %d\n",temp);
    temp = temp + 1;
}

int main(int argc,char const *array[])
{
    count(); //output = 0
    count(); //output = 0

    count_2(); //output = 0
    count_2(); //output = 1
    count_2(); //output = 2
    count_2(); //output = 3

    return 0;
}
```

2. Biến Register

```
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
```

<img src="https://i.imgur.com/oHtV1x9.png)https://i.imgur.com/oHtV1x9.png">

3. Biến Extern: Cho phép truy cập từ 1 `file.c` khác có trong thư mục
- Cú pháp compile: 'gcc extern.c library.c -o extern.c'

```
extern void count();
extern uint8_t temp;

```
---
# Lesson 5: Phân Vùng Nhớ

<img src="https://i.imgur.com/GSRPuKh.png">

- Layout Chương Trình C trong memory gồm 5 phần chính:

- Text: 
  + Chứa các mã lệnh
  + Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
  + Chứa khai báo hằng số trong chương trình (.rodata)
    
- Data Segment (DS)
  + Các biến global và static được initialized các biến khác 0 bởi programmer
  + Quyền truy cập là read-write.
  + Được giải phóng khi kết thúc chương trình
  + VD: int hex = 32;
    
- Uninitialized Data Segment (BSS)
  + Các biến global và static không được initialized có thể bằng 0
  + Quyền truy cập là read-write.
  + Được giải phóng khi kết thúc chương trình.
  + VD: int hex;
    
- Heap: Dynamic Memory Allocation (Vùng cấp phát bộ nhớ động)
  + Control bằng các lệnh malloc/calloc/realloc
  + Mỗi lần sử dụng Heap sẽ phình lên và ta có thể sử dụng lệnh free để giải phóng heap cứ mỗi lần như vậy Heap sẽ xẹp đi
  + Nếu quên deallocate memory in Heap sẽ gây ra Memory Leak
  + Quyền truy cập là read-write.
    
- Stack: Automatic Variable Storage (Cấp phát bộ nhớ tự động)
  + Mỗi khi Function được gọi Function sẽ được để vào Function frame
  + Quyền truy cập là read-write.
  + Được sử dụng cấp phát cho biến local, input parameter của hàm,…
  + Sẽ được giải phóng khi ra khỏi block code/hàm
  + Stack gồm 4 phần chính: Function parameter, Return address, Saved previous frame pointer, Local variables
 
<img src="https://i.imgur.com/dXcsbqM.png">
<img src="https://i.imgur.com/XocnW6D.png">
  
---
# Lesson 6: Struct & Union

1. Struct
   - Struct là kiểu dữ liệu do người dùng tự định nghĩa
   - Ta có thể dùng typedef để định nghĩa ngắn gọn
   - Ví dụ khai báo
```
typedef struct 
{
    uint8_t ngay;         
    uint32_t thang;  
    uint16_t nam;       
}typeDate;
```
  - Ví dụ sử dụng
```
    typeDate date;

    // date.ngay = 23;
    // date.thang = 5;
    // date.nam = 2023;

    //Hoac typeDate date = {23,5,2023};
``` 

- Kích thước của struct được tính bằng cách dựa vào member có giá trị lớn nhất có trong đó
- Ví dụ cụ thể

```
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

```
2. Union
    - Giống như Struct, Union cũng là kiểu dữ liệu do người dùng định nghĩa.

    - Giá trị của các biến trong Union có cùng một địa chỉ nên giá trị sau khi gán bởi giá trị trước

    - Kích thước của Union là kích thước của member lớn nhất.
```
#include<stdio.h>
#include<stdint.h>
#include<string.h>

typedef union 
{
    uint32_t var1;
    uint16_t var2;
    uint64_t var3;
}typeData1;

int main(int argc,char const *arvg)
{
    typeData1 value ={.var1=2,.var2=3};

    printf("Test: %d\n",value.var1);                      //Output = 3
    printf("Dia chi cua Union var1: %p\n",&(value.var1)); //Output = 0061FF10
    printf("Dia chi cua Union var2: %p\n",&(value.var2)); //Output = 0061FF10
    printf("Dia chi cua Union var3: %p\n",&(value.var3)); //Output = 0061FF10
    return 0; 
}
```
---
# Lesson 7: Goto & Setjum

1. Goto
   - Cung cấp 1 bước nhảy từ 'goto' đến một câu lệnh có label
   - Ví dụ:
```
      label:
      statement(
      goto label:
      )
```
2. Setjum
   - Tương tự như Goto
   - Sử dụng thư viện setjmp.h để dùng setjum
```
#include<stdio.h>
#include<stdint.h>
#include<setjmp.h>

int main(int argc,char const *argv[])
{
    jmp_buf jumb;
    int i = setjmp(jumb);
    
    printf("i=%d \n",i);

    //Thoat khoi chuong trinh khi i=1
    if(i!=0)
    {
        exit(0);
    }

    //Trả về giá trị jumb bằng 1 bằng cách quay lại lên trên vị trí setjmp
    longjmp(jumb,1);

    printf("test\n");
    return 0;
    
}
```
---
# Lesson 8: Pointer
- Bản chất ram bao gồm giá trị và địa chỉ 
- Để lưu giá trị địa chỉ của 1 biến ta có thể khai báo và sử dụng con trỏ
```
int a = 10;
int *pa = &a;              //Tạo biến con trỏ và trỏ lưu địa chỉ biến a
    *pa = 27;                  //Trỏ đến địa chỉ biến a và lưu giá trị bằng 27

    printf("C1. Gia tri a: %d\n",a);    //Khi này giá trị a = 27
    printf("C2. Gia tri a: %d\n",*pa);

    printf("C1. Dia Chi a: %p \n",&a); //Lấy địa chỉ
    printf("C2. Dia Chi a: %p \n",pa); //Lấy địa chỉ
```

1. Để thay đổi giá trị của 1 hàm con ta cần truy xuất đến đúng địa chỉ để thay đổi
```
void swap2(int *a,int *b) //2 Địa chỉ của hàm này là địa chỉ 2 số đầu vào
{
    printf("So a: %d,dia chi: %p\n",*a,a);
    printf("So b: %d,dia chi: %p\n",*b,b);

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv)
{
    int so1 = 10;
    int so2 = 20;

    printf("Truoc Swap so1: %d,dia chi: %p\n",so1,&so1); //10
    printf("Truoc Swap so2: %d,dia chi: %p\n",so2,&so2); //20

    swap2(&so1,&so2);

    printf("Sau Swap so1: %d,dia chi: %p\n",so1,&so1); //20
    printf("Sau Swap so2: %d,dia chi: %p\n",so2,&so2); //10


    return 0;
}
```
---
# Lesson 10: 
