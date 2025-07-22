#include <stdio.h>
#include <stdint.h>


uint8_t maybay;
uint8_t xemay;
uint8_t oto;
uint8_t tauhoa;
uint8_t tauthuy;
uint8_t status;

uint8_t user; // 0bxxxx xxxx
// bit 0: may bay
// bit 1: xe may
// bit 2: o to
// bit 3: tau hoa
// bit 4: tau thuy
// bit 5: status

0b01101100 << 4 = 0b11000000; // 0xC0 (phép dịch trái 4 bit)

0b01101100 >> 5 = 0b00000011; // 0x03 (phép dịch phải 5 bit)

NOT AND OR XOR 


int main(int argc, char const *argv[])
{
    
    return 0;
}
