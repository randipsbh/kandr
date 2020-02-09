#include <stdio.h>

#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

main()
{
  int c, state;
  /* remove white spaces */
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n' && c != '.') {
      putchar(c);
      break;
    }
  }
  state = IN;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n' && c != '.') {
      if (state == OUT) {
        putchar('\n');
        state = IN;
      } 
      putchar(c);
    } else {
      state = OUT;
    }

  }
  putchar('\n');
}
