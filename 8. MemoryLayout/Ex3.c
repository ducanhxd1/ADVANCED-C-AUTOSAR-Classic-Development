// Ví dụ cho vùng Bss segment

#include <stdio.h>

typedef struct 
{
    int x;
    int y;
} Point_Data;

static Point_Data p1 = {0,0};
Point_Data p2;
Point_Data p3 = {0,1};

int a = 0;
int b;

static int global = 0;
static int global_2;

void test()
{
    static int global = 0;
    static int global_2;        
}

int main()
{
    test();
    return 0;
}