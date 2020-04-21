#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP  100    /* max size of operant or operator  */
#define NUMBER '0'    /* signat that a number was found */

int getop(char [], char [], int);
void push(double);
double pop(void);
void clear(void);
void mathfunc(char []);
int getline(char [], int);
int lp = 0;  /* line position */
char input[MAXOP];

/* reverse  Polish calculator */
main()
{
  int type, len;
  double op2, op3;
  char s[MAXOP];
  
  while ((getline(input, MAXOP)) > 0) {
    lp = 0;
    while ((type = getop(s, input, len)) != '\0') {
      switch (type) {
        case NUMBER:
          push(atof(s));
          break;
        case '+':
          push(pop() + pop());
          break;
        case '*':
          push(pop() * pop());
          break;
        case '-':
          op2 = pop();
          push(pop() - op2);
          break;
        case '/':
          op2 = pop();
          if (op2 != 0.0)
            push(pop() / op2);
          else
            printf("error: zero divisor\n");
          break;
        case '%':
          op2 = pop();
          if (op2 != 0.0) 
            push(fmod(pop(), op2));
          else
            printf("error: zero divisor\n");
          break;
        case '\n':
          printf("\t%.8g\n", pop());
          break;
        default:
          printf("error: unknown command %s\n", s);
          break;
        }
      }
  }
  return 0;
}

#define MAXVAL 100    /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

/* getop: get next character or numeric operand */
int getop(char s[], char line[], int lim)
{
  int i, c;

  while ((s[0] = c = line[lp++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  i = 0;
  if (!isdigit(c) && c != '.' && c != '-')
    return c;        /* not a number */
 
   if (c == '-')
     if (isdigit(c = line[lp++]) || c == '.')
       s[++i] = c;
     else {
       --lp;
       return '-';
       }
  
  if (isdigit(c))    /* collect integer part */
    while (isdigit(s[++i] = c = line[lp++]))
      ;
  if (c == '.')      /* collect fraction part */
    while (isdigit(s[++i] = c = line[lp++]))
      ;
  s[i] = '\0';
  --lp;
  return NUMBER;
}

int getline(char s[], int lim)
{
  
  int i, c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
