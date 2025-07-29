#include "queue.h"

/*  - Cấp phát động mảng `data` với kích thước `size`
    - Đặt `front = -1`, `rear = -1`
    - Gán `q->size = size`
 */
void initQueue(Queue *q, int size)
{
    q->data = (int *)malloc(sizeof(int));
    q->rear = q->rear = -1;
    q->size = size;
}

/*
 * Chức năng: Kiểm tra hàng đợi rỗng (không có phần tử nào)
 * - Trả về true nếu `front == -1`
 */
bool isEmpty(Queue *q)
{
    return q->front == -1 ? true : false;
}

/*
 * Chức năng: Kiểm tra hàng đợi đầy 
 * - Trả về true nếu `rear == size - 1` (hàng đợi đầy)
 */
bool isFull(Queue *q)
{
    return q->rear == q->size - 1 ? true : false;
}

/*
 * Chức năng: Thêm 1 phần tử vào cuối hàng đợi
 * - 1. Kiểm tra hàng đợi đầy -> In ra thông báo và return
 * - 2. Nếu hàng đợi rỗng (front == - 1): thì gán front = 0
 * - 3. Tăng rear: rear++
 * - 4. Gán data[rear] = value
 */
void enqueue(Queue *q, int value)
{
    if(isFull(q)) {
        printf("Hàng đợi đầy không thể thêm phần tử mới\n");
        return;
    }
    if(isEmpty(q))  q->front = 0;
    q->rear++;
    q->data[q->rear] = value;
}

/*
 * Chức năng: Xóa phần tử ở đầu hàng đợi và trả về giá trị đó.
 * - 1. Nếu hàng đợi rỗng -> In ra thông báo và return
 * - 2. Lưu lại giá trị tại data[front]
 * - 3. Nếu front == rear: 
 *      - Tức là chỉ còn 1 phần tử -> đặt front = rear = -1
 * - 4. Ngược lại: 
 *      - Tăng front : front++
 * - 5. Trả về giá trị vừa lưu
 */
int dequeue(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Hàng đợi rỗng không có phần tử nào để xóa\n");
        return -1;
    }
    
    int value = q->data[q->front];

    if(q->front == q->rear)
    {
        q->front = q->rear = -1; 
    } 
    else 
    {
        q->front++;
    }

    return value;
}

/*
 * Chức năng: In tất cả phần tử trong hàng đợi
 * - 1. Nếu hàng đợi rỗng -> In ra thông báo 
 * - 2. Duyệt từ front đến rear:
 *      - In từng phần tử data[i]
 * 
 */
void display(Queue *q)
{
    if(isEmpty(q)) {
        printf("Hàng đợi rỗng không có phần tử nào được in ra màn hình\n");
        return;
    }
     
    for(int i = q->front; i <= q->rear; i++)
    {
        printf("%d \n", q->data[i]);
    }
}

/*
 * Chức năng: Giải phóng bộ nhớ đã cấp phát
 * - 1. Gọi hàm free (q->data) 
 * - 2. Đặt các biến về trạng thái ban đầu nếu cần.
 * 
 */
void freeQueue(Queue *q)
{
    free(q->data);
    q->front = q->rear = -1;
    q->size = 0;
    q->data = NULL;
}
