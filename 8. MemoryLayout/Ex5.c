#include <stdio.h>

#define SIZE 5

int arr[SIZE]; // cấp phát tĩnh (vùng nhớ ko thể thay đổi)

int main()
{

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d = %d\n", i, arr[i]);
    }
    
}