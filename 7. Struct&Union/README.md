
# STRUCT
Đây là từ khóa để định nghĩa 1 kiểu dữ liệu người dùng, mục đích để tạo nên 1 kiểu dũ liệu để mô tả 1 đối tượng cụ thể nào đó khác với các kiểu dữ liệu nguyên thủy như int,float,double,...

## 1.1 Khai báo
Khai báo 1 struct để lưu trữ thông tin sinh viên thì

Ví dụ 
```C
  struct info{
    int lop;
    char ten[10];
  }
```
Cách sử dụng struct đã định nghĩa như sau

Ví dụ
```C
 int main(){
    struct info SV; // khai bao struct sinh vien
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
}info;

info SV; // tương đương với struct info SV;
```
