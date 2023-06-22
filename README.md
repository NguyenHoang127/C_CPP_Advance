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

<img src="[https://imgur.com/oHtV1x9)https://imgur.com/oHtV1x9]">
