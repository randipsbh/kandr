#include <stdio.h>

#define MAXLINE 1000    /* maximum input lien size */

int max;                /* maximum length seen so far */
char line [MAXLINE];    /* current input line */
char longest[MAXLINE];  /* longest line saved here */

int getline(void);
void copy(void);

/* print longet input line; specialized version */
main()
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline()) > 0)
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0)   /* there was a line */
		printf("%s", longest);
	return 0;
}

/* getline: specialized version */
int getline(void)
{
	int c, i;
	extern char line[];
  
  i = 0;
  while (i < MAXLINE - 1) {
    c = getchar();
    if (c == EOF) {
      break;
    }
    if (c == '\n') {
      break;
    }
    line[i++] = c;
  }
	if (c == '\n') {
		line[i] = c;
		++i;
	}
  line[i] = '\0';
  return i;
}

void copy(void)
{
  int i;
  extern char line[], longest[];
  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
