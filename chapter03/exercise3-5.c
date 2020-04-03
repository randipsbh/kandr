#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
  int c, i, j;
  for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
  c = s[i];
  s[i] = s[j];
  s[j] = c;                              }
}

/* itoa: convert n to characters */
void itob(int n, char s[], int b)
{
  int i, sign;
  char r;
  sign = n;            /* record sign */
                       /* make n posiitve */

  i = 0;
  do {       /* generate digits in reverse order */
    r = abs(n % b);  /* get next digit, abs to avoid overflow in max signed value */
    if (0 <= r && r <= 9) 
      r += '0';
    else        /* for bases larger than 10 that require letter represnetation  */
      r += 55;
    s[i++] = r;
  } while ((n /= b));      /* deelte digit  it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

main()
{
  char s[10];
  itob(-11, s, 2);
  printf("%s\n", s);

  itob(-201, s, 16);
  printf("%s\n", s);
}
