#include <stdio.h>

void expand(char s1[], char s2[])
{
  int i, j;
  char c;

  j = 0;
  for (i = 0; s1[i] != '\0'; i++) {
    /* check if s1[i] is  a letter or digit and there is a proceeding '-' (s1[i+1]) */
    /* check to see if s[i+2] is \0. This is for the case when s1 has a trailing dash (a-b-) */ 
    if ((s1[i] >= '0' && s1[i] <= '9' || s1[i] >= 'A' || s1[i] <= 'Z' || s1[i] >= 'a' && s1[i]) <= 'z'
      && (s1[i+1] == '-') 
      && (s1[i+2] != '\0')) {
       /* Using ASCII values loop from current letter to the next letter in s1 */
       for (c = s1[i]; c < s1[i+2]; c++) {
         /* store letter or digit in s2  */
         s2[j] = c;
         j++;
       }
       /* iterate i to skip the unnecessary '-'  */
       i++;
       /* store letter, digit and leading or trailing '-' */
     }  else {
       s2[j] = s1[i];
       j++;
     }
  }   
     s2[j] = '\0';
}

main()
{
  char s1[100] = "-a-zA-Z0-9-";
  char s2[100];
  expand(s1, s2);
  printf("s1 = %s s2 = %s\n", s1, s2);
}
