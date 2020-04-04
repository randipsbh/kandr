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
void itoa(int n, char s[], int width)
{
  int i, donepadding, sign, spaces;
  sign = n;            /* record sign */
                       /* make n posiitve */

  i = 0;
  do {       /* generate digits in reverse order */
    s[i++] = abs(n  % 10)  + '0';    /* get next digit, abs to overflow in max signed value */
  } while ((n /= 10));      /* deelte it */
  if (sign < 0)
    s[i++] = '-';

  if (i < width) {    /* determine if padding is necessary */
    donepadding = width - i; /* determine index to stop padding */
    for (spaces = 0; spaces < donepadding; spaces++) {
      s[i++] = ' ';
    }
  }
  s[i] = '\0';
  reverse(s);
}

main()
{
  char s[10];
  itoa(-1254, s, 8);
  printf("%s\n", s);
}
