#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[])
{
  int i, j, k, ok;
  for (i = k = 0; s1[i] != '\0'; i++) {
    ok = 1;
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        ok = 0;
      }
    }
    if (ok) {
      s1[k - 1] = s1[i];
    }
  }
  s1[k] = '\0';
}

void check(char *s1, char *s2, char *expected, char *actual)
{
  printf("s1 = %s, s2 = %s, expected = %s, actual = %s\n", s1, s2, expected, actual); 
}

main()
{
  char s1[] = "hello world";
  char s2[] = "oe";
  char expected[] = "hll wrld";
  squeeze(s1, s2);
  check("hello world", s2, s1, expected);
}
