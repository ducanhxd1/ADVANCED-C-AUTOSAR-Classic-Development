# Compiler và Quá Trình Biên Dịch

## Giới thiệu về Compiler


Compiler (Trình biên dịch) là một công cụ quan trọng trong quá trình phát triển phần mềm, chuyển đổi mã nguồn từ ngôn ngữ lập trình cấp cao (như C/C++) sang mã máy mà vi xử lý có thể hiểu và thực thi. Compiler không chỉ đơn thuần chuyển mã mà còn tối ưu hóa mã, phát hiện lỗi và cung cấp những thông báo cảnh báo có giá trị trong quá trình phát triển.

### Lý do sử dụng Compiler
- **Cầu nối giữa máy tính và người lập trình**: Compiler giúp máy tính có thể hiểu và thực thi mã nguồn người lập trình viết.
- **Hỗ trợ tối ưu hóa**: Compiler có thể tối ưu hóa mã nguồn giúp chương trình chạy nhanh hơn và sử dụng ít tài nguyên hơn.
- **Phát hiện lỗi**: Compiler giúp phát hiện các lỗi cú pháp và logic trong mã nguồn.

### Quá trình Biên Dịch 


__Quá trình biên dịch gồm các bước chính sau:__
```
1. Preprocessing: Tiền xử lý mã nguồn, bao gồm việc xử lý các macro và include (file.i)
2. Compilation: Biên dịch mã nguồn thành mã trung gian (file.s).
3. Assembly: Chuyển mã trung gian thành mã máy (file.o)
4. Linking: Liên kết các phần của chương trình thành một file thực thi (file.exe)

```

## 1. Preprocessing và Các Macro

### 1.1 `#include`
- **Mục đích**: Dùng để đưa các file header vào chương trình.
- **Cách sử dụng**:
  - `"file.h"`: Dùng cho file header trong cùng thư mục.
  - `<file.h>`: Dùng cho thư viện hệ thống hoặc thư viện ngoài.


### 1.2 `#define`
- **Mục đích**: định nghĩa macro để thay thế 1 đoạn văn bảng, hằng số, chuỗi, hàm 
   __Ví dụ__: Gọi hàm thông qua macro
  ```c
  #define CREATE_FUNCTION(name,STR) \
  void name(){            \
      printf(STR);    \
  }

  //thay thế ở bước tiền xử lý
  /* 
    void func1(){ printf("this is function 1\n"); };
    void func2(){ printf("this is function 2\n"); };
    void func3(){ printf("this is function 3\n"); };
   */
  CREATE_FUNCTION(func1,"this is function 1\n");
  CREATE_FUNCTION(func2,"this is function 2\n");
  CREATE_FUNCTION(func3,"this is function 3\n");
  int main(){
    func1(); 
  }

   __Ví dụ__ : Khai báo 1 mảng dùng macro và biến thông thường 
  ```c
  #define SIZE 5
  int size = 5;
  //lỗi do trình biên dịch phát hiện đây là 1 biến chứ không phải hằng số 
  int arr[size] = {1, 2, 3, 4, 5};
  //trình biên dịch tìm và thay thế nội dung macro
  int arr[SIZE] = {1,2,3,4,5};

- **Phân tích**:
  - __Macro__ sẽ thay thế ARRAY_SIZE bằng giá trị 5 trong quá trình biên dịch, do đó không yêu cầu cấp phát bộ nhớ tại runtime.

  - __Biến__ yêu cầu cấp phát bộ nhớ tại runtime và giá trị có thể thay đổi trong quá trình chạy.


   __Ví dụ__: tính bình phương bằng Macro và hàm 

  __Macro__
  ```c 
  #define SQUARE(x) ((x) * (x))
  int main() {
      int num = 5;
      int result = SQUARE(num); // Kết quả: 25
  }
  ``````
  __Hàm__
  ```c
  int square(int x) {
    return x * x;
  }

  int main() {
      int num = 5;
      int result = square(num); // Kết quả: 25
  }
  

