
# STRUCT
Đây là từ khóa để định nghĩa 1 kiểu dữ liệu người dùng, mục đích để tạo nên 1 kiểu dũ liệu để mô tả 1 đối tượng cụ thể nào đó khác với các kiểu dữ liệu nguyên thủy như int,float,double,...

## 1.1 Khai báo
Khai báo 1 struct để lưu trữ thông tin sinh viên thì

Ví dụ 
```C
  struct user{
    int lop;
    char ten[10];
  }
```
Cách sử dụng struct đã định nghĩa như sau

Ví dụ
```C
 int main(){
    struct user SV; // khai bao struct sinh vien
    SV.lop = 5;     // Gán thông tin cho sinh viên
    SV.name = "abc";
    printf("tuoi: %d\name: %s\n",student.tuoi,student.name);
    return 0;
};
```
Ngoài ra còn sử dụng từ khóa "typedef" để rút gọn việc khai báo kiểu dữ liệu struct

Ví dụ
```C
tyepdef struct{
    int lop;
    char name[10]; 
}user;

user SV; // tương đương với struct info SV;
user* ptr = &SV; // hoặc là một con trỏ

int main()
{
  SV.lop = 5;
  ptr -> lop = 10;
  printf("%d", ptr -> lop);
}
```
## 1.2 Kích thước của struct
Để có thể tính toán được kích thước của struct thì cần phải tìm hiểu các khái niệm sau đây

### 1.2.1. Data Alignment
- Là cách trình biên dịch (compiler) sắp xếp các biến thành viên bên trong struct sao cho tuân theo "yêu cầu căn chỉnh bộ nhớ" (memory alignment) để truy xuất bộ nhớ tối ưu trên phần cứng

Bộ vi xử lý thường truy xuất dữ liệu nhanh hơn nếu dữ liệu được đặt tại các địa chỉ bộ nhớ là bội số của kích thước dữ liệu đó.

```
  int thường cần được đặt ở địa chỉ chia hết cho 4 (giả sử int chiếm 4 byte).

  double thường cần địa chỉ chia hết cho 8 (nếu double chiếm 8 byte).

  struct myStruct {
    char a;   // 1 byte
    int b;    // 4 byte
  };
```
Ở ví dụ myStruct sẽ chiếm 5 byte nhưng thực tế thì không phải. Có thể sử sizeof(myStruct) để biết kích thước.

| Thành viên | Kích thước  | Căn chỉnh | Ghi chú                                 |
| ---------- | ----------- | --------- | --------------------------------------- |
| `char a`   | 1 byte      | 1 byte    |                                         |
| Padding    | 3 bytes     |           | Để `int b` nằm ở địa chỉ chia hết cho 4 |
| `int b`    | 4 bytes     | 4 bytes   |                                         |
| **Tổng**   | **8 bytes** |           | Do có padding                           |

* Như vậy tổng kích thước thực của struct là 8 byte. Mỗi lần nó sẽ cấp phát 4 byte do yêu cầu của việc căn chỉnh vùng nhớ và dựa vào biến có kiểu dữ liệu lớn nhất là int
+ Do đó tổng kích thước của struct sẽ luôn là con số chia hết cho kiểu dữ liệu lớn nhất được khai báo, địa chỉ bắt đầu của các thành phần trong struct cũng sẽ tuân theo quy luật này


### 1.2.2. Padding byte
+ Đây là những byte được thêm vào sau địa chỉ của mỗi biến được khai báo để đảm bảo được quy tắc căn chỉnh của từng thành viên hoặc cả struct. 

