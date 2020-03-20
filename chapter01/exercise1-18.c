#include <stdio.h>
#define MAX 1000    /* maximum input line length */


main()
{
  /* if you get a tab or space store it in a buffer */
  /* if you get a non tab space or new line then print the buffer, print the
     char and reset the buffer */
  /* if you get a new line character do not print buffer */
  int c, i, j;
  char buffer[MAX];
  j = 0; // character count per line
  i = 0; // next buffer index
  c = getchar();
  while (c != EOF) {
    while (c != EOF && c != '\n') {
      if (c != ' ' && c != '\t') {
        /* null terminate buffer */
        buffer[i] = '\0';

        /* print the character after the buffer */
        printf("%s", buffer);

        /* reset the buffer */
        i = 0;

        /* print the next character */
        putchar(c);
      }
      if (c == ' ' || c == '\t') {
        buffer[i++] = c;
      }

      // get next character, update count
      c = getchar();
      j++;
    }
    if (i != j && c == '\n') {
      printf(" %d", j);
      putchar(c);
    }

    /* reset the counters */
    i = 0;
    j = 0;

    /* get the next character */
    c = getchar();
  }

  return 0;
}

