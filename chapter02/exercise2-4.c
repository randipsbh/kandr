#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[])
{
  int i, j, k, ok;
  for (i = k = 0; s1[i] != '\0'; i++) {
    printf("i = %d:\n", i);
    ok = 1;
    for (j = 0; s2[j] != '\0'; j++) {
      printf("  j = %d\n", j);
      if (s1[i] == s2[j]) {
        ok = 0;
      }
    }
    if (ok) {
      printf("ok = %d, k = %d, i = %d\n", ok, k, i);
      printf("  %c\n", s1[k++]);
      printf("  %c\n", s1[i]); 
      s1[k - 1] = s1[i];
      printf("end ok\n");
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
  printf("call squeeze\n");
  squeeze(s1, s2);
  printf("call check\n");
  check("hello world", s2, s1, expected);
}
