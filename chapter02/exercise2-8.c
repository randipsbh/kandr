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

int rightrot(int x, int n)
{
  int t;
  /* create mask for n right bits */
  int xmask = mask(n);

  /* capture n bits and store in t */
  t = x & xmask;
  t = t << (MAXBITS - n);
  /* shift x by n bits to the right */
  x = x >> n;
  /* x = t | x and return x */
  x = x | t;

  return x; 

 /*  int xmask = mask(n);
  printf("xmask = %d\n", xmask);
  int t1 = x & xmask;
  printf("t1 = %d\n", t1);
  
  t1 = t1 << (MAXBITS - n);
  x =  x >> n;

  return x | t1; */
}

void check(int x, int n, int expected, int actual)
{
  printf("x = %d, n = %d, expected = %d, actual = %d\n", x, n, expected, actual);
}

main()
{
  int x, n;

  x = 89;
  n = 4;
  check(89, 4, -1879048187, rightrot(x, n));
}
