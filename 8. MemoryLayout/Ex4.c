#include <stdio.h>

//stack frame :
/*
    - return address
    - tham so
    - biến cục bộ
    - thanh ghi lưu trữ kết quả hoặc trạng thái trước đó của chương trình.
*/
int *p = NULL;

int test(int a, int b)
{
    int c = a + b;
    int d = c + 10;
    printf("&b = %p\n", &b);
    printf("&a = %p\n", &a);
    printf("&c = %p\n", &c);
    printf("&d = %p\n", &d);
    /*
        &b = 0000008F377FFA78
        &a = 0000008F377FFA70
        &c = 0000008F377FFA5C
        &d = 0000008F377FFA58
        => địa chỉ giảm dần, 
        khi ở trên stack thứ tự cấp phát theo tham số truyền vào là từ phải -> trái
        mỗi lần gọi hàm thì sẽ cấp phát địa chỉ mới, ko ảnh hưởng đến tham số truyền vào trong hàm main() 
    */

    /* const int e = 12;
    p = (int*)&e;
    *p = 10;
    printf("e = %d", e); 
    */
    return d;
}

int main()
{

    int a = 1, b =2;    
    int res = test(a, b);
    return 0;
}