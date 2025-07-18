
# POINTER
- Con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn.
- Thông qua con trỏ có thể thay đổi giá trị tại biến mà nó trỏ tới

- Cách khai báo:

    ```C
        int x = 10;
        int *ptr = &x;  // ptr giờ đây chứa địa chỉ của x
        *ptr =5;
        >> x bằng5
    ```
