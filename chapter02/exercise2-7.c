#include <stdio.h>

#define MAXBITS 32

int mask(int n)
{
  int x = 0;
  if (n > 0) {
    x = 1;
  }
  while (n > 1) {
    x = x << 1;
    x += 1;
    n--;
  } 
  return x;
}

int invert(int x, int p, int n)
{
  int shift = MAXBITS - p - n;
  int xmask = mask(n);
  printf("xmask = %d\n", xmask);
  xmask = xmask << shift;
  printf("xmask = %d\n", xmask);

  int t1 = ~x & xmask;
  int t2 = x & ~xmask;

  return t1 + t2;
}

check(int x, int p, int n, int expected, int actual)
{
  printf("x = %d, p = %d, x = %d, expected = %d, actual = %d\n", x, p, n, expected, actual);
}

main()
{
  int x, p, n, expected;
  x = 53;
  p = 26;
  n = 3;
  expected = 13;
  check(x, p, n, expected, invert(x, p, n));
}
