#include <stdio.h>
#define TABSTOP 8
main()
{
	int c, col, spaces;

	c = getchar();
  col = 0;
	while (c != EOF) {
    if (c == '\t') {
      spaces = TABSTOP - (col % TABSTOP);
      while (spaces > 0) {
        putchar(' ');
        spaces--;
      }
      col += spaces;
    } else if (c != '\n') {
      putchar(c);
      col++;
    } else {
      putchar(c);
      col = 0;
    }
    c = getchar();
  }
}
