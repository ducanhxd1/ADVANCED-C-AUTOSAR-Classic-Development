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
    int* items;
    int size;
    int top;
} Stack;

// hàm khởi tạo bộ nhớ cho ngăn xếp
void Init_Stack(Stack* stack, int size);

// hàm kiểm tra stack đầy
bool Isfull(Stack stack);

// hàm kiểm tra stack rỗng
bool IsEmpty(Stack stack);

// hàm thêm phần tử vào stack
void Push(Stack* stack, int data);

// hàm xoa phần tử o dinh stack
int Pop(Stack* stack, int data);

// hàm giải phóng stack
void FreeStack(Stack *stack);
#endif  