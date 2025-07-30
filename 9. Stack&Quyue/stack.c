#include "stack.h"

// hàm khởi tạo bộ nhớ cho ngăn xếp
/* 
    - Sử dụng hàm malloc() để cấp phát vùng nhớ của stack vùng nhớ này ở phân vùng heap.
    - Gán top = - 1 (rỗng)
 */
void Init_Stack(Stack* stack, int size)
{
    stack->items = (int*)malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;

    if(stack->items == NULL){
        fprintf(stderr, "Loi cap phat bo nho\n");
        exit(1);
    }
}

// hàm kiểm tra stack đầy
bool IsFull(Stack stack)
{
    return stack.top == stack.size - 1 ? true : false;
}

// hàm kiểm tra stack rỗng
bool IsEmpty(Stack stack)
{
    return stack.top == - 1 ? true : false;
}


// hàm thêm phần tử vào stack
/* 
    Kiểm tra nếu top + 1 == size → stack đầy.
    Nếu đầy, tăng gấp đôi size bằng realloc.
    Sau đó, tăng top, và gán data[top] = x.
*/
void Push2(Stack* stack, int data)
{
    // Nếu stack đầy -> mở rộng gấp 2 lần
    if(stack->top + 1 == stack->size) {
        int new_size = stack->size * 2;
        int new_items = realloc(stack->items, sizeof(int) * new_size);

        if (new_size == NULL) {
            printf("Khong the cap phat them bo nho\n");
        }
        stack->items = new_items;
        stack->size = new_items;
    }

    // them phan tu moi
    stack->top++;
    stack->items[stack->top] = data;
}


void Push1(Stack* stack, int data)
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
        // stack->items[stack->top--];
        stack->top--;
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
        return stack->items[stack->top];
    }
}

void HuyStack(Stack *stack)
{
    if(stack->items != NULL){
        free(stack->items);
        stack->items = NULL;
    }
    stack->top = -1;
    stack->size = 0;
    // free(stack->items);
}
