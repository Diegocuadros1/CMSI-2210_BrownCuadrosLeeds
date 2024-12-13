#include <stdio.h>
#include <inttypes.h>

uint64_t sayHiTimes( uint64_t x ) {
   uint64_t count = 0;
   for( int i = 0; i < x; i++ ) {
      printf( "   Hello!\n" );
      count++;
   }
   return count;
}

