#include <stdio.h>
#include <string.h>

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = low + (high - low)/2;
    if (x < v[mid])
      high = mid + 1;
    else if (x > v[mid])
      low = mid + 1;
    else  /* found match */
      return mid;
  }
  return -1;  /* no match */
}

int check(int x, int v[], int n, int expected)
{
  int i;
  int actual = binsearch(x, v, n);
  printf("x = %d, ", x);
  
  printf("v = ");
  for (i = 0; i < n; i++) {
    printf("%d, ", v[i]);
  }

  printf("n = %d, expected = %d, actual = %d\n", n, expected, actual);
}

main()
{
  int v1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int v2[] = {0, 5, 10};
  int v3[] = {0, 2, 4, 6, 8, 9, 10, 12, 14, 16, 18, 19, 22};

  check(2, v1, 8, 1);
  check(10, v2, 3, 2);
  check(10, v3, 13, 6);
}

