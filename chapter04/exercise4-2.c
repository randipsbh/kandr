#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* atof: conevert string s to double */

double atof(char s[])
{
  double val, power, exp;
  int i, j,  sign, signexp;

  for (i = 0; isspace(s[i]); i++)  /* skips white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
  }
  signexp = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  exp = 1.0;
  printf("%d\n", s[i]);
  for (j = 1; j <= s[i] - 48; j++) {
   printf("inside j for loop\n");
   exp *= 10;
  }
  
  if (signexp < 0)
    return sign * val / power / exp;
  else 
    return sign * val / power * exp;;
}

main()
{
  char s[] = "123.45e5";
  printf("%lf\n", atof(s));
}
