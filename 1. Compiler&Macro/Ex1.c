#include <stdio.h>

#define SIZE 20

void test()
{
    printf("Hello from test function\n");
}

#define CreateFunction(name) \
    void name() { \
        printf("Hello from " #name " function\n"); \
    }

CreateFunction(myFunction);
#undef SIZE 


int main(void)
{
    test();
    myFunction();
    
    return 0;
}
