#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[])
{
  int i, j;
  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }
  return -1;
}

void check(char *s1, char *s2, int expected, int actual)
{
  printf("s1 = %s, s2 = %s, expected = %d, actual = %d\n", s1, s2, expected, actual); 
}

main()
{
  char s1[] = "hello world";
  char s2[] = "oe";
  int expected = 1;;
  check(s1, s2, expected, any(s1, s2));
}