- **Phân tích**:

  __Macro__: Sử dụng #define để thay thế đoạn mã khi biên dịch, không kiểm tra kiểu dữ liệu và không có kiểm tra lỗi. Tuy nhiên, nếu đối số là biểu thức có dấu ngoặc đơn như SQUARE(2 + 3), kết quả có thể không như mong đợi do thiếu dấu ngoặc.

  __Hàm__: Có thể kiểm tra kiểu dữ liệu, hỗ trợ giá trị truyền vào dạng phức tạp và dễ dàng bảo trì mã nguồn.

### 1.3 `#undef`
  **Mục đích**: Hủy định nghĩa của 1 macro.
  ```c
  #define MAX_SIZE 10
  #undef MAX_SIZE
  ```
### 1.4 `Macro Mở rộng`
- **# và ##**
    - `#` : chuẩn hóa văn bản thành chuỗi
    - `##`: nối các đối số vào đoạn văn bản
  ```c
  #define CREATE_VAR(name) \
  int int_##name;        \ 
  double double_##name;  \
  float float_##name;

  #define CREATE_STRING(str) printf(#str)

  int main(){
    CREATE_VAR(sensor);
    CREATE_STRING(asdwadw);
  }
  ```
  __Kết quả bước tiền xử lý__

  ```c
  int int_sensor; double double_sensor; float float_sensor;;
  printf("asdwadw");
  ```

- **Variadic Macros** : cho phép truyền vào 1 số lượng đối số không xác định
  ```c
  #define SUM(...) sum(__VA_ARGS__)  
    - `...` : cho phép nhận vào các đói số
    - `__VA_ARGS__` : thay thế các đối số truyền vào 

  ```
   __Ví dụ__ : Tính tổng danh sách phần tử đối số

  __Cách 1:__ sử dụng sizeof() để xác định số lượng đối số
  ```c
  // xác định số phần tử của array
  /*
      + Size toàn bộ array : sizeof(array)
      + Size phần tử đầu : sizeof(array[0])
      => số phần tử = sizeof(array) / sizeof([0])
  */
  #define SUM(...)                               \
    int arr[] = {__VA_ARGS__};                   \
    int i = 0;                                   \
    int tong = 0;                                \
    for (; i < sizeof(arr) / sizeof(arr[0]); i++) \
    {                                            \
      tong += arr[i];                            \
    }                                            \
    printf("tong:%d\n", tong);
  ```

  __Cách 2:__ Sử dụng phần tử cuối để xác định độ dài danh sách 
  ```c
  #define SUM(...)                               \
    int arr[] = {__VA_ARGS__,0};                 \
    int i = 0;                                   \
    int tong = 0;                                \
    while(arr[i] != 0)                           \
    {                                            \
      tong += arr[i++];                          \
    }                                            \
    printf("tong:%d\n", tong);
    ```
  

### 1.5 Chỉ thị biên dịch có diều kiện
- **#ifdef / #ifndef / #error /#endif**: kiểm tra sự tồn tại của 1 macro và tránh khai báo lại nhiều lần
    - `#ifdef` : nếu 1 macro đã định nghĩa thì thực hiện đoạn code bên dưới
    - `#ifndef`: nếu 1 macro chưa được định nghĩa thì thực hiện đoạn code bên dưới
    - `#error`:  tạo đoạn mã lỗi tự động hiển thị ở bước tiền xử lý dựa trên thiết kế của các chỉ thị biên dịch khác 
    - `#endif` : chỉ thị kết thúc khối #ifdef, #ifndef, #else, hoặc #elif
  ```C
  #ifndef MAX_SIZE
  #define MAX_SIZE 100
  #endif
  ```

  **Ứng dụng** : Thiết kế thư viện theo tiên chuẩn đối dự án phức tạp chứa nhiều file nguồn. Với các đặc điểm 
  + Mỗi tệp (.c) sẽ có 1 tệp (.h) tương ứng
  + Giúp tách biệt phần định nghĩa và khai báo
  + Khai báo với include guard giúp bước tiền xử lý chỉ thực hiện thay thế nội dung của tệp header 1 lần
  + Tránh lỗi định nghĩa lại hoặc thay thế nội dung nhiều lần, giúp tối ưu quá trình xử lý và biên dịch 

  __Ví dụ__:
  ```c
  #ifndef HEADER_FILE_H    // Nếu HEADER_FILE_H chưa được định nghĩa
  #define HEADER_FILE_H    // Định nghĩa HEADER_FILE_H

  // Mã trong header file bao gồm
  /*
  - khai báo nguyên mẫu hàm
  - định nghĩa struct,union
  - khai báo biến chia sẻ giữa nhiều tệp
  */

  #endif  // Kết thúc chỉ thị #ifndef
  ```



