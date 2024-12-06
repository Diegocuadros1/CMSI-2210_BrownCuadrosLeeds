#include <stdio.h>

unsigned int isLittleEndian() {
    unsigned int x = 0x12345678;
    unsigned char *c = (unsigned char*)&x;

    if (c[0] == 0x78) {
        return 1;
    } else {
        return 0;
    }
}

unsigned int toBigEndian(unsigned int num) {
    // Swap the byte order:
    return ((num & 0x000000FF) << 24) |
           ((num & 0x0000FF00) << 8)  |
           ((num & 0x00FF0000) >> 8)  |
           ((num & 0xFF000000) >> 24);
}

unsigned int makeNBOC(unsigned int num) {
    if (isLittleEndian()) {
        printf("Your system is Little-Endian,swapping %i to Big-Endian.\n", num);
        return toBigEndian(num);
    } else {
        printf("Your system is Big-Endian, no swapping necessary for number %i.\n", num);
        return num;
    }
}
