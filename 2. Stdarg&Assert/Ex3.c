#include <stdio.h>
#include <stdarg.h>

/*
#define Tong(...) sum(__VA_ARGS__, 0)  // '...' macro variadic, cho phép truyền vào một số lượng tham số không xác định.
// __VA_ARGS__ macro đại diện cho danh sách các tham số được truyền vào macro. '0' được thêm vào cuối để đảm bảo hàm sum có đủ tham số.
// Khi gọi Tong(4, 1, 2, -1, 3), macro sẽ được mở rộng thành sum(4, 1, 2, -1, 3, 0).


int sum(int count, ...) // count : tham số đầu tiên đại diện cho số lượng tham số không xác định
{
    va_list args;
    va_start(args, count);

    // Khác biệt so với Ex2
    int total = count; // Khởi tạo biến total với giá trị count
    int value;
    
    // không sử dụng for vì không biết số lượng tham số => dùng while khi gặp "0" thì dừng
    while ((value = va_arg(args, int)) != 0) { // Sử dụng vòng lặp để lấy từng tham số cho đến khi gặp giá trị 0
        total += value;
    }
   
    va_end(args);

    return total;
}
*/
// Ở ví dụ này sẽ giải quyết được vấn đề không biết trước số lượng tham số
// nhưng khi vòng lặp có 2 tham số liên tiếp bằng 0 thì sẽ dừng lại ở vị trí đó dẫn đến việc không tính được giá trị của tham số sau cùng.

// Để giải quyết vấn đề này => sử dụng va_copy để sao chép danh sách tham số và sử dụng va_arg để lấy từng tham số một cách an toàn.

#define tong(...)  sum(__VA_ARGS__, '\n') 

int sum(int count, ...) // count : tham số đầu tiên đại diện cho số lượng tham số không xác định
{
    va_list args;
    va_list check;

    va_start(args, count);
    va_copy(check, args); // Sao chép danh sách tham số để kiểm tra

    int total = count; 
    // int value;
    
    while ((va_arg(args, char*)) != (char*)'\n') { 
        total += va_arg(check, int); // Lấy từng tham số từ danh sách đã sao chép
    }
   
    va_end(args);

    return total;
}

int main(void)
{
    
    printf("Tong la: %d\n", tong(4, 1, 0, 2, -1, 3)); 
    return 0;
}