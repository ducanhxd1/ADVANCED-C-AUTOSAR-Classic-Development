# MEMORY LAYOUT
RAM (random access memory)
Chương trình main.exe(trên window), main.hex (nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH.

Khi nhấn run chương trình trên Window(cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy 

Text segment(Code segment)

- Mã máy: chứa tập hợp các lệnh thực thi
- Quyền truy cập: Text Segment thường có quyền đọc và thực thi,


Data segment(Initilized Data)
- Chứa các biến toàn cục được khởi tạo vói giá trị khác 0.
- Chứa các biến static(global + local) được khởi tạo với giá trị khác 0.
- Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến.
- Với compiler Gcc/G++(windows): Data Segment còn lưu trữ biến hằng số toàn cục (const) và chuỗi hằng (string literal) nhưng quyền truy cập là chỉ đọc
- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.

Stack
- Chứa các biến cục bộ (trừ static cục bộ), tham số truyền vào.
- Chứa hằng số cục bộ, có thể thay đổi thông qua con trỏ.
- Quyền truy cập: đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.
- Sau khi ra khỏi hàm, tự động thu hồi vùng nhớ.
- Nguyên tắc hoạt động: LIFO (Last In First Out) - FILO (First In Last Out)
