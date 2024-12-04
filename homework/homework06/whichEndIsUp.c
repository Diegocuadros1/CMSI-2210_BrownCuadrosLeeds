#include <stdio.h>

int main() {
    unsigned int x = 0x12345678;
    unsigned char *c = (unsigned char*)&x;

    printf("Memory representation: ");
    for (int i = 0; i < sizeof(x); i++) {
        printf("%02x ", c[i]);
    }
    printf("\n");

    if (c[0] == 0x78) {
        printf("Your system is Little-Endian.\n");
    } else if (c[0] == 0x12) {
        printf("Your system is Big-Endian.\n");
    } else {
        printf("Unknown endianness.\n");
    }

    return 0;
}