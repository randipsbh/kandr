#include <stdio.h>      /* printf */
#include <string.h>     /* strlen */
#include <math.h>       /* pow */

int ctoi(char c) {
  if ('9' >= c && c >= '0') {
    return c - 48;
  }
  if ('F' >= c && c >= 'A') {
    return c - 55;
  }
  if (102 >= c && c >= 97) {
    return c - 87;
  }
  return -1;
}

int htoi(char* s)
{
  int begin, end, sum, i, j;
  
  /* determine the beginning */
  begin = 0;
  if (strlen(s) > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    begin = 2;
  }
  end = strlen(s) - 1;;
  
  /* compute the hex sum */
  sum = 0;
  for (i = end, j = 0; i >= begin; i--, j++) {
    sum += ctoi(s[i]) * pow (16.0, j);
  }

  return sum;
}

void check(char* hex, int expected, int actual) {
  printf("%s, expected = %d, actual = %d\n", hex, expected, actual);
}

main()
{
  char *hex;

  hex = "0x1234";
  check(hex, 4660, htoi(hex));
  hex = "0X1234";
  check(hex, 4660, htoi(hex));
  hex = "1234";
  check(hex, 4660, htoi(hex));
  hex = "0x0";
  check(hex, 0, htoi(hex));
  hex = "0X0";
  check(hex, 0, htoi(hex));
  hex = "0";
  check(hex, 0, htoi(hex));
  hex = "C9";
  check(hex, 201, htoi(hex));
  hex = "abcd";
  check(hex, 43981, htoi(hex));
}
