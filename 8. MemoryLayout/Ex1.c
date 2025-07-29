#include <stdio.h>




void test()
{
    static int static_local = 5;
    printf("Test\n");
}

int main()
{
    
    test();
    return 0;
}
