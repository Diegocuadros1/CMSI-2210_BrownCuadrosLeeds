#include <stdio.h>
#include <winsock2.h> 


unsigned int isLittleEndian();

unsigned int makeNBOC(unsigned int num) {
    if (isLittleEndian()) {
        printf("Your system is Little-Endian,swapping %i to Big-Endian.\n", num);
        return htonl(num);
    } else {
        printf("Your system is Big-Endian, no swapping necessary for number %i.\n", num);
        return num;
    }
}


unsigned int isLittleEndian() {
    unsigned int x = 0x12345678;
    unsigned char *c = (unsigned char*)&x;

    if (c[0] == 0x78) {
        return 1;
    } else {
        return 0;
    }
}
