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

#endif
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
