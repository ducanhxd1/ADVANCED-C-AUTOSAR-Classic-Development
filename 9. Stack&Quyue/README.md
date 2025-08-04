# Ngăn xếp (STACK)
## Khái niệm:
Ngăn xếp (stack) là một cấu trúc dữ liệu tuyến tính, hoạt động theo nguyên tắc LIFO - Last In, First Out nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra.

## Các thao tác cơ bản:
| Tên thao tác | Ý nghĩa                                        | Diễn giải         |
| ------------ | ---------------------------------------------- | ----------------- |
| `push(x)`    | Thêm phần tử `x` vào đỉnh của stack            | "Push vào đỉnh"   |
| `pop()`      | Xóa và trả về phần tử ở đầu hàng đợi           | "Lấy phần tử đỉnh"|
| `isEmpty()`  | Kiểm tra ngăn xếp có rỗng: top = -1            |                   |
| `isFull()`   | Kiểm tra ngăn xếp có đầy : top = size-1        |                   |
| `peek()`     | Trả về phần tử ở đỉnh stack nhưng **không xóa**|                   |

🔸 Câu hỏi 1:
Tại sao biến top lại được khởi tạo là -1 chứ không phải 0?
- top = -1 là cách phổ biến để biểu thị rằng stack không chứa phần tử nào cả. Khi thêm phần tử đầu tiên, top được tăng lên 0, là chỉ số đầu tiên của mảng.

🔸 Câu hỏi 2:
Nếu muốn thêm phần tử vào stack, điều kiện gì cần kiểm tra trước?
- Nếu stack đầy (top == Size - 1), không thể thêm phần tử mới vào nếu không gây ra lỗi tràn bộ nhớ (overflow).

🔸 Câu hỏi 3:
Giả sử Size = 5, nếu top = 4 thì điều gì xảy ra khi gọi push(10)?
- Nếu không kiểm tra đầy trước khi push, thì sẽ ghi đè ra ngoài vùng nhớ cấp phát cho mảng, gây ra lỗi undefined behavior – tức là chương trình có thể crash, sai dữ liệu, hoặc bị khai thác lỗ hổng bảo mật. Không phải là “giá trị rác” mà là truy xuất trái phép.

🔸 Câu hỏi 4:
Tại sao cần realloc trong push?

Khi realloc() dùng để mở rộng bộ nhớ khi stack đầy, và nó cố gắng giữ nguyên vùng nhớ cũ nếu có thể. Nếu không đủ chỗ, nó sẽ:
+ Cấp phát vùng nhớ mới có size lớn hơn.
+ Copy dữ liệu từ vùng cũ sang.
+ Giải phóng vùng cũ.

🔸 Câu hỏi 5:
Tại sao nên tăng gấp đôi capacity khi stack đầy, thay vì chỉ tăng một ít?
- Việc tăng gấp đôi (realloc()) giúp cải thiện hiệu suất 
- Thay vì push() -> realloc() -> size tăng (+1) (+10) sẽ phải sử dụng realloc() nhiều lần
- Ngược lại, push() -> realloc() -> size tăng (+8) >> (+16) ==> Chỉ cần realloc() 1 lần 

🔸 Câu hỏi 6:
Sau khi gọi pop, có nên giảm capacity không? Vì sao?
Không nên giảm vì :
- Nếu mỗi lần pop() mà giảm bộ nhớ (realloc nhỏ hơn) sẽ gây tốn tài nguyên và chậm.
- Thường chỉ giảm nếu top nhỏ hơn một phần rất nhỏ (ví dụ: 1/4 capacity), để tránh giữ thừa bộ nhớ lâu dài.

Ứng dụng thực tế :


# Hàng đợi (QUEUE)
## Khái niệm:
Hàng đợi (queue) là một cấu trúc dữ liệu tuyến tính, hoạt động theo nguyên tắc FIFO - First In First Out. Phần tử được thêm vào đầu tiên sẽ lấy ra đầu tiên.

## Các thao tác cơ bản:
| Tên thao tác | Ý nghĩa                                        | Diễn giải         |
| ------------ | ---------------------------------------------- | ----------------- |
| `enqueue(x)` | Thêm phần tử `x` vào cuối hàng đợi             | "Push vào sau"    |
| `dequeue()`  | Xóa và trả về phần tử ở đầu hàng đợi           | "Lấy phần tử đầu" |
| `isEmpty()`  | Kiểm tra hàng đợi có rỗng không                |                   |
| `isFull()`   | Kiểm tra hàng đợi có đầy không                 |                   |
| `peek()`     | Trả về phần tử đầu tiên nhưng **không xóa**    |                   |

Ứng dụng thực tế :
- Hệ thống xử lý yêu cầu (vd: người chờ mua vé,...)
- Điều phối tiến trình trong hệ điều hành (CPU scheduling)
