#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) // count : tham số đầu tiên đại diện cho số lượng tham số không xác định
{
    va_list args;
    int total = 0;

    va_start(args, count);
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);

    return total;
}

// Cách này có nhược điểm là phải biết trước số lượng tham số sẽ truyền vào hàm (count)
// => Cần kết hợp với variadic để có thể truyền vào số lượng tham số không xác định

int main(void)
{
    printf("Tong la: %d\n", sum(3, 3, 5, 7)); // Gọi hàm sum với 3 tham số
    return 0;
}

// => Với hàm số lượng tham số không xác định,  có 2 cách là sử dụng các macro trong thư viện stdarg.h để quản lý danh sách tham số. 
// Hoặc có thể sử dụng Variadic để quản lý danh sách tham số không xác định 
