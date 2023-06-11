#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define MIN_VALUE 1
#define MAX_VALUE 10

void createArray(uint8_t arr[])
{
    uint8_t i;

    // Khởi tạo seed cho hàm rand()
    srand(time(NULL));

    // Tạo mảng ngẫu nhiên trong phạm vi từ MIN_VALUE đến MAX_VALUE
    for (i = 0; i < SIZE; i++) 
    {
        arr[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    }
}

int Searching(uint8_t arr[], uint8_t n, uint8_t target) 
{
    uint8_t left = 0;
    uint8_t right = n - 1;

    while (left <= right) 
    {
        //Xác định vị trí ở giữa mảng
        uint8_t mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            return 1;
        }

        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}

int main() {
    
    uint8_t arr[50];
    createArray(arr);

    printf("Mang ngau nhien:\n");
    for (uint8_t i = 0; i < SIZE; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target = 8;

    if (Searching(arr, 50, target)) 
    {
        printf("so 8 co trong mang");
    }
    else 
    {
        printf("so 8 khong co trong mang");
    }
    // printf("Mang ngau nhien:\n");
    // for (uint8_t i = 0; i < SIZE; i++) 
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    return 0;
}

