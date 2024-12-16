#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Not the best; should be a command line argument!
#define NUMBER_OF_DARTS 100000
#define M_PI 3.1415926535

// Returns the 'c-squared' value of 'x' and 'y'
double squareOfDistanceToOrigin( double x, double y ) {
   return x * x + y * y;
}

// Returns a random value in [-1..1]
double randomValue() {
   return 2.0 * rand() / RAND_MAX - 1.0;
}

// The main program 'entry point'
int main() {
   int i;
   int inside = 0;
   srand( time(0) );

   for( i = 0; i < NUMBER_OF_DARTS; i++ ) {
      double x = randomValue();
      double y = randomValue();
      if( squareOfDistanceToOrigin(x, y) < 1.0 ) {
         inside++;
      }
   }
   printf( "Pi [est.]: %12.10f\n", \
           4.0 * ((double)inside / NUMBER_OF_DARTS) );
   printf( "[actual to 10 digits is %12.10f)\n", M_PI );

   return 0;
}