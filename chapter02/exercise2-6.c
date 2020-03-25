#include <stdio.h>

#define MAXBITS 32

int mask(int n)
{
  int x = 0;
  if (n > 0) {
    x = 1;
  }
  while (n > 1) {
    x  = x << 1;;
    x += 1;
    n--;
  }
  return x;
}

int setbits(int x, int p, int n, int y)
{
  /* compute shift */
  int shift = MAXBITS - p - n;

  /* compute masks */
  int ymask = mask(n);
  int xmask = ~(ymask << shift);

  /* capture relevant bits */
  int t1 = x & xmask;
  int t2 = y & ymask;
  
  /* move rightmost n bits of y to p */
  t2 = t2 << shift;

  return t1 + t2;
}

void check(int x, int p, int n, int y, int expected, int actual)
{
  printf("x = %d, p = %d, n = %d, y = %d, expected = %d, actual = %d\n", x, p, n, y, expected, actual);
}

main()
{
  int x, p, n, y, expected;
  
  x = 172;
  p = 26;
  n = 3;
  y = 91;
  expected = 156;
  check(x, p, n, y, expected, setbits(x, p, n, y));

  x = -8;
  p = 0;
  n = 4;
  y = 117;
  expected = 1610612728;
  check(x, p, n, y, expected, setbits(x, p, n, y));
}
