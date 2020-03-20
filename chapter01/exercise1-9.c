#include <stdio.h>

#define IN  1  /* inside whitespace */
#define OUT 0 /* outside whitespace */

main()
{
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (state == OUT) {
        state = IN;
        putchar(c);
      }
    } else {
        state = OUT;
        putchar(c);       
    }
  }
}
