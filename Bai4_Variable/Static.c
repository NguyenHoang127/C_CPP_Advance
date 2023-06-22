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