#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j)
{
  int c;

  if (i > j)
    return;
  else {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
    i++;
    j--;
    reverse(s, i, j);
  }
}

main()
{
  char s[] = "12345";
  reverse(s, 0, strlen(s) - 1);
  printf("%s\n", s);
}
