#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int32_t findGCD( int32_t, int32_t );

int main() {
    assert( findGCD( 24, 18 ) == 6 );
    assert( findGCD( 12, 16 ) == 4 );
    assert( findGCD( 12, 0 ) == 12 );
    assert(findGCD(0, 0) == 0);

    printf("Everything Runs correctly!!");
    return 0;
}
