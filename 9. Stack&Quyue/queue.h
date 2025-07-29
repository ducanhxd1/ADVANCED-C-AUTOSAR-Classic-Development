#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Cấu trúc dữ liệu queue */
typedef struct {
    int* data;   // con trỏ mảng động
    int front;   // chỉ số đầu hàng đợi
    int rear;    // chỉ số cuối hàng đợi
    int size;    // kích thước 
} Queue;

/**
 * @brief Khởi tạo hàng đợi: cấp phát bộ nhớ động cho mảng, đặt front, rear = -1.
 * 
 * - Queue*q : con trỏ kiểu hàng đợi trỏ đến các biến thành viên
 * - size : kích thước để cấp phát vùng nhớ mảng động
 */
void initQueue(Queue* q, int size);

bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void display(Queue* q);
void freeQueue(Queue* q);




#endif 