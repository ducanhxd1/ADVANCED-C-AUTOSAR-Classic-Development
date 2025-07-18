#include <stdio.h>

struct MyStruct {
    char a;   // 1 byte
    int b;    // 4 bytes
};

int main()
{   
    struct MyStruct st;
    sizeof(st);
    
    return 0;
}
