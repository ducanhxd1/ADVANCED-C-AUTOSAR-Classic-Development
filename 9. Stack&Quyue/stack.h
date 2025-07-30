#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// heap
// stack

// mảng 
// kích thước -> size
// top

// cấu trúc ngăn xếp
typedef struct {
    int* items; // Con trỏ tới mảng động chứa các phần tử stack
    int size;   // Sức chứa hiện tại của mảng
    int top;    // Vị trí đỉnh của stack (-1 khi rỗng)
} Stack;

// hàm khởi tạo bộ nhớ cho ngăn xếp
void Init_Stack(Stack* stack, int size);

// hàm kiểm tra stack đầy
bool IsFull(Stack stack);

// hàm kiểm tra stack rỗng
bool IsEmpty(Stack stack);

// hàm thêm phần tử vào stack
void Push1(Stack* stack, int data);

// hàm xoa phần tử o dinh stack
int Pop(Stack* stack, int data);

// hàm giải phóng stack
void FreeStack(Stack *stack);
#endif  