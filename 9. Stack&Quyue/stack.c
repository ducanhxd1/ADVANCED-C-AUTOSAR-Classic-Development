#include "stack.h"

// hàm khởi tạo bộ nhớ cho ngăn xếp
void Init_Stack(Stack* stack, int size)
{
    stack->items = (int*)malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

// hàm kiểm tra stack đầy
bool Isfull(Stack stack)
{
    return stack.top == stack.size - 1 ? true : false;
}

// hàm kiểm tra stack rỗng
bool IsEmpty(Stack stack)
{
    return stack.top == - 1 ? true : false;
}

// hàm thêm phần tử vào stack
void Push(Stack* stack, int data)
{
    if(!Isfull(*stack))
    {
        stack->top++;
        stack->items[stack->top] = data;
        printf("thêm %d", stack->items[stack->top]);
    } 
    else {
        printf("stack đầy\n");
    }
}

// hàm xoa phần tử o dinh stack
int Pop(Stack* stack, int data)
{
    if(!IsEmpty(*stack)){
        int data = stack->items[stack->top];
        stack->items[stack->top--];
        return data;
    }
    else {
        printf("stack rỗng\n");
        return -1;
    }
}

int Top(Stack* stack, int data)
{
    if(!IsEmpty(*stack)) return -1;
    else {

    }
}