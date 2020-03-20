#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char line[]); 

main()
{
  int len;
  char line[MAXLINE];
  while ((len = getline(line, MAXLINE)) > 0) {    
    reverse(line);
    print("%s", line);
  }
  return 0;
}

int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim-1 (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  return i;
}
/* reverse one line at a time */
void reverse(char s[])
{

  /* get length of input array */
  /* make a new char array, insert contents of orginal array into new one */ 

  int i, j, k, c;
  char sr[MAXLINE];
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  s[i+1] = '\0';

  k = 0;
  for (int j = i -1; j >=0; j--) {
    sr[j] = s[k];
    k++;
  }
  sr[k] = '\n';
  sr[k +1] = '\0';
  printf("%s", sr);
}
