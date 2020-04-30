#include <stdio.h>

#define swap(t, x, y) \
{ \
  t temp = x; \
  x = y; \
  y = temp; \
} \

main()
{
  int x = 5;
  int y = 10;
  printf("before macro swap\n x = %d\n y = %d\n", x, y);
  swap(int, x, y);
  printf("after macro swap\n x = %d\n y = %d\n", x, y);
}
