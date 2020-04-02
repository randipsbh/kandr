#include <stdio.h>
#include <string.h>

void unescape(char s[], char t[])
{
  int i, j;
  i = j = 0;
  while (t[i] != '\0') {
    printf("in loop\n");
    switch (t[i]) {
      case '\\':
        switch (i++) {
          case 't':
            printf("case t");
            s[j] = '\t';
            break;
          case 'n':
            printf("case t");
            s[j] = '\n';
            break;
        }
        break;
      default:
        printf("default %c\n", t[i]);
        s[j] = t[i];
        break;
    }
    i++;
    j++;
  }
  s[j] = '\0';
}

void escape(char s[], char t[])
{
  /* using switch statments copy t to s */
  /* replace tab and newline in t to \t and \n in s */
  int i, j;
  i = j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
      case '\t':
        s[j++] = '\\';
        s[j] = 't';
        break;
      case '\n':
        s[j++] = '\\';
        s[j] = 'n';
        break;
      default:
        s[j] = t[i];
        break;
    }
    i++;
    j++;
  }
  s[j] = '\0';
}

void check(char *expected, char *actual)
{
  printf("%s\n", expected);
}

main()
{
  char s[50];
  char t[50] = "Hello\tWorld!\n";
  unescape(s, t);
  check(s, t);


}

