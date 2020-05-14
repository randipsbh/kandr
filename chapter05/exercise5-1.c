#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too any characters\n");
  else
    buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))   /* skip white spae */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);  /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 :  1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c)) {
      ungetch((sign == 1) ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != sign)
    ungetch(c);
  return c;
}

main()
{
  int n, i, array[SIZE], getint(int *);

  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    printf("%d\n", array[n]);
}
