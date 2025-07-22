# STDARG 
Thư viện stdarg cung cấp các phương thức để làm việc với các hàm số có số lượng input parameter không cố định.

- va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
- va_start: bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
- va_arg: Truy cập một số đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai.
- va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. NÓ cần được gọi trước khi kết thúc hàm.