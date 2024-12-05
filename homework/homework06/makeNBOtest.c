#include <stdio.h>

unsigned int makeNBOC(unsigned int num);

int main() {
    unsigned int x = 0x12345678;
    x = makeNBOC(x);
    printf("%u\n", x);
    x = makeNBOC(x);
    printf("%u\n", x);
    return 0;
}