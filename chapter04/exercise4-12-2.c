#include <stdio.h>
#include <string.h>

void itoa(int n, char s[])
{
  static int i = 0;

  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }

  if (n / 10)
    itoa(n / 10, s);
  s[i++] = (n % 10 + '0');
  s[i] = '\0';
}
main()
{
  char s[10];
  int n = -124;
  itoa(n, s);
  printf("%s\n", s);
}