- **#if, #elif, #else**: Kiểm tra các điều kiện biên dịch khác nhau 
  ```c
  // Định nghĩa các loại MCU
    #define STM32    1
    #define ESP32    2
    #define ATMEGA   3

    // Chọn loại MCU
    #define MCU STM32

    // Cấu hình GPIO phù hợp với MCU
    #if MCU == STM32
        void gpio()
        {
            printf("GPIO initialized for STM32\n");
        }

    #elif MCU == ESP32
        void gpio()
        {
            printf("GPIO initialized for ESP32\n");
        }

    #else MCU == ATMEGA

        void gpio()
        {
            printf("GPIO initialized for ATmega\n");
        }

    #endif
  ```


### 1.6 `Tổng kết quá trình tiền xử lý`
**Các bước**:
  - mở rộng mã nguồn (.c) sang mã tiền xử lý (.i)
  - Xóa các comment
  - xử lý các điều kiện tiền xử lý
    
    => chỉ thị biên dịch có điều kiện : lựa chọn đoạn mã để thực thi dựa trên sự tồn tại của macro và điều kiện biên dịch khác nhau
    
    =>  chỉ thị thay thế tệp : thay thế nội dung trong các file header
    
    =>  chỉ thị thay thế macro : thay thế tên macro bằng đoạn văn bản thay thế 
- **Cú pháp**:
  ```c
  gcc -E main.c -o main.i
## 2. Compilation (Biên dịch)
- **Mục đích** : dịch mã tiền xử lý sang mã trung gian (.s), cho phép thao tác trên các thanh ghi hệ thống, để quyết định cách thức lưu trữ và xử lý dữ bao gồm các bước 
  + ánh xạ và lưu trữ các biến vào thanh ghi hoặc bộ nhớ RAM
  + chuyển đổi các phép toán và lệnh vào thanh ghi

  Mã nguồn C
  ```c 
  int x = 10, y = 20, z;
  z = x + y;
  ```
  Assembly
  ```c
  MOV R0, #10   ; x = 10
  MOV R1, #20   ; y = 20
  ADD R2, R0, R1 ; z = x + y


- **Cú pháp:**
  ```c
  gcc -S main.i -o main.s

## 3. Assembler (Hợp dịch)
- **Mục đích**: dịch mã trung gian (.s) sang ngôn ngữ cấp thấp cụ thể là mã máy(.o), chứa file nguồn thể hiện dưới các giá trị binary mà máy chỉ có thể hiểu và xử lý
- **Cú pháp:**
  ```c
  gcc -o main.i -o main.i

## 4. Linker (Liên kết)
- **Mục đích** : Liên kết nhiều tệp mã máy (.o) lại với nhau (nếu có) để tạo ra tệp thực thi (.exe), là tệp kết quả chạy chương trình. Gồm các bước
  + Kết nối các thư viện hệ thống và tệp header
  + Tìm và liên kết lời gọi hàm và định nghĩa của chúng
  + Báo lỗi nếu gọi hàm chưa được định nghĩa

- **Cú pháp:**
  ```c
  gcc main.o out1.o out2.o -o run.exe
  ```

- **Câu lệnh xử lý tổng các bước**
  ```c
  gcc main.c out1.c out2.c -o run.exe
  ```
