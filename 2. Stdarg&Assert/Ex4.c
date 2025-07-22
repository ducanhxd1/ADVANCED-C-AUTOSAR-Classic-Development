#include <stdio.h>
#include <stdarg.h>

typedef struct
{
    int x;
    double y;
} Data;

void display(int count,...)
{
    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        Data tmp = va_arg(args, Data);
        printf("Data.x at %d is: %d\n", i, tmp.x);
        printf("Data.y at %d is: %.2f\n", i, tmp.y);
    }

    va_end(args);
}

int main(void)
{
    Data d1 = {1, 1.1};
    Data d2 = {2, 2.2};
    Data d3 = {3, 3.3};

    display(3, d1, d2, d3); 

    return 0;
}