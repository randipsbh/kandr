#include <stdio.h>
#include <limits.h>
#include <math.h>

long pow2(int e);
void printSigned(char*label, long min, long max, long expectedMin, long expectedMax);
void printUnsigned(char* label, unsigned long actualMin, unsigned long actualMax, unsigned long expectedMin, unsigned long expectedMax);

main()
{
  unsigned long ulMax;
  signed long lMax;
  printUnsigned("unsigned char", 0, pow2(sizeof(unsigned char)*8) - 1, 0, UCHAR_MAX);
  printUnsigned("unsigned short", 0, pow2(sizeof(unsigned short)*8) - 1, 0, USHRT_MAX);
  printUnsigned("unsigned int", 0, pow2(sizeof(unsigned int)*8) - 1, 0, UINT_MAX);
  ulMax = pow2(sizeof(unsigned long)*8 - 1) + (pow2(sizeof(unsigned long)*8 - 1) - 1);
  printUnsigned("unsigned long", 0, ulMax, 0, ULONG_MAX);
  printSigned("signed char", -(pow2(sizeof(signed char)*8 - 1)), pow2(sizeof(signed char)*8 - 1) - 1, SCHAR_MIN, SCHAR_MAX);
  printSigned("signed short", -(pow2(sizeof(signed short)*8 - 1)), pow2(sizeof(signed short)*8 - 1) - 1, SHRT_MIN, SHRT_MAX);
  printSigned("signed int", -(pow2(sizeof(signed int)*8 - 1)), pow2(sizeof(signed int)*8 - 1) - 1, INT_MIN, INT_MAX);
  printSigned("signed long", -(pow2(sizeof(signed long)*8 - 1)), pow2(sizeof(signed long)*8 - 1) - 1, LONG_MIN, LONG_MAX);
}

long pow2(int e) {
  return 1ul << e;
}

void printSigned(char* label, long actualMin, long actualMax, long expectedMin, long expectedMax)
{
  printf("range for %s is %ld to %ld (expected %ld to %ld)\n", label, actualMin, actualMax,
    expectedMin, expectedMax);
}

void printUnsigned(char* label, unsigned long actualMin, unsigned long actualMax, unsigned long expectedMin, unsigned long expectedMax)
{
  printf("range for %s is %lu to %lu (expected %lu to %lu)\n", label, actualMin, actualMax,
    expectedMin, expectedMax);
}
