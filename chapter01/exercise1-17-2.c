#include <stdio.h>
#define MAX_LENGTH 80

/* print the longest input line */
main()
{
  int c, i;
  char buffer[MAX_LENGTH+1];
 
  c = getchar();
  while (c != EOF) {
    i= 0;
    while (c != EOF && c != '\n') {
      if (i < MAX_LENGTH)
        buffer[i] = c;
      if (i == MAX_LENGTH) {
        buffer[i] = '\0'; /* null terminate string */
        printf("%s", buffer); 
      }
      if (i >= MAX_LENGTH) {
        putchar(c);
      }
      i++;
      c = getchar();
    }
    if (c == '\n') {
      if (i > MAX_LENGTH+1)
        putchar(c);
      c = getchar();
    }
  }
  return 0;
}

