#include <stdarg.h>
#include <stdio.h>

// dấu "..." : biểu thị cho số lượng tham số không xác định
// va_list: kiểu dữ liệu để lưu trữ danh sách các tham số không xác định    
// va_start: macro để khởi tạo danh sách tham số, xác định tham số đầu tiên sau khi so sánh với label để tách chuỗi
// va_copy: macro để sao chép danh sách tham số
// va_arg: macro để truy cập từng tham số trong danh sách
// va_end: macro để kết thúc việc truy cập danh sách tham số
void test(int count, ...)
{
    va_list args;
    // typedef char* va_list; // định nghĩa va_list là con trỏ đến char

    va_start(args, count);
    
    // for (int i = 0; i < count; i++) {
    //     int value = va_arg(args, int);
    //     printf("Value %d: %d\n", i + 1, value);
    // }

    printf("Value 1: %d\n", va_arg(args, int)); // (int)"\001" = 10 ép kiểu char* sang int
    printf("Value 2: %d\n", va_arg(args, int));
    printf("Value 3: %c\n", va_arg(args, char*));
    printf("Value 4: %s\n", va_arg(args, char*));

    va_end(args); // thu hồi tài nguyên đã cấp phát cho danh sách tham số 
}


int main()
{

    test(4, 10, 20, 'a', "hello"); // Gọi hàm test với 4 tham số
    return 0;

}