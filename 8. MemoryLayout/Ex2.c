// Ví dụ cho vùng Data segment

#include <stdio.h>

int data = 23;

static int static_global = 10;

const char* str1 = "this is str1"; // read-only -> .rdata segment

char* str2 = "this is str2";

const char str3[] = "this is str3"; 

char str4[] = "this is str4"; 

void test()
{
    static int static_local = 5;
    printf("Test\n");
}

int main()
{   
    // str1, str2, str3 chi read_only 

    str4[5] = 't';

    printf("%s\n", str4);

    test();
    return 0;
}