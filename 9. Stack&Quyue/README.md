# Hàng đợi (QUEUE)
## Khái niệm:
Hàng đợi (queue) là một cấu trúc dữ liệu tuyến tính, hoạt động theo nguyên tắc FIFO - First In First Out. Phần tử được thêm vào đầu tiên sẽ lấy ra đầu tiên.

### Các thao tác cơ bản:
| Tên thao tác | Ý nghĩa                                        | Diễn giải         |
| ------------ | ---------------------------------------------- | ----------------- |
| `enqueue(x)` | Thêm phần tử `x` vào cuối hàng đợi             | "Push vào sau"    |
| `dequeue()`  | Xóa và trả về phần tử ở đầu hàng đợi           | "Lấy phần tử đầu" |
| `isEmpty()`  | Kiểm tra hàng đợi có rỗng không                |                   |
| `isFull()`   | (nếu dùng mảng) Kiểm tra hàng đợi có đầy không |                   |
| `peek()`     | Trả về phần tử đầu tiên nhưng **không xóa**    |                   |

Ứng dụng thực tế :
- Hệ thống xử lý yêu cầu (vd: người chờ mua vé,...)
- Điều phối tiến trình trong hệ điều hành (CPU scheduling)
